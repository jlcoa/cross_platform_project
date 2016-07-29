//
//  i_group_member_dao.hpp
//  core
//
//  Created by Steve Chen on 2/28/16.
//
//

#pragma once

#include "i_dao_factory.hpp"
#include "../interface/r_contact.hpp"
#include "../interface/r_group.hpp"

#include "../interface/r_group_member.hpp"

namespace core {
    
    class IGroupMemberDao: public IDao {
        
    public:
        
        virtual void saveModel(std::shared_ptr<core_gen::RGroupMember> model, std::shared_ptr<DataChangeMap> changeMap = nullptr) = 0;
        
        virtual void saveModels(std::vector<std::shared_ptr<core_gen::RGroupMember>>& models, std::shared_ptr<DataChangeMap> changeMap = nullptr) = 0;
        
//        virtual std::map<std::string, sqlite::Value> toDb(GroupMember& model) = 0;
//        
//        virtual std::shared_ptr<GroupMember> toObject(sqlite::Cursor &cursor) = 0;
        
        virtual void clear4Group(const std::string& groupId, std::shared_ptr<DataChangeMap> changeMap = nullptr) = 0;
        
        virtual void removeMember4Group(const std::string& groupId, const std::vector<std::string> memberIds, std::shared_ptr<DataChangeMap> changeMap = nullptr) = 0;
        
        virtual bool isGroupAdminOrOwner(const std::string& groupId, const std::string& userId) = 0;
        
//        virtual std::shared_ptr<std::vector<std::shared_ptr<core_gen::RContact>>> query(const std::vector<std::string> &column, const std::map<std::string, sqlite::Value> & where, const std::vector<std::string> &orderBy, size_t count = 0, size_t offset = 0) = 0;
        
    };
 
    
}
