//
//  group_update_ui_controller.cpp
//  core
//
//  Created by Steve Chen on 2/28/16.
//
//

#include "group_update_ui_controller.hpp"
#include "../../interface/i_group_callback.hpp"
#include "../../app/unified_factory.hpp"

namespace core {
    
    GroupUpdateUiController::GroupUpdateUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate):AbstractUiController(unifiedFactory, delegate) {
        
        m_viewModel = std::make_shared<GroupUpdateViewModel>();
        
        m_contactService = unifiedFactory.lock()->getBizServiceFactory()->getService<IContactService>();
        
    };
    
    
    void GroupUpdateUiController::updateGroupName(const std::string & groupName, const std::shared_ptr<core_gen::IGroupCallback> & callback) {
        
        auto tcallback = std::make_shared<CallbackResult<core_gen::RGroup>>();
        tcallback->callback = [=](std::shared_ptr<core_gen::RGroup> data) {
            callback->onGroupUpdated(*data, tcallback->result->result);
        };
        
        m_contactService->updateGroupName(std::make_shared<core_gen::RGroup>(std::move(m_viewModel->getGroup())) , groupName, tcallback);
    }
}
