//
//  object_fetcher.hpp
//  core
//
//  Created by Steve Chen on 2/14/16.
//
//

#pragma once

#include <functional>
#include <string>

#include "i_dao_factory.hpp"
#include "../core/logger.hpp"

#include "../core/task_dispatcher.hpp"

#include "../service/i_data_change_notification_service.hpp"

namespace core {
    
    const string kTagObjectFetcher = "kTagObjectFetcher";
    
    template<class ClassT>
    class ObjectFilter {
        
    public:
        
        ObjectFilter (
                      std::function<bool(const ClassT&)> filterFunc,
                      const std::map<std::string, sqlite::Value>& where = {},
                      const std::vector<std::string> &column = {}
                      )
        :
        m_filterFunc{filterFunc},
        m_where{where},
        m_column{column}
        {
            
        }
        
        bool satisfies(const ClassT& obj) const {
            return m_filterFunc(obj);
        }
        
        const std::vector<std::string>& getColumn() const {
            return m_column;
        }
        
        const std::map<std::string, sqlite::Value>& getWhere() const {
            return m_where;
        }
        
    private:
        
        std::function<bool(const ClassT&)> m_filterFunc;
        
        std::map<std::string, sqlite::Value> m_where;
        
        std::vector<std::string> m_column;
    };
    
    template<class ClassT>
    class ObjectSorter {
        
    public:
        ObjectSorter(
                     std::function<int(const ClassT&, const ClassT&)> compareFunc,
                     std::function<bool(const ClassT&, const ClassT&)> equalFunc,
                     const std::vector<std::string>& orderBy = {} )
        :
        m_compareFunc(compareFunc),
        m_equalFunc(equalFunc),
        m_orderBy(orderBy)
        {
        }
        
        int compare(const ClassT& obj1, const ClassT& obj2) const {
            return compareInternal(obj1, obj2);
        }
        
        bool isEqual(const ClassT& obj1, const ClassT& obj2) const {
            return m_equalFunc(obj1, obj2);
        }
        
        const std::vector<std::string>& getOrderby() const {
            return m_orderBy;
        }
        
    private:
        int compareInternal(const ClassT& obj1, const ClassT& obj2) const {
            return m_compareFunc(obj1, obj2);
        }
        
        std::function<int(const ClassT&, const ClassT&)> m_compareFunc;
        
        std::function<bool(const ClassT&, const ClassT&)> m_equalFunc;
        
        std::vector<std::string> m_orderBy;
    };
    
    template<class ClassT, class DAO>
    class ObjectFetcher;
    
    template<class ClassT, class DAO>
    class ObjectFetcherDelegate {
        
    public:
        
        virtual bool onPrehandleData(std::shared_ptr<ObjectFetcher<ClassT, DAO>> objectFetcher, shared_ptr<ClassT> mode) {return true;};
        
        virtual void onDataChanged(std::shared_ptr<ObjectFetcher<ClassT, DAO>> objectFetcher) = 0;
        
        virtual void onModelChanged(std::shared_ptr<ObjectFetcher<ClassT, DAO>> objectFetcher, shared_ptr<ClassT> model, shared_ptr<ClassT> originalModel, EModelChangeType changeType) {};
    };
    
    
    template<class ClassT, class DAO>
    class ObjectFetcher: public IDataChangeListener, public std::enable_shared_from_this<ObjectFetcher<ClassT, DAO>> {
        
    public:
        
        ObjectFetcher(std::shared_ptr<IDaoFactory> daoFactory,
                      std::shared_ptr<ObjectFilter<ClassT>> filter,
                      std::shared_ptr<ObjectSorter<ClassT>> sorter, size_t batchSize = 20):m_daoFactory{daoFactory},  m_dataFilter{filter}, m_dataSorter{sorter}, m_batchSize{batchSize} {
            
            m_bunderyIndex = 0;
            m_isFetching = false;
            m_prefetchAll = false;
            
        };
        
        size_t count() { return m_data.size(); };
        
