//
//  contact_service.hpp
//  core
//
//  Created by Steve Chen on 2/14/16.
//
//

#pragma once

#include "../i_contact_service.hpp"

#include "../../dao/i_contact_dao.hpp"

namespace core {
    
    class ContactService: public IContactService, public AbstractBizService, public std::enable_shared_from_this<ContactService> {
        
    public:
        
        ContactService(std::weak_ptr<IUnifiedFactory> unifiedFactory): AbstractBizService(unifiedFactory), m_syncingContact(false), m_syncingGroup(false) {};
        
        void syncContact() override;
        
        void syncGroup() override;
        
        std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> allContacts() override;
        
        std::shared_ptr<ObjectFetcher<core_gen::RGroup, IGroupDao>> allGroups() override;
        
        std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> groupMembers(std::shared_ptr<core_gen::RGroup> group) override;
        
        void createGroup(const std::vector<core_gen::RContact> & contacts, std::shared_ptr<CallbackResult<core_gen::RGroup>>) override;
        
        void quitGroup(std::shared_ptr<core_gen::RGroup> group, std::shared_ptr<CallbackResult<core_gen::RActionResult>>) override;
        
        void updateGroupName(std::shared_ptr<core_gen::RGroup> group, const std::string &groupName, std::shared_ptr<CallbackResult<core_gen::RGroup>>) override;
        
        void addMembers(const std::string &groupId, const std::vector<std::string> & memberIds, std::shared_ptr<CallbackResult<core_gen::RGroup>>) override;
        
        void removeMembers(const std::string &groupId, const std::vector<std::string> & memberIds,  std::shared_ptr<CallbackResult<core_gen::RGroup>>) override;
        
    private:
        
        bool m_syncingContact;
        bool m_syncingGroup;
        
    };
    
}