//
//  contact_ui_controller.cpp
//  core
//
//  Created by Steve Chen on 2/21/16.
//
//

#include "contact_ui_controller.hpp"
#include "../../app/unified_factory.hpp"

namespace core {
    
    ContactUiController::ContactUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate):AbstractUiController(unifiedFactory, delegate) {

    };
    
    void ContactUiController::init() {
        m_contactService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IContactService>();
        
        auto dataSource = std::make_shared<ContactTableDataSource>(m_contactService->allContacts(), shared_from_this());
        m_viewModel = std::make_shared<ContactViewModel>(dataSource);
        dataSource->loadData();
    };
}