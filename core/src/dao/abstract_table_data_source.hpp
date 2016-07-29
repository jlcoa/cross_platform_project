//
//  abstract_table_data_source.hpp
//  core
//
//  Created by Steve Chen on 2/26/16.
//
//

#pragma once

#include "object_fetcher.hpp"
#include "stl.hpp"
#include <unordered_map>
#include <unordered_set>

namespace core {
    
    template<class Key, class T, class DAO>
    class AbstractTableDataSource;
    
    template<class Key, class T, class DAO>
    class ITableDataSourceDelegate {
        
    public:
        
        bool onPrehandleData(std::shared_ptr<AbstractTableDataSource<Key, T, DAO>> dataSourc, std::shared_ptr<T> data) {
            return true;
        };
        
        virtual void onDataChanged(std::shared_ptr<AbstractTableDataSource<Key, T, DAO>> dataSource) = 0;
    };
    
    template<class Key, class T, class DAO>
    class AbstractTableDataSource: public ObjectFetcherDelegate<T, DAO>, public std::enable_shared_from_this<AbstractTableDataSource<Key, T, DAO>> {
        
    public:
        
        AbstractTableDataSource(std::shared_ptr<ObjectFetcher<T, DAO>> fetcher, std::weak_ptr<ITableDataSourceDelegate<Key, T, DAO>> delegate): m_fetcher(fetcher), m_delegate(delegate) {
            
        };
        
        void loadData(bool preloadAll = false) {
            
            m_fetcher->setDelegate(std::enable_shared_from_this<AbstractTableDataSource<Key, T, DAO>>::shared_from_this());
            m_fetcher->performFetch(preloadAll);
            
        };
        
        std::shared_ptr<T> objectAt(int32_t section, int32_t row) {
            
            int index = 0;
            for(int i = 0 ; i < section ; i++) {
                index += m_dataMap[m_keyVector[i]].size();
            }
            
            index += row;
            
            return m_fetcher->objectAt(index);
        };
        
        int32_t numberOfSections() {
            return (int32_t) m_keyVector.size();
        };
        
        int32_t numberOfRowsInSection(int32_t section) {
            
            int32_t count = 0;
            
            if (section < (int32_t)m_keyVector.size()) {
                auto targetIter = m_dataMap.find(m_keyVector.at(section));
                if (targetIter != m_dataMap.end()) {
                    count = (int32_t) targetIter->second.size();
                }
            }
            
            return count;
        };
        
        void onDataChanged(std::shared_ptr<ObjectFetcher<T, DAO>> objectFetcher) override {
            auto delegate = m_delegate.lock();
            if (delegate) {
                delegate->onDataChanged(std::enable_shared_from_this<AbstractTableDataSource<Key, T, DAO>>::shared_from_this());
            }
        };
        
        void onModelChanged(std::shared_ptr<ObjectFetcher<T, DAO>> objectFetcher, shared_ptr<T> model, shared_ptr<T> originalModel, EModelChangeType changeType) override {
            handleData(model);
        }
        
        bool onPrehandleData(std::shared_ptr<ObjectFetcher<T, DAO>> objectFetcher, shared_ptr<T> mode) override {
            
            return true;
        }
        
    protected:
        
        virtual Key key4Model(std::shared_ptr<T> model) = 0;
        
        virtual void handleData(shared_ptr<T> mode) {
            
            auto key = key4Model(mode);
            addModel2Section(key, mode);
        };
        
    private:
        
        virtual void handleFetchedData(shared_ptr<T> model, shared_ptr<T> originalModel, EModelChangeType changeType) {
            
            auto key = key4Model(model);
            
            if (changeType == EModelChangeType::Deleted) {
                removeModelFromSection(key, model);
            }
            else if (changeType == EModelChangeType::Inserted) {
                addModel2Section(key, model);
            }
            else if (changeType == EModelChangeType::Updated) {
                updateModel2Section(key, model);
            }
            else if(changeType == EModelChangeType::Moved) {
                removeModelFromSection(key, originalModel);
                addModel2Section(key, model);
            }
            
        };
        
        void removeModelFromSection(Key key, shared_ptr<T> model) {
            
            auto iter = m_dataMap.find(key);
            auto id = *(model->id);
            
            if(iter != m_dataMap.end()) {
                iter->second.erase(id);
                //If there isn't any message for a particular section, remove it from the section vector.
                if (iter->second.size() == 0) {
                    m_keyVector.erase(std::remove(m_keyVector.begin(), m_keyVector.end(), key), m_keyVector.end());
                    m_dataMap.erase(iter);
                }
            }
            else {
                //section name from the new model changed, should find its original section and remove it.
                bool needToRomoveMapKey = false;
                Key origKey;
                
                for (auto iter = m_dataMap.begin(); iter != m_dataMap.end(); ++iter) {
                    
                    auto vecIter = std::find(iter->second.begin() , iter->second.end(), id);
                    
                    if(vecIter != iter->second.end()) {
                        
                        if (key != iter->first) {
                            
                            iter->second.erase(id);
                            
                            if (iter->second.size() == 0) {
                                m_keyVector.erase(std::remove(m_keyVector.begin(), m_keyVector.end(), iter->first), m_keyVector.end());
                                needToRomoveMapKey = true;
                                origKey = iter->first;
                            }
                        }
                        
                        break;
                    }
                }
                
                if (needToRomoveMapKey) {
                    m_dataMap.erase(origKey);
                }
            }
        }
        
        void addModel2Section(Key key, shared_ptr<T> model) {
            
            auto iter = m_dataMap.find(key);
            if(iter != m_dataMap.end()) {
                iter->second.insert(*(model->id));
            } else {
                std::unordered_set<std::string> idSet;
                idSet.insert(*(model->id));
                m_dataMap.insert(std::make_pair(key, idSet));
                m_keyVector.push_back(key);
            }
        }
        
        void updateModel2Section(Key key, shared_ptr<T> model) {
            
            auto id = *(model->id);
            
            //Firstly, check if the model's original section equals to the updated one.
            if (m_keyVector.size() == 0) {
                addModel2Section(key, model);
            }
            else if (m_keyVector.size() == 1 && m_keyVector[0] == key) {
                //There is ONLY one section, do nothing.
            }
            else
            {
                bool needToRomoveMapKey = false;
                Key origKey;
                
                for (auto iter = m_dataMap.begin(); iter != m_dataMap.end(); ++iter) {
                    
                    auto vecIter = std::find(iter->second.begin() , iter->second.end(), id);
                    
                    if(vecIter != iter->second.end()) {
                        
                        if (key != iter->first) {
                            //If the section key changed, need to remove it from the original one to insert it to another one.
                            
                            iter->second.erase(id);
                            
                            if (iter->second.size() == 0) {
                                m_keyVector.erase(std::remove(m_keyVector.begin(), m_keyVector.end(), iter->first), m_keyVector.end());
                                needToRomoveMapKey = true;
                                origKey = iter->first;
                            }
                            
                            addModel2Section(key, model);
                        }
                        
                        break;
                    }
                }
                
                if (needToRomoveMapKey) {
                    m_dataMap.erase(origKey);
                }
                
            }
        }
        
        
        std::shared_ptr<ObjectFetcher<T, DAO>> m_fetcher;
        
        std::weak_ptr<ITableDataSourceDelegate<Key, T, DAO>> m_delegate;
        
        std::unordered_map<Key, std::unordered_set<std::string>> m_dataMap;
        
        std::vector<Key> m_keyVector;
    };
    
}