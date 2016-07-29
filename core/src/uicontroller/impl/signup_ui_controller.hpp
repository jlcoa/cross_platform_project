//
//  signup_ui_controller.hpp
//  core
//
//  Created by Steve Chen on 3/7/16.
//
//

#pragma once

#include "../../interface/i_signup_ui_controller.hpp"

#include "../../interface/i_view_model_delegate.hpp"
#include "../../interface/r_account.hpp"

#include "../../service/i_account_service.hpp"

#include "../i_ui_controller.hpp"

namespace core {
    
    class SignUpUiController: public core_gen::ISignupUiController, public AbstractUiController<AbstractViewModel, core_gen::IViewModelDelegate>, public std::enable_shared_from_this<SignUpUiController> {
        
    public:
        SignUpUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate);
        
        void signup(const std::string & userName, const std::string & password, const std::string & firstName, const std::string & lastName, const std::shared_ptr<core_gen::IActionCallback> & callback) override;
        
    private:
        
        std::shared_ptr<IAccountService> m_accountService;
        
    };
    
}