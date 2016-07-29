//
//  i_ui_controller_factory.cpp
//  core
//
//  Created by Steve Chen on 2/16/16.
//
//

#include "ui_controller_factory.hpp"

#include "./impl/lifecyle_ui_controller.hpp"
#include "./impl/login_ui_controller.hpp"
#include "./impl/signup_ui_controller.hpp"
#include "./impl/contact_ui_controller.hpp"
#include "./impl/group_ui_controller.hpp"
#include "./impl/group_create_ui_controller.hpp"
#include "./impl/group_update_ui_controller.hpp"
#include "./impl/group_member_ui_controller.hpp"
#include "./impl/group_detail_ui_controller.hpp"
#include "./impl/profile_ui_controller.hpp"

namespace core {
    
    std::shared_ptr<core_gen::ILifecycleUiController> UiControllerFactory::createLifecycleUiController(const std::shared_ptr<core_gen::ILifecyleViewModelDelegate> & delegate) {
        return createUiController<LifecycleUiController>(delegate);
    }
    
    std::shared_ptr<core_gen::ILoginUiController> UiControllerFactory::createLoginUiController(const std::shared_ptr<core_gen::IViewModelDelegate> &delegate) {
        return createUiController<LoginUiController>(delegate);
    }
    
    std::shared_ptr<core_gen::ISignupUiController> UiControllerFactory::createSignUpUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) {
        return createUiController<SignUpUiController>(delegate);
    }
    
    std::shared_ptr<core_gen::IContactUiController> UiControllerFactory::createContactUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) {
        return createUiController<ContactUiController>(delegate);
    }
    
    std::shared_ptr<core_gen::IGroupUiController> UiControllerFactory::createGroupUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) {
         return createUiController<GroupUiController>(delegate);
    }
    
    std::shared_ptr<core_gen::IGroupCreateUiController> UiControllerFactory::createGroupCreateUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) {
        return createUiController<GroupCreateUiController>(delegate);
    }
    
    std::shared_ptr<core_gen::IGroupUpdateUiController> UiControllerFactory::createGroupUpdateUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) {
        return createUiController<GroupUpdateUiController>(delegate);
    }
    
    std::shared_ptr<core_gen::IGroupMemberUiController> UiControllerFactory::createGroupMemberUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) {
        return createUiController<GroupMemberUiController>(delegate);
    }
    
    std::shared_ptr<core_gen::IGroupDetailUiController> UiControllerFactory::createGroupDetailUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) {
        return createUiController<GroupDetailUiController>(delegate);
    }
    
    std::shared_ptr<core_gen::IProfileUiController> UiControllerFactory::createProfileUiController(const std::shared_ptr<core_gen::IViewModelDelegate> & delegate) {
        return createUiController<ProfileUiController>(delegate);
    }
}