//
//  unified_factory.cpp
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#include "unified_factory.hpp"
#include "../service/impl/biz_service_factory.hpp"
#include "../dao/impl/dao_factory.hpp"
#include "../uicontroller/ui_controller_factory.hpp"

namespace core {
    
    std::shared_ptr<IBizServiceFactory> UnifiedFactory::getBizServiceFactory() {
        if (nullptr == m_bizServiceFactory) {
            m_bizServiceFactory = BizServiceFactory::createBizServiceFactory(shared_from_this());
        }
        return m_bizServiceFactory;
    }
    
    std::shared_ptr<IDaoFactory> UnifiedFactory::getDaoFactory() {
        if (nullptr == m_daoFactory) {
            m_daoFactory = std::make_shared<DaoFactory>(shared_from_this());
        }
        return m_daoFactory;
    }
    
    std::shared_ptr<core_gen::IUiControllerFactory> UnifiedFactory::getUiControllerFactory() {
        if (nullptr == m_uiControllerFactory) {
            m_uiControllerFactory = std::make_shared<UiControllerFactory>(shared_from_this());
        }
        return m_uiControllerFactory;
    }
    
}