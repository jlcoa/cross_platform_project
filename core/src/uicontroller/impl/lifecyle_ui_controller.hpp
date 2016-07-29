//
//  lifecyle_ui_controller.hpp
//  core
//
//  Created by Steve Chen on 2/16/16.
//
//

#pragma once

#include "../../interface/i_lifecycle_ui_controller.hpp"

#include "../i_ui_controller.hpp"

#include "../../interface/i_lifecyle_view_model_delegate.hpp"

#include "../../service/i_account_service.hpp"

namespace core {
    
    class LifecycleUiController: public AbstractUiController<IViewModel, core_gen::ILifecyleViewModelDelegate>, public core_gen::ILifecycleUiController, public IAccountServiceObserver, public std::enable_shared_from_this<LifecycleUiController> {
        
    public:
        
        LifecycleUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::ILifecyleViewModelDelegate> & delegate);
        
        void start() override;
        
        void onAccountStatusChanged(core_gen::EAccountStatus accountStatus) override;
        
        core_gen::RAccountResponse getAccountInfo() override;
        
    private:
        
        std::shared_ptr<IAccountService> m_accountService;
    };
    
}