        std::shared_ptr<ClassT> objectAt(size_t index, bool preload = false) {
            assert(index < m_data.size());
            
            if (preload && updateBunderyIndex(index)) {
                checkAndPerformPrefetch();
            }
            
            return m_data.at(index);
        };
        
        bool updateBunderyIndex(size_t index) {
            bool result = false;
            
            if (m_bunderyIndex < index) {
                result = true;
                m_bunderyIndex = index;
                
                LOG_DEBUG_F(kTagObjectFetcher, "updateBunderyIndex: ", KV(m_bunderyIndex));
            }
            
            return result;
        }
        
        bool reachBundery() {
            
            bool result = m_bunderyIndex >= count() - m_batchSize;
            
            return result;
        }
        
        void checkAndPerformPrefetch() {
            bool shouldPrefetch = m_hasMore && (m_prefetchAll || reachBundery());
            if (shouldPrefetch) {
                executeFetchInternal(m_batchSize);
            }
        }
        
        void initNotification(std::shared_ptr<IDataChangeNotificationService> notificationService) {
            notificationService->subscribe<ClassT>(sharedFromThis());
        }
        
        void performFetch(bool prefetchAll = false) {
            m_prefetchAll = prefetchAll;
            executeFetchInternal(m_batchSize);
        }
        
        void setDelegate(std::weak_ptr<ObjectFetcherDelegate<ClassT, DAO>> delegate) {
            m_delegate = delegate;
        }
        
        void onDataChanged(const string& modelName, shared_ptr<ModelChangeTypeMap> changeMap) {
            
            auto self = sharedFromThis();
            
            dispatchToBG([self, changeMap]() {
                
                shared_ptr<ModelChangeTypeMap> satisfiedMap = self->prehandleChangedDataMap(changeMap);
                if (satisfiedMap->size() > 0) {
                    dispatchToUI([self, satisfiedMap]() {
                        self->handleChangedDataMap(satisfiedMap);
                        self->notifyDataChange();
                    });
                }
                
            });
        }
        
    private:
        
        void notifyModelChanged(std::shared_ptr<ClassT> model, std::shared_ptr<ClassT> originalModel, EModelChangeType changeType) {
            auto delegate = m_delegate.lock();
            if (delegate) {
                delegate->onModelChanged(std::enable_shared_from_this<ObjectFetcher<ClassT, DAO>>::shared_from_this(), model, originalModel, changeType);
            }
        }
        
        void onObjectAdd(shared_ptr<ClassT> model) {
            
            auto i = m_data.begin();
            int pos = 0;
            
            //searching for a place to insert added object
            for(;i != m_data.end() && m_dataSorter->compare((*(model.get())), (*(i->get()))) > 0; i++, pos++ ) {
                
            }
            
            if(i == m_data.end()) {
                pos = (int)m_data.size();
                m_data.push_back(model);
            } else {
                m_data.insert(i , model);
            }
            
            notifyModelChanged(model, nullptr, EModelChangeType::Inserted);
        }
        
        void onObjectUpdate(shared_ptr<ClassT> model) {
            
            bool needResort = false;
            
            //searching for the object
            for (auto i = m_data.begin(); i != m_data.end() ; i++) {
                if (m_dataSorter->isEqual(**i, *model)) {
                    needResort = m_dataSorter->compare(*model, **i) != 0;
                    *i = model;
                    
                    break;
                }
            }
            
            
            if(needResort) {
                std::stable_sort(m_data.begin(), m_data.end(), [=](shared_ptr<ClassT> o1, shared_ptr<ClassT> o2){
                    return m_dataSorter->compare(*o1, *o2) < 0;
                });
            }
            
            notifyModelChanged(model, nullptr, EModelChangeType::Updated);
            
        }
        
        void onObjectDelete(shared_ptr<ClassT> model) {
            
            //searching for the object
            for (auto i = m_data.begin(); i != m_data.end() ; i++) {
                if (m_dataSorter->isEqual(**i, *model)) {
                    m_data.erase(i);
                    break;
                }
            }
            
            notifyModelChanged(model, nullptr, EModelChangeType::Deleted);
        }
        
        
        bool shouldBeInRange(shared_ptr<ClassT> model) {
            
            bool result = !m_hasMore;
            
            if (!result && count() > 0) {
                auto lastMode = --m_data.end();
                if (m_dataSorter->compare((*(model.get())), (*(lastMode->get()))) < 0) {
                    result = true;
                }
            }
            
            return result;
            
        }
        
