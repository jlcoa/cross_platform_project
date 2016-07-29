//
//  group_member_dao.cpp
//  core
//
//  Created by Steve Chen on 2/28/16.
//
//

#include "group_member_dao.hpp"

namespace core {
    
    GroupMemberDao::GroupMemberDao(std::weak_ptr<IDaoFactory> df) : AbstractDao{df, std::type_index(typeid(core_gen::RGroupMember))} {
        addColumn(core_gen::RGroupMember::ID, SQL_TEXT);
        addColumn(core_gen::RGroupMember::GROUPID, SQL_TEXT);
        addColumn(core_gen::RGroupMember::USERID, SQL_TEXT);
        addColumn(core_gen::RGroupMember::TYPE, SQL_INTEGER);
        
        m_primaryKey = core_gen::RGroupMember::ID;
    }
    
    std::shared_ptr<core_gen::Model> GroupMemberDao::toObject(sqlite::Cursor &cursor) {
        
        auto model = std::make_shared<core_gen::RGroupMember>();
        
        fillStringValue(cursor, m_columnMap[core_gen::RGroupMember::ID]->position, model->id);
        fillStringValue(cursor, m_columnMap[core_gen::RGroupMember::GROUPID]->position, model->groupId);
        fillStringValue(cursor, m_columnMap[core_gen::RGroupMember::USERID]->position, model->userId);
        
        std::experimental::optional<std::int64_t> target;
        fillIntValue(cursor, m_columnMap[core_gen::RGroupMember::TYPE]->position, target);
        
        if (target) {
            model->type = (core_gen::EGroupMemberType)*target;
        }
        
        return model;
        
    };
    
    std::map<std::string, sqlite::Value> GroupMemberDao::toDb(std::shared_ptr<core_gen::Model> model) {
       
        std::map<std::string, sqlite::Value> contents;
        
        auto gm = std::dynamic_pointer_cast<core_gen::RGroupMember>(model);
        
        extractStringValue(contents, core_gen::RGroupMember::GROUPID, gm->groupId);
        
        extractStringValue(contents, core_gen::RGroupMember::ID, gm->id);
        
        extractStringValue(contents, core_gen::RGroupMember::USERID, gm->userId);
        
        if (gm->type) {
            std::experimental::optional<std::int64_t> target = (int64_t)(*gm->type);
            extractIntValue(contents, core_gen::RGroupMember::TYPE, target);
        }
        
        return contents;
    }
    
    bool GroupMemberDao::isGroupAdminOrOwner(const std::string& groupId, const std::string& userId) {
        
        std::map<std::string, sqlite::Value> where = {{"`" + core_gen::RGroupMember::GROUPID + "` = ?%d", groupId}, {"`" + core_gen::RGroupMember::USERID + "` = ?%d", userId}, {"`" + core_gen::RGroupMember::TYPE + "` > ?%d", 0}};
        
        
        auto sql = "select * from `" + m_tableName + "` where `" + core_gen::RGroupMember::GROUPID + "` = '" + groupId + "' and `" + core_gen::RGroupMember::USERID + "` = '" + userId + "' and type > 0";
        
        shared_ptr<sqlite::Stmt> queryStmt = m_dbProvider->getDatabase(DatabaseType::READ)->prepare(sql);
        
        auto cursor = queryStmt->exec_query();
        
        return cursor.is_valid();
        
    }
    
    void GroupMemberDao::saveModel(std::shared_ptr<core_gen::RGroupMember> model, std::shared_ptr<DataChangeMap> changeMap) {
        saveModelInternal(model, changeMap);
    }
    
    void GroupMemberDao::saveModels(std::vector<std::shared_ptr<core_gen::RGroupMember>>& models, std::shared_ptr<DataChangeMap> changeMap) {
        saveModelsInternal(models, changeMap);
    }
    
    void GroupMemberDao::removeMember4Group(const std::string& groupId, const std::vector<std::string> memberIds, std::shared_ptr<DataChangeMap> changeMap) {
        
        int32_t index = 1;
        
        auto where = " `" + core_gen::RGroupMember::GROUPID + "` = ?" + std_patch::to_string(index) + " AND `" + core_gen::RGroupMember::USERID  +  "` in (";
        index ++;
        
        std::vector<sqlite::Value> values = {groupId};
        
        for (auto iter = memberIds.begin(); iter != memberIds.end(); iter ++, index ++) {
            where += "?" + std_patch::to_string(index);
            if (iter != --memberIds.end()) {
                where += ", ";
            }
        }
        
        values.insert(values.end(), memberIds.begin(), memberIds.end());
        
        where += ")";
        
        AbstractDao::deleteInternal(where, values);
    }
    
    void GroupMemberDao::clear4Group(const std::string& groupId, std::shared_ptr<DataChangeMap> changeMap) {
        
        auto where = " `" + core_gen::RGroupMember::GROUPID + "` = ?1 ";
        std::vector<sqlite::Value> value = {groupId};
        AbstractDao::deleteInternal(where, value);
    }
    
    void GroupMemberDao::onCreate(std::shared_ptr<DatabaseProvider> dbProvider) {
        AbstractDao::onCreate(dbProvider);
    }
    
    void GroupMemberDao::onUpgrade(int oldVersion, int newVersion) {
        
    }
    
}