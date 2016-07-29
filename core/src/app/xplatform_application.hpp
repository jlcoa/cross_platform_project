//
//  xplatform_application.hpp
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#pragma once

#include "../interface/i_xplatform_application.hpp"
#include "stl.hpp"
#include "../interface/i_pal_bundle.hpp"
#include "../interface/i_data_provider.hpp"

namespace core {
    
    class IUnifiedFactory;
    
    class IUiControllerFactory;
    
    class IDataProvider;
    
    class XplatformApplication: public core_gen::IXplatformApplication {
        
    public:
        static shared_ptr<core_gen::IXplatformApplication> gApplication;
        
        void initApp(const std::shared_ptr<core_gen::IPalBundle> & palBundle) override;
        
        std::shared_ptr<IUnifiedFactory> getUnifiedFactory();
        
        std::shared_ptr<core_gen::IUiControllerFactory> getUiControllerFactory() override;
        
        std::shared_ptr<core_gen::IDataProvider> getDataProvider() override;
        
    private:
        shared_ptr<IUnifiedFactory> m_unifiedFactory;
        shared_ptr<core_gen::IDataProvider> m_dataProvider;
    };
    
    
    
}
