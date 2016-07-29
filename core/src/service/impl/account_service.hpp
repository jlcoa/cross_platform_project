//
//  account_service.hpp
//  core
//
//  Created by Steve Chen on 2/13/16.
//
//

#pragma once

#include "../i_account_service.hpp"
#include "../i_biz_service_factory.hpp"

namespace core {
    
    class AccountService: public IAccountService, public AbstractBizService, public std::enable_shared_from_this<AccountService> {
        
    public:
        
        AccountService(std::weak_ptr<IUnifiedFactory> unifiedFactory): AbstractBizService(unifiedFactory), m_accountStatus(core_gen::EAccountStatus::NOT_LOGGED_IN) {};
        
        void login(shared_ptr<core_gen::RAccount> account, LoginCallback cb) override;
        
        void signup(shared_ptr<core_gen::RAccount> account, std::shared_ptr<CallbackResult<core_gen::RActionResult>>) override;
        
        void signout(std::shared_ptr<CallbackResult<core_gen::RActionResult>>) override;
        
        void addAccountObserver(std::weak_ptr<IAccountServiceObserver> observer) override {
            addBizObserver(m_accountObservers, observer);
        };
        
        void removeAccountObserver(std::weak_ptr<IAccountServiceObserver> observer) override {
            removeBizObserver(m_accountObservers, observer);
        };
        
        void start() override;
        
        std::shared_ptr<core_gen::RAccountResponse> getAccountInfo() override {return m_accountInfo;};
        
        void requestUploadToken(std::shared_ptr<CallbackResult<core_gen::RUploadToken>>) override;
        
        void updateAvatar(std::shared_ptr<core_gen::RAvatarInfo> avatar, std::shared_ptr<CallbackResult<core_gen::RAvatarInfo>>) override;
        
    private:
        
        std::vector<std::weak_ptr<IAccountServiceObserver>> m_accountObservers;
        
        core_gen::EAccountStatus m_accountStatus;
        
        std::shared_ptr<core_gen::RAccountResponse> m_accountInfo;
        
    private:
        
        void updateAvatar2Server(std::shared_ptr<core_gen::RAvatarInfo> avatar, std::shared_ptr<CallbackResult<core_gen::RAvatarInfo>>, const std::string &domain);
        
        void notifyAccountStatusChanged();
        
        void handleLoggedIn();
        
        void initData();
        
    };
    
}
