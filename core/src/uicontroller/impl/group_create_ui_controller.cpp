//
//  group_create_ui_controller.cpp
//  core
//
//  Created by Steve Chen on 2/27/16.
//
//

#include "group_create_ui_controller.hpp"
#include "../../app/unified_factory.hpp"

#include "../../interface/i_group_callback.hpp"

namespace core {
    
    GroupCreateUiController::GroupCreateUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate):AbstractUiController(unifiedFactory, delegate) {
        
        m_contactService = unifiedFactory.lock()->getBizServiceFactory()->getService<IContactService>();
        
    };
    
    void GroupCreateUiController::createGroup(const std::vector<core_gen::RContact> & contacts, const std::shared_ptr<core_gen::IGroupCallback> & callback) {
        
        auto tcallback = std::make_shared<CallbackResult<core_gen::RGroup>>();
        tcallback->callback = [=](std::shared_ptr<core_gen::RGroup> data) {
            callback->onGroupUpdated(*data, tcallback->result->result);
        };
        
        m_contactService->createGroup(contacts, tcallback);
        
    };
    
}