//
//  i_login_ui_controller.cpp
//  core
//
//  Created by Steve Chen on 2/16/16.
//
//

#include "login_ui_controller.hpp"
#include "../../app/unified_factory.hpp"

namespace core {
    
    LoginUiController::LoginUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate):AbstractUiController(unifiedFactory, delegate) {
        
        m_viewModel = std::make_shared<LoginViewModel>();
        m_accountService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IAccountService>();
        
    };
    
    void LoginUiController::login() {
        
        auto account = core_gen::RAccount();
        account.username = m_viewModel->getUserName();
        account.password = m_viewModel->getPassword();
        account.grant_type = core_gen::RAccount::GRAND_TYPE_PASSWORD;
        
        m_accountService->login(std::make_shared<core_gen::RAccount>(std::move(account)), [=](core_gen::ELoginStatus status){
            
            m_viewModel->setStatus(status);
            m_delegate->onDataChanged();
            
        });
   
    }
    
}