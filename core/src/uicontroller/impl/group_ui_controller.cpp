//
//  group_ui_controller.cpp
//  core
//
//  Created by Steve Chen on 2/21/16.
//
//

#include "group_ui_controller.hpp"

#include "../../app/unified_factory.hpp"

namespace core {
    
    GroupUiController::GroupUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate):AbstractUiController(unifiedFactory, delegate) {
        
    };
    
    void GroupUiController::init() {
        
        m_contactService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IContactService>();
        
        auto dataSource = std::make_shared<GroupTableDataSource>(m_contactService->allGroups(), shared_from_this());
        m_viewModel = std::make_shared<GroupViewModel>(dataSource);
        
        dataSource->loadData();
    
    };
}