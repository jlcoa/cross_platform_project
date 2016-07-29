//
//  group_member_ui_controller.cpp
//  core
//
//  Created by Steve Chen on 2/28/16.
//
//

#include "group_member_ui_controller.hpp"

#include "../../app/unified_factory.hpp"

#include "../../interface/i_group_callback.hpp"

#include "../../interface/r_group.hpp"

namespace core {
    
    GroupMemberUiController::GroupMemberUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate):AbstractUiController(unifiedFactory, delegate) {

        m_contactService = unifiedFactory.lock()->getBizServiceFactory()->getService<IContactService>();
        
    };
    
    void GroupMemberUiController::init() {
        
    }
    
    void GroupMemberUiController::onDataChanged(const string &modelName, shared_ptr<ModelChangeTypeMap> changeMap) {
        
        auto group = m_viewModel->getGroup();
        
        for (auto typeVector : *changeMap) {
            
            for (auto model : *typeVector.second) {
                auto gmodel = std::dynamic_pointer_cast<core_gen::RGroup>(model);
                if (group.id == gmodel->id) {
                    loadData(*gmodel);
                    break;
                }
            }
        }
        
    }
    
    void GroupMemberUiController::loadData(const core_gen::RGroup & group) {
        
        if (m_viewModel == nullptr) {
            auto notificationService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IDataChangeNotificationService>();
            
            notificationService->subscribe<core_gen::RGroup>(shared_from_this());
        }
        
        auto dataSource = std::make_shared<ContactTableDataSource>(m_contactService->groupMembers(std::make_shared<core_gen::RGroup>(group)), shared_from_this());
        
        m_viewModel = std::make_shared<GroupMemberViewModel>(dataSource);
        m_viewModel->setGroup(group);
        dataSource->loadData();
        
    }
    
    void GroupMemberUiController::addMembers(const std::vector<std::string> & memberIds, const std::shared_ptr<core_gen::IGroupCallback> & callback) {
        
        auto tcallback = std::make_shared<CallbackResult<core_gen::RGroup>>();
        tcallback->callback = [=](std::shared_ptr<core_gen::RGroup> data) {
            callback->onGroupUpdated(*data, tcallback->result->result);
        };
        m_contactService->addMembers(*m_viewModel->getGroup().id, memberIds, tcallback);
    
    }
    
    void GroupMemberUiController::removeMembers(const std::vector<std::string> & memberIds, const std::shared_ptr<core_gen::IGroupCallback> & callback) {
        
        auto tcallback = std::make_shared<CallbackResult<core_gen::RGroup>>();
        tcallback->callback = [=](std::shared_ptr<core_gen::RGroup> data) {
            callback->onGroupUpdated(*data, tcallback->result->result);
        };
        m_contactService->removeMembers(*m_viewModel->getGroup().id, memberIds, tcallback);

        
    }
    
}