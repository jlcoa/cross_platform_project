//
//  unified_factory.hpp
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#pragma once
#include "stl.hpp"
#include "../service/i_biz_service_factory.hpp"
#include "../dao/i_dao_factory.hpp"
#include "../interface/i_ui_controller_factory.hpp"

namespace core {
    
    class IUnifiedFactory {
    public:
        virtual std::shared_ptr<IBizServiceFactory> getBizServiceFactory() = 0;
        virtual std::shared_ptr<IDaoFactory> getDaoFactory() = 0;
        virtual std::shared_ptr<core_gen::IUiControllerFactory> getUiControllerFactory() = 0;
        
    };
    
    class UnifiedFactory: public IUnifiedFactory, public std::enable_shared_from_this<UnifiedFactory> {
    
    public:
        std::shared_ptr<IBizServiceFactory> getBizServiceFactory() override;
        std::shared_ptr<IDaoFactory> getDaoFactory() override;
        std::shared_ptr<core_gen::IUiControllerFactory> getUiControllerFactory() override;
        
    private:
        std::shared_ptr<IBizServiceFactory> m_bizServiceFactory;
        std::shared_ptr<IDaoFactory> m_daoFactory;
        std::shared_ptr<core_gen::IUiControllerFactory> m_uiControllerFactory;
    };
    
}