        bool matchedInData(shared_ptr<ClassT> model) {
            
            bool found = false;
            for (auto i = m_data.begin(); i != m_data.end() ; i++) {
                if (m_dataSorter->isEqual(**i, *model)) {
                    found = true;
                    break;
                }
            }
            
            return found;
        }
        
        std::shared_ptr<std::pair<bool, EModelChangeType>> isSatisfied(shared_ptr<ClassT> model, EModelChangeType changeType) {
            
            bool satisfied = false;
            
            switch (changeType) {
                case EModelChangeType::Inserted:
                    satisfied = m_dataFilter->satisfies(*model) && shouldBeInRange(model);
                    break;
                    
                case EModelChangeType::Updated:
                    if(m_dataFilter->satisfies(*model)) {
                        satisfied = matchedInData(model);
                        if (!satisfied) {
                            satisfied = shouldBeInRange(model);
                            changeType = EModelChangeType::Inserted;
                        }
                    }
                    else {
                        if (matchedInData(model)) {
                            satisfied = true;
                            changeType = EModelChangeType::Deleted;
                        };
                    }
                    
                    break;
                    
                case EModelChangeType::Deleted:
                    satisfied = matchedInData(model);
                    break;
                    
                default:
                    break;
            }
            
            return std::make_shared<std::pair<bool, EModelChangeType>>(satisfied, changeType);
        }
        
        void addChangeTypeData(shared_ptr<ModelChangeTypeMap> changeTypeMap, shared_ptr<ClassT> model, EModelChangeType type) {
            
            auto iter = changeTypeMap->find(type);
            
            std::shared_ptr<ModelVector> modelVector = nullptr;
            if (iter == changeTypeMap->end()) {
                modelVector = std::make_shared<ModelVector>();
                changeTypeMap->insert({type, modelVector});
            }
            else {
                modelVector = iter->second;
            }
            modelVector->push_back(model);
        }

        
        shared_ptr<ModelChangeTypeMap> prehandleChangedDataMap(shared_ptr<ModelChangeTypeMap> changeMap) {
            
            shared_ptr<ModelChangeTypeMap> satisfiedMap = make_shared<ModelChangeTypeMap>();
            
            for (auto changeTypeMapIterator = changeMap->begin(); changeTypeMapIterator != changeMap->end(); changeTypeMapIterator ++) {
                
                auto modelVector = (changeTypeMapIterator->second);
                if(modelVector&& !modelVector->empty()) {
                    
                    for(auto changeIter = modelVector->begin() ; changeIter != modelVector->end() ; ++changeIter) {
                        
                        auto model = std::dynamic_pointer_cast<ClassT>(*changeIter);
                        
                        auto result = isSatisfied(model, changeTypeMapIterator->first);
                        if (result->first) {
                            addChangeTypeData(satisfiedMap, model, result->second);
                            prehandleData( model);
                        }
                        
                    }
                }
            }
            
            return satisfiedMap;
        }
        
        void handleChangedDataMap(shared_ptr<ModelChangeTypeMap> satisfiedMap) {
            
            for (auto changeTypeMapIterator = satisfiedMap->begin(); changeTypeMapIterator != satisfiedMap->end(); changeTypeMapIterator ++) {
                auto modelVector = (changeTypeMapIterator->second);
                if(modelVector&& !modelVector->empty()) {
                    for(auto changeIter = modelVector->begin() ; changeIter != modelVector->end() ; ++changeIter) {
                        
                        switch (changeTypeMapIterator->first) {
                            case EModelChangeType::Inserted:
                                onObjectAdd(std::dynamic_pointer_cast<ClassT>(*changeIter));
                                break;
                                
                            case EModelChangeType::Updated:
                                onObjectUpdate(std::dynamic_pointer_cast<ClassT>(*changeIter));
                                break;
                                
                            case EModelChangeType::Deleted:
                                onObjectDelete(std::dynamic_pointer_cast<ClassT>(*changeIter));
                                break;
                                
                            default:
                                break;
                        }
                    }
                }
            }
        }
        
