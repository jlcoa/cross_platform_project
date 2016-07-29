//
//  i_login_ui_controller.hpp
//  core
//
//  Created by Steve Chen on 2/16/16.
//
//

#pragma once


#include "../../interface/i_login_ui_controller.hpp"
#include "../../interface/i_view_model_delegate.hpp"
#include "../../interface/i_login_view_model.hpp"
#include "../../interface/r_account.hpp"

#include "../../service/i_account_service.hpp"

#include "../i_ui_controller.hpp"

namespace core {
    
    class LoginViewModel: public core_gen::ILoginViewModel, public AbstractViewModel {
        
    public:
        
        std::string getUserName() override {return m_userName;};
        
        void setUserName(const std::string & userName) override { m_userName = userName; };
        
        std::string getPassword() override {return m_passowrd;};
        
        void setPassword(const std::string & password) override {m_passowrd = password;};
        
        void setStatus(core_gen::ELoginStatus status) override { m_status = status; };
        
        core_gen::ELoginStatus getStatus() override { return m_status; };
        
        bool isLoading() override {return AbstractViewModel::isLoading();};
        
        void setLoading(bool loading) override {AbstractViewModel::setLoading(loading);};
        
    private:
        
        std::string m_userName;
        std::string m_passowrd;
        
        core_gen::ELoginStatus m_status;
    };
    
    class LoginUiController: public core_gen::ILoginUiController, public AbstractUiController<core_gen::ILoginViewModel, core_gen::IViewModelDelegate>, public std::enable_shared_from_this<LoginUiController> {
        
    public:
         LoginUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate);
        
        void login() override;
        
        std::shared_ptr<core_gen::ILoginViewModel> getViewModel() override {
            return AbstractUiController::getViewModel();
        };
        
    private:
        
        std::shared_ptr<IAccountService> m_accountService;
    };
    
}
