//
//  group_update_ui_controller.hpp
//  core
//
//  Created by Steve Chen on 2/28/16.
//
//

#pragma once

#include "../../interface/i_group_update_ui_controller.hpp"
#include "../../interface/i_group_update_view_model.hpp"
#include "../../interface/i_view_model_delegate.hpp"

#include "../i_ui_controller.hpp"

#include "../../service/i_contact_service.hpp"

namespace core {
    
    class GroupUpdateViewModel: public core_gen::IGroupUpdateViewModel, public AbstractViewModel {
    
    public:
        
        GroupUpdateViewModel(): AbstractViewModel() {
            
        };
        
        void setGroup(const core_gen::RGroup & group) override { m_group = std::make_shared<core_gen::RGroup>(group); };
        
        core_gen::RGroup getGroup() override { return *m_group; };
        
    private:
        std::shared_ptr<core_gen::RGroup> m_group;
    };
    
    class GroupUpdateUiController: public core_gen::IGroupUpdateUiController, public AbstractUiController<core_gen::IGroupUpdateViewModel, core_gen::IViewModelDelegate> {
        
    public:
        
        GroupUpdateUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate);
        
        void updateGroupName(const std::string & groupName, const std::shared_ptr<core_gen::IGroupCallback> & callback) override;
        
        std::shared_ptr<core_gen::IGroupUpdateViewModel> getViewModel() override {
            return AbstractUiController::getViewModel();
        };
        
    private:
        
        std::shared_ptr<IContactService> m_contactService;
        
    };
    
}
