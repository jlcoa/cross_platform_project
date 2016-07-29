//
//  biz_service_factory.cpp
//  core
//
//  Created by Steve Chen on 2/13/16.
//
//

#include "biz_service_factory.hpp"

#include "../../service/impl/account_service.hpp"
#include "../../service/impl/contact_service.hpp"
#include "../../service/impl/data_change_notification_service.hpp"

namespace core {
    
    std::shared_ptr<IBizServiceFactory> BizServiceFactory::createBizServiceFactory(std::shared_ptr<IUnifiedFactory> unifiedFactory) {
        auto serviceFactory = std::make_shared<BizServiceFactory>(unifiedFactory);
        
        serviceFactory->registerService<IAccountService, AccountService>();
        serviceFactory->registerService<IContactService, ContactService>();
        serviceFactory->registerService<IDataChangeNotificationService, DataChangeNotificationService>();
        return serviceFactory;
    }
    
    std::shared_ptr<IBizService> BizServiceFactory::getService(const std::string& key) {
        auto it = m_serviceMap.find(key);
        if (it != m_serviceMap.end()) {
            return it->second;
        }
        
        return nullptr;
    }
    
}
