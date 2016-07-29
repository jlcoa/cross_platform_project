//
//  xplatform_application.cpp
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#include "xplatform_application.hpp"
#include "unified_factory.hpp"

#include "../core/pal.hpp"
#include "data_provider.hpp"

shared_ptr<core_gen::IXplatformApplication> core::XplatformApplication::gApplication = std::make_shared<core::XplatformApplication>();

shared_ptr<core_gen::IXplatformApplication> core_gen::IXplatformApplication::sharedApplication() {
    return core::XplatformApplication::gApplication;
};

namespace core {
    
    void XplatformApplication::initApp(const std::shared_ptr<core_gen::IPalBundle> &palBundle) {
        setPal(palBundle);
        m_unifiedFactory = std::make_shared<core::UnifiedFactory>();
        
        m_dataProvider = std::make_shared<DataProvider>(m_unifiedFactory);
    }
    
    std::shared_ptr<IUnifiedFactory> XplatformApplication::getUnifiedFactory() {
        return m_unifiedFactory;
    }
    
    std::shared_ptr<core_gen::IUiControllerFactory> XplatformApplication::getUiControllerFactory() {
        return m_unifiedFactory->getUiControllerFactory();
    }
    
    std::shared_ptr<core_gen::IDataProvider> XplatformApplication::getDataProvider() {
        return m_dataProvider;
    }
    
}



