//
//  i_contact_service.hpp
//  core
//
//  Created by Steve Chen on 2/14/16.
//
//

#pragma once

#include "i_biz_service_factory.hpp"

#include "../dao/object_fetcher.hpp"

#include "../interface/r_contact.hpp"
#include "../dao/i_contact_dao.hpp"

#include "../interface/r_group.hpp"
#include "../dao/i_group_dao.hpp"

#include "../interface/r_action_result.hpp"

namespace core {
    
    class IContactService: public IBizService {
        
    public:
        
        virtual void syncContact() = 0;
        
        virtual void syncGroup() = 0;
        
        virtual std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> allContacts() = 0;
        
        virtual std::shared_ptr<ObjectFetcher<core_gen::RGroup, IGroupDao>> allGroups() = 0;
        
        virtual std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> groupMembers(std::shared_ptr<core_gen::RGroup> group) = 0;
        
        virtual void createGroup(const std::vector<core_gen::RContact> & contacts, std::shared_ptr<CallbackResult<core_gen::RGroup>>) = 0;
        
        virtual void quitGroup(std::shared_ptr<core_gen::RGroup> group, std::shared_ptr<CallbackResult<core_gen::RActionResult>>) = 0;
        
        virtual void updateGroupName(std::shared_ptr<core_gen::RGroup> group, const std::string &groupName, std::shared_ptr<CallbackResult<core_gen::RGroup>>) = 0;
        
        virtual void addMembers(const std::string &groupId, const std::vector<std::string> & memberIds, std::shared_ptr<CallbackResult<core_gen::RGroup>>) = 0;
        
        virtual  void removeMembers(const std::string &groupId, const std::vector<std::string> & memberIds,  std::shared_ptr<CallbackResult<core_gen::RGroup>>) = 0;
        
        
    };
    
}