        auto sharedFromThis() {
            return std::enable_shared_from_this<ObjectFetcher<ClassT, DAO>>::shared_from_this();
        }
        
        void prehandleData(std::shared_ptr<ClassT> model) {
            auto delegate = m_delegate.lock();
            if (delegate) {
//                for (auto model: *models) {
                    delegate->onPrehandleData(std::enable_shared_from_this<ObjectFetcher<ClassT, DAO>>::shared_from_this(), model);
//                }
            }
        }
        
        void prehandleData(std::shared_ptr<std::vector<std::shared_ptr<ClassT>>> models) {
            auto delegate = m_delegate.lock();
            if (delegate) {
                for (auto model: *models) {
                    delegate->onPrehandleData(std::enable_shared_from_this<ObjectFetcher<ClassT, DAO>>::shared_from_this(), model);
                }
            }
        }
        
        void executeFetchInternal (size_t batchSize) {
            if (m_isFetching) {
                LOG_DEBUG_F(kTagObjectFetcher, "already in fetching");
            }
            else {
                m_isFetching = true;
                
                LOG_DEBUG_F(kTagObjectFetcher, "start fetching");
                
                auto self = sharedFromThis();
                
                dispatchToBG([self, batchSize]() {
                    auto result = self->fetchData(self->count(), batchSize);
                    self->prehandleData(result);
                    
                    dispatchToUI([self, result]() {
                        self->m_isFetching = false;
                        self->m_hasMore = result->size() >= self->m_batchSize;
                        
                        LOG_DEBUG_F(kTagObjectFetcher, "bundery index: ", KV(self->m_bunderyIndex));
                        
                        if (result->size() > 0) {
                            
                            for (auto exIter = result->begin(); exIter != result->end(); ++exIter) {
                                self->notifyModelChanged(*exIter, nullptr, EModelChangeType::Inserted);
                            }
                            
                            std::move(result->begin(), result->end(), std::inserter(self->m_data, self->m_data.end()));
                            
                            LOG_DEBUG_F(kTagObjectFetcher, "end fetching");
                            
                            self->notifyDataChange();
                            
                            self->checkAndPerformPrefetch();
                        }
                        else {
                            LOG_DEBUG_F(kTagObjectFetcher, "all end fetching");
                        }
                    });
                    
                });
            }
        }
        
        std::shared_ptr<std::vector<std::shared_ptr<ClassT>>> fetchData(size_t offset, size_t count) {
            
            LOG_DEBUG_F(kTagObjectFetcher, "fetchData: ", KV(offset), KV(count));
            auto dao = m_daoFactory->getDao<DAO>();
            return dao->query(m_dataFilter->getColumn(), m_dataFilter->getWhere(), m_dataSorter->getOrderby(), count, offset);
            
        }
        
        void notifyDataChange() {
            
            auto delegate = m_delegate.lock();
            
            if (delegate) {
                delegate->onDataChanged(std::enable_shared_from_this<ObjectFetcher<ClassT, DAO>>::shared_from_this());
            }
            
        }
        
        std::shared_ptr<IDaoFactory> m_daoFactory;
        
//        std::shared_ptr<IDataChangeNotificationService> m_notificationService;
        
        std::shared_ptr<ObjectFilter<ClassT>> m_dataFilter;
        
        std::shared_ptr<ObjectSorter<ClassT>> m_dataSorter;
        
        size_t m_batchSize;
        
        std::vector<std::shared_ptr<ClassT>> m_data;
        
        bool m_isFetching;
        bool m_prefetchAll;
        bool m_hasMore;
        
        size_t m_bunderyIndex;
        
        std::weak_ptr<ObjectFetcherDelegate<ClassT, DAO>> m_delegate;
    };
    
}
