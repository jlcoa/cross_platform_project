//
//  i_biz_service_factory.cpp
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#include "i_biz_service_factory.hpp"
#include "../app/unified_factory.hpp"
#include "i_data_change_notification_service.hpp"

namespace core {

    void AbstractBizService::notifyDataChange(std::shared_ptr<DataChangeMap> changeMap) {
        
        auto unifiedFactory = m_unifiedFactory.lock();
        
        dispatchToUI([unifiedFactory, changeMap]() {
        
            auto notificationService = unifiedFactory->getBizServiceFactory()->getService<IDataChangeNotificationService>();
            
            notificationService->dataChange(changeMap);
            
        });
        
    };
    
}