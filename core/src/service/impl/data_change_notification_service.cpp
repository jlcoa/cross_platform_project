//
//  data_change_notification_service.cpp
//  core
//
//  Created by Steve Chen on 3/4/16.
//
//

#include "data_change_notification_service.hpp"

namespace core {
    
    void DataChangeNotificationService::subscribe(const string &table, std::weak_ptr<IDataChangeListener> listener) {
        std::vector<std::weak_ptr<IDataChangeListener>> listeners = m_listenerMap[table];
        addBizObserver(listeners, listener);
        m_listenerMap[table] = listeners;
    }
    
    void DataChangeNotificationService::unsubscribe(const string &table, std::weak_ptr<IDataChangeListener> listener) {
        std::vector<std::weak_ptr<IDataChangeListener>> listeners = m_listenerMap[table];
        removeBizObserver(listeners, listener);
        m_listenerMap[table] = listeners;
    }
    
    
    void DataChangeNotificationService::dataChange(shared_ptr<DataChangeMap> changeMap) {
        
        auto self = std::enable_shared_from_this<DataChangeNotificationService>::shared_from_this();
        auto modelMap = changeMap->getModelMap();

        if (modelMap) {
            dispatchToUI([self, changeMap, modelMap]() {
                
                
                for (auto setIterator = modelMap->begin(); setIterator != modelMap->end(); setIterator++)
                {
                    string modelName = setIterator->first;
                    auto listenersIter = self->m_listenerMap.find(modelName);
                    
                    if (listenersIter != self->m_listenerMap.end()) {
                        
                        auto listeners = listenersIter->second;
                        
                        for (auto listener: listeners) {
                            auto ls = listener.lock();
                            if (ls) {
                                ls->onDataChanged(modelName, setIterator->second);
                            }
                        }
                    }
                }
                
            });
        }
        
    }
}