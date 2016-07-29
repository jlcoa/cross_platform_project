//
//  group_detail_ui_controller.hpp
//  core
//
//  Created by Steve Chen on 3/5/16.
//
//

#pragma once

#include "../../interface/i_group_detail_ui_controller.hpp"
#include "../../interface/i_group_detail_view_model.hpp"
#include "../../interface/i_view_model_delegate.hpp"

#include "../i_ui_controller.hpp"

#include "../../service/i_contact_service.hpp"

namespace core {
    
    class GroupDetailViewModel: public core_gen::IGroupDetailViewModel, public AbstractViewModel {
    
    public:
        
        GroupDetailViewModel(): AbstractViewModel() {};
        
        void setGroup(const core_gen::RGroup & group) override { m_group = std::make_shared<core_gen::RGroup>(group);
        };
        
        core_gen::RGroup getGroup() override { return *m_group; };
        
    private:
        std::shared_ptr<core_gen::RGroup> m_group;
        
    };
    
    class GroupDetailUiController: public core_gen::IGroupDetailUiController, public AbstractUiController<core_gen::IGroupDetailViewModel, core_gen::IViewModelDelegate>, public IDataChangeListener , public std::enable_shared_from_this<GroupDetailUiController> {
      
    public:
        
        GroupDetailUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate);
        
        void setGroup(const core_gen::RGroup & group) override;
        
        void onDataChanged(const string& modelName, shared_ptr<ModelChangeTypeMap> changeMap) override;
        
        std::shared_ptr<core_gen::IGroupDetailViewModel> getViewModel() override {
            return AbstractUiController::getViewModel();
        }
        
        void quit(const std::shared_ptr<core_gen::IActionCallback> & callback) override;
        
        
    private:
        
        std::shared_ptr<IContactService> m_contactService;
        
    };
    
}
