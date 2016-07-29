//
//  data_change_notification_service.hpp
//  core
//
//  Created by Steve Chen on 3/4/16.
//
//

#pragma once

#include "../i_data_change_notification_service.hpp"
#include "../i_biz_service_factory.hpp"

namespace core {
    
    class DataChangeNotificationService: public IDataChangeNotificationService, public AbstractBizService, public std::enable_shared_from_this<DataChangeNotificationService> {
        
    public:
        
        DataChangeNotificationService(const std::weak_ptr<IUnifiedFactory> unifiedFactory):AbstractBizService {unifiedFactory} {};
        
        void subscribe(const string &table, std::weak_ptr<IDataChangeListener> listener) override;
        
        void unsubscribe(const string &table, std::weak_ptr<IDataChangeListener> listener) override;
        
        void dataChange(shared_ptr<DataChangeMap> changeMap) override;
        
        
    private:
        
        std::unordered_map<string, std::vector<std::weak_ptr<IDataChangeListener>>> m_listenerMap;
        
    };
}


