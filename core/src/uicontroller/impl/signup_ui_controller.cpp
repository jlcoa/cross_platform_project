//
//  signup_ui_controller.cpp
//  core
//
//  Created by Steve Chen on 3/7/16.
//
//

#include "signup_ui_controller.hpp"
#include "../../app/unified_factory.hpp"

namespace core {
    
    SignUpUiController::SignUpUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate):AbstractUiController(unifiedFactory, delegate) {
        
        m_viewModel = std::make_shared<AbstractViewModel>();
        m_accountService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IAccountService>();
        
    };
    
    void SignUpUiController::signup(const std::string & userName, const std::string & password, const std::string & firstName, const std::string & lastName,  const std::shared_ptr<core_gen::IActionCallback> & callback) {
        
        auto tcallback = std::make_shared<CallbackResult<core_gen::RActionResult>>();
        tcallback->callback = [=](std::shared_ptr<core_gen::RActionResult> data) {
//            callback->onGroupUpdated(*data, tcallback->result);
            
            callback->onResponse(*data);
        };
        
//        m_contactService->createGroup(contacts, tcallback);
        
        auto account = std::make_shared<core_gen::RAccount>();
        account->username = userName;
        account->password = password;
        account->firstName = firstName;
        account->lastName = lastName;
        
        m_accountService->signup(account, tcallback);
        
    }
    
}