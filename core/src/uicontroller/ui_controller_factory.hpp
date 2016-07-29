//
//  i_ui_controller_factory.hpp
//  core
//
//  Created by Steve Chen on 2/16/16.
//
//

#pragma once

#include "../interface/i_ui_controller_factory.hpp"

namespace core {
    
    class IUnifiedFactory;
    
    class UiControllerFactory: public core_gen::IUiControllerFactory, public std::enable_shared_from_this<UiControllerFactory> {
      
    public:
        
        UiControllerFactory(std::weak_ptr<IUnifiedFactory> unifiedFactory): m_unifedFactory{unifiedFactory} {};
        
        std::shared_ptr<core_gen::ILifecycleUiController> createLifecycleUiController(const std::shared_ptr<core_gen::ILifecyleViewModelDelegate> & delegate) override;
        
        std::shared_ptr<core_gen::ILoginUiController> createLoginUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) override;
        
        std::shared_ptr<core_gen::ISignupUiController> createSignUpUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) override;
        
        std::shared_ptr<core_gen::IContactUiController> createContactUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) override;
        
        std::shared_ptr<core_gen::IGroupUiController> createGroupUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) override;
        
        std::shared_ptr<core_gen::IGroupCreateUiController> createGroupCreateUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) override;
        
        std::shared_ptr<core_gen::IGroupUpdateUiController> createGroupUpdateUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) override;
        
        std::shared_ptr<core_gen::IGroupMemberUiController> createGroupMemberUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) override;
        
        std::shared_ptr<core_gen::IGroupDetailUiController> createGroupDetailUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) override;
        
        std::shared_ptr<core_gen::IProfileUiController> createProfileUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) override;
      
    private:
        std::weak_ptr<IUnifiedFactory> m_unifedFactory;
        
        template<class Controller, class Delegate>
        std::shared_ptr<Controller> createUiController(const std::shared_ptr<Delegate> &delegate) {
            
            auto uiController = std::make_shared<Controller>(m_unifedFactory, delegate);
            
            uiController->init();
            
            return uiController;

        }
    };
    
}