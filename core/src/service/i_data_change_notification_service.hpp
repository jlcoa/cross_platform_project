//
//  i_data_change_notification_service.hpp
//  core
//
//  Created by Steve Chen on 3/4/16.
//
//

#pragma once

#include "i_biz_service_factory.hpp"
#include "../dao/data_change_map.hpp"

namespace core {
    
    class IDataChangeListener {
        
    public:
        virtual void onDataChanged(const string& modelName, shared_ptr<ModelChangeTypeMap> changeMap) = 0;
        
    };
    
    class IDataChangeNotificationService:  public IBizService {
        
    public:
        
        virtual void subscribe(const string &table, std::weak_ptr<IDataChangeListener> listener) = 0;
        
        virtual void unsubscribe(const string &table, std::weak_ptr<IDataChangeListener> listener) = 0;
        
        virtual void dataChange(shared_ptr<DataChangeMap> changeMap) = 0;
        
        
        template <class T>
        void subscribe(std::weak_ptr<IDataChangeListener> listener) {
            subscribe(typeid(T).name(), listener);
        };
        
        template <class T>
        void unsubscribe(std::weak_ptr<IDataChangeListener> listener) {
            unsubscribe(typeid(T).name(), listener);
        };
    };
    
}

