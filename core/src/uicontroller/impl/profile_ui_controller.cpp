//
//  profile_ui_controller.cpp
//  core
//
//  Created by Steve Chen on 3/21/16.
//
//

#include "profile_ui_controller.hpp"
#include "../../interface/i_request_upload_token_callback.hpp"

#include "../../app/unified_factory.hpp"

namespace core {
    
    ProfileUiController::ProfileUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate):AbstractUiController(unifiedFactory, delegate) {
        
        m_viewModel = std::make_shared<ProfileViewModel>();
        
        auto accountService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IAccountService>();
        m_viewModel->setAccount(accountService->getAccountInfo()->user);
        
    }
    
    void ProfileUiController::updateAvatar(const core_gen::RAvatarInfo & avatarInfo, const std::shared_ptr<core_gen::IActionCallback> & callback) {
        
        auto tcallback = std::make_shared<CallbackResult<core_gen::RAvatarInfo>>();
        tcallback->callback = [callback, tcallback](std::shared_ptr<core_gen::RAvatarInfo> data) {
//            callback->onTokenGet(token, *tcallback->result);
            callback->onResponse(*tcallback->result);
        };
        
        auto accountService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IAccountService>();
        accountService->updateAvatar(std::make_shared<core_gen::RAvatarInfo>(avatarInfo), tcallback);
        
    }
    
    void ProfileUiController::requestUploadToken(const std::shared_ptr<core_gen::IRequestUploadTokenCallback> & callback) {
        
        auto tcallback = std::make_shared<CallbackResult<core_gen::RUploadToken>>();
        tcallback->callback = [callback, tcallback](std::shared_ptr<core_gen::RUploadToken> data) {
            
            std::experimental::optional<core_gen::RUploadToken> token;
            if (data != nullptr) {
                token = *data;
            }
            
            callback->onTokenGet(token, *tcallback->result);
        };
        
        auto accountService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IAccountService>();
        accountService->requestUploadToken(tcallback);
    }
    
    void ProfileUiController::signout(const std::shared_ptr<core_gen::IActionCallback> & callback) {
        
        auto tcallback = std::make_shared<CallbackResult<core_gen::RActionResult>>();
        tcallback->callback = [callback, tcallback](std::shared_ptr<core_gen::RActionResult> data) {
            callback->onResponse(*tcallback->result);
        };
        
        auto accountService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IAccountService>();
        accountService->signout(tcallback);
    }
    
}