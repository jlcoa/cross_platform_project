//
//  lifecyle_ui_controller.cpp
//  core
//
//  Created by Steve Chen on 2/16/16.
//
//

#include "lifecyle_ui_controller.hpp"

#include "../../app/unified_factory.hpp"

namespace core {
    
    LifecycleUiController::LifecycleUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::ILifecyleViewModelDelegate> & delegate):AbstractUiController(unifiedFactory, delegate) {
        m_accountService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IAccountService>();
    };
    
    void LifecycleUiController::start() {
        m_accountService->addAccountObserver(shared_from_this());
        m_accountService->start();
    }
    
    void LifecycleUiController::onAccountStatusChanged(core_gen::EAccountStatus accountStatus) {
        m_delegate->onAccountStatusChanged(accountStatus);
    }
    
    core_gen::RAccountResponse LifecycleUiController::getAccountInfo() {
        return *(m_accountService->getAccountInfo());
    }
}