//
//  group_member_dao.hpp
//  core
//
//  Created by Steve Chen on 2/28/16.
//
//

#pragma once

#include "../i_group_member_dao.hpp"

namespace core {
    
    class GroupMemberDao: public IGroupMemberDao,  public AbstractDao {
        
    public:
        
        GroupMemberDao(std::weak_ptr<IDaoFactory> df);
        
        void onCreate(std::shared_ptr<DatabaseProvider> dbProvider) override;
        
        void onUpgrade(int oldVersion , int newVersion) override;
        
        void saveModel(std::shared_ptr<core_gen::RGroupMember> model, std::shared_ptr<DataChangeMap> changeMap = nullptr) override;
        
        void saveModels(std::vector<std::shared_ptr<core_gen::RGroupMember>>& models, std::shared_ptr<DataChangeMap> changeMap = nullptr) override;
        
//        std::map<std::string, sqlite::Value> toDb(GroupMember& model) override;
//        
//        std::shared_ptr<GroupMember> toObject(sqlite::Cursor &cursor) override;
//        
        void clear4Group(const std::string& groupId, std::shared_ptr<DataChangeMap> changeMap = nullptr) override;
        
        void removeMember4Group(const std::string& groupId, const std::vector<std::string> memberIds, std::shared_ptr<DataChangeMap> changeMap = nullptr) override;
        
        bool isGroupAdminOrOwner(const std::string& groupId, const std::string& userId) override;
        
    protected:
        
        std::map<std::string, sqlite::Value> toDb(std::shared_ptr<core_gen::Model> model) override;
        
        std::shared_ptr<core_gen::Model> toObject(sqlite::Cursor &cursor) override;
    };
    
}
