//
//  group_detail_ui_controller.cpp
//  core
//
//  Created by Steve Chen on 3/5/16.
//
//

#include "group_detail_ui_controller.hpp"

#include "../../app/unified_factory.hpp"
#include "../../interface/i_action_callback.hpp"

namespace core {
    
    GroupDetailUiController::GroupDetailUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate):AbstractUiController(unifiedFactory, delegate) {
        
        m_viewModel = std::make_shared<GroupDetailViewModel>();
        
        m_contactService = unifiedFactory.lock()->getBizServiceFactory()->getService<IContactService>();
        
    };
    
    void GroupDetailUiController::setGroup(const core_gen::RGroup & group) {
        m_viewModel->setGroup(group);
        
        auto unifiedFactory = m_unifiedFactory.lock();
        
        auto notificationService = unifiedFactory->getBizServiceFactory()->getService<IDataChangeNotificationService>();
        notificationService->subscribe<core_gen::RGroup>(shared_from_this());
    }
    
    void GroupDetailUiController::quit(const std::shared_ptr<core_gen::IActionCallback> &callback) {
        
        auto tcallback = std::make_shared<CallbackResult<core_gen::RActionResult>>();
        tcallback->callback = [callback](std::shared_ptr<core_gen::RActionResult> data) {
            callback->onResponse(*data);
        };
        
        m_contactService->quitGroup(std::make_shared<core_gen::RGroup>(m_viewModel->getGroup()), tcallback);
        
    }
    
    void GroupDetailUiController::onDataChanged(const string& modelName, shared_ptr<ModelChangeTypeMap> changeMap) {
        
        auto group = m_viewModel->getGroup();
        
        for (auto typeVector : *changeMap) {
            
            for (auto model : *typeVector.second) {
                auto gmodel = std::dynamic_pointer_cast<core_gen::RGroup>(model);
                if (group.id == gmodel->id) {
                    m_viewModel->setGroup(*gmodel);
                    break;
                }
            }
            
        }
        
    }
    
}