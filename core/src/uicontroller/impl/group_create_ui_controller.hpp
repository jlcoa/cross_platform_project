//
//  group_create_ui_controller.hpp
//  core
//
//  Created by Steve Chen on 2/27/16.
//
//

#pragma once

#include "../../interface/i_group_create_ui_controller.hpp"

#include "../../interface/i_view_model_delegate.hpp"

#include "../i_ui_controller.hpp"

#include "../../dao/i_group_dao.hpp"

#include "../../service/i_contact_service.hpp"

namespace core {
    
    class GroupCreateUiController: public core_gen::IGroupCreateUiController, public AbstractUiController<IViewModel, core_gen::IViewModelDelegate>, public std::enable_shared_from_this<GroupCreateUiController> {
        
    public:
        
        GroupCreateUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate);
        
        void createGroup(const std::vector<core_gen::RContact> & contacts, const std::shared_ptr<core_gen::IGroupCallback> & callback) override;
        
    private:
        
        std::shared_ptr<IContactService> m_contactService;
    };
    
}
