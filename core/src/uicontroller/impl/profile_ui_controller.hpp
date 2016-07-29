//
//  profile_ui_controller.hpp
//  core
//
//  Created by Steve Chen on 3/21/16.
//
//

#pragma once

#include "../../interface/i_profile_ui_controller.hpp"
#include "../../interface/i_profile_view_model.hpp"
#include "../../interface/i_view_model_delegate.hpp"
#include "../../service/i_account_service.hpp"

#include "../i_ui_controller.hpp"

namespace core {
    
    class ProfileViewModel: public core_gen::IProfileViewModel, public AbstractViewModel {
      
    public:
        
        void setAccount(const core_gen::RAccount & account) override {
            m_account = std::make_shared<core_gen::RAccount>(account);
            
        };
        
        core_gen::RAccount getAccount() override {return *m_account;};
        
    private:
        
        std::shared_ptr<core_gen::RAccount> m_account;
        
    };
    
    class ProfileUiController: public core_gen::IProfileUiController, public AbstractUiController<core_gen::IProfileViewModel, core_gen::IViewModelDelegate>, public std::enable_shared_from_this<ProfileUiController> {
        
    public:
        
        ProfileUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate);
        
        void updateAvatar(const core_gen::RAvatarInfo & avatarInfo, const std::shared_ptr<core_gen::IActionCallback> & callback) override;
        
        void requestUploadToken(const std::shared_ptr<core_gen::IRequestUploadTokenCallback> & callback) override;
        
        std::shared_ptr<core_gen::IProfileViewModel> getViewModel() override {
            return AbstractUiController::getViewModel();
        };
        
        void signout(const std::shared_ptr<core_gen::IActionCallback> & callback) override;
        
    private:
        
        
    };
    
}