//
//  i_account_service.hpp
//  core
//
//  Created by Steve Chen on 2/13/16.
//
//

#pragma once

#include "i_biz_service_factory.hpp"
#include "../interface/r_account.hpp"

#include "../interface/e_login_status.hpp"
#include "../interface/e_account_status.hpp"
#include "../interface/r_account_response.hpp"
#include "../interface/r_upload_token.hpp"
#include "../interface/i_action_callback.hpp"
#include "../interface/r_avatar_info.hpp"

namespace core {
    
    typedef std::function<void(core_gen::ELoginStatus status)> LoginCallback;
    
    class IAccountServiceObserver {
        
    public:
        
        virtual void onAccountStatusChanged(core_gen::EAccountStatus accountStatus) = 0;
        
    };
    
    class IAccountService: public IBizService {
        
    public:
        
        virtual void login(shared_ptr<core_gen::RAccount> account, LoginCallback cb) = 0;
        
        virtual void signup(shared_ptr<core_gen::RAccount> account, std::shared_ptr<CallbackResult<core_gen::RActionResult>>) = 0;
        
        virtual void signout(std::shared_ptr<CallbackResult<core_gen::RActionResult>>) = 0;
        
        virtual void addAccountObserver(std::weak_ptr<IAccountServiceObserver> observer) = 0;
        
        virtual void removeAccountObserver(std::weak_ptr<IAccountServiceObserver> observer) = 0;
        
        virtual void start() = 0;
        
        virtual std::shared_ptr<core_gen::RAccountResponse> getAccountInfo() = 0;
        
        virtual void requestUploadToken(std::shared_ptr<CallbackResult<core_gen::RUploadToken>>) = 0;
        
        virtual void updateAvatar(std::shared_ptr<core_gen::RAvatarInfo> avatar, std::shared_ptr<CallbackResult<core_gen::RAvatarInfo>>) = 0;
    };
    
}