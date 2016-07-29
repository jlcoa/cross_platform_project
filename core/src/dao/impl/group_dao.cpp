//
//  group_dao.cpp
//  core
//
//  Created by Steve Chen on 2/21/16.
//
//

#include "group_dao.hpp"
#include "../i_group_member_dao.hpp"

namespace core {
    
    GroupDao::GroupDao(std::weak_ptr<IDaoFactory> df) : AbstractDao{df, std::type_index(typeid(core_gen::RGroup))} {
        addColumn(core_gen::RGroup::ID, SQL_TEXT);
        addColumn(core_gen::RGroup::GROUPNAME, SQL_TEXT);
        addColumn(core_gen::RGroup::GROUPTYPE, SQL_TEXT);
//        addColumn(core_gen::RGroup::MEMBERSCOUNT, SQL_INTEGER);
        
        m_primaryKey = core_gen::RGroup::ID;
    }
    
    void GroupDao::onCreate(std::shared_ptr<DatabaseProvider> dbProvider) {
        AbstractDao::onCreate(dbProvider);
    }
    
    void GroupDao::onUpgrade(int oldVersion, int newVersion) {
        
    }
    
    std::shared_ptr<core_gen::Model> GroupDao::toObject(sqlite::Cursor &cursor) {
        
        auto model = std::make_shared<core_gen::RGroup>();
        
        fillStringValue(cursor, m_columnMap[core_gen::RGroup::ID]->position, model->id);
        fillStringValue(cursor, m_columnMap[core_gen::RGroup::GROUPNAME]->position, model->groupName);
        fillStringValue(cursor, m_columnMap[core_gen::RGroup::GROUPTYPE]->position, model->groupType);
//        fillIntValue(cursor, m_columnMap[core_gen::RGroup::MEMBERSCOUNT]->position, model->membersCount);
        
        return model;
        
    };
    
    std::map<std::string, sqlite::Value> GroupDao::toDb(std::shared_ptr<core_gen::Model> model) {
        std::map<std::string, sqlite::Value> contents;
        
        auto group = std::dynamic_pointer_cast<core_gen::RGroup>(model);
        
        extractStringValue(contents, core_gen::RGroup::ID, group->id);
        
        extractStringValue(contents, core_gen::RGroup::GROUPNAME, group->groupName);
        
        extractStringValue(contents, core_gen::RGroup::GROUPTYPE, group->groupType);
        
//        extractIntValue(contents, core_gen::RGroup::MEMBERSCOUNT, contact.membersCount);
        
        return contents;
    }
    
    void GroupDao::deleteModel(std::shared_ptr<core_gen::RGroup> model, std::shared_ptr<DataChangeMap> changeMap) {
        
        auto where = " `" + core_gen::RGroupMember::GROUPID + "` = ?1 ";
        
        std::vector<sqlite::Value> values = {*model->id};
        
        deleteInternal(where, values);
        
        m_daoFactory.lock()->getDao<IGroupMemberDao>()->clear4Group(*model->id);
        
        generateChangeMap(model, EModelChangeType::Deleted, changeMap);
        
    }
    
    void GroupDao::saveModel(std::shared_ptr<core_gen::RGroup> model, std::shared_ptr<DataChangeMap> changeMap) {
        
        saveModelInternal(model, changeMap);
        
        std::vector<std::shared_ptr<core_gen::RGroupMember>> members;
        if (model->userIds) {
            for (auto memberId: *model->userIds) {
                auto groupMember = std::make_shared<core_gen::RGroupMember>();
                groupMember->id = *model->id + "-" + memberId;
                groupMember->groupId = model->id;
                groupMember->userId = memberId;
                
                if (model->admin) {
                    if(std::find(model->admin->begin(), model->admin->end(), memberId) != model->admin->end()) {
                        groupMember->type = core_gen::EGroupMemberType::ADMIN;
                    }
                }
                
                if (model->owner) {
                    if(std::find(model->owner->begin(), model->owner->end(), memberId) != model->owner->end()) {
                        groupMember->type = core_gen::EGroupMemberType::OWNER;
                    }
                }
                
                members.push_back(groupMember);
            }
            m_daoFactory.lock()->getDao<IGroupMemberDao>()->clear4Group(*model->id);
        }
        
        if (!members.empty()) {
            m_daoFactory.lock()->getDao<IGroupMemberDao>()->saveModels(members);
        }
    }
    
    void GroupDao::saveModels(std::vector<std::shared_ptr<core_gen::RGroup>>& models, std::shared_ptr<DataChangeMap> changeMap) {
        saveModelsInternal(models, changeMap);
    }
    
    std::shared_ptr<core_gen::RGroup> GroupDao::objectByID(const std::string& id) {
        
        std::map<std::string, sqlite::Value> where = {{"`" + core_gen::RGroup::ID + "` = ?%d", id}};
        
        auto result = query({}, where, {});
        
        return result->size() > 0 ? result->at(0) : nullptr;
    }
    
    std::shared_ptr<ObjectFetcher<core_gen::RGroup, IGroupDao>> GroupDao::allModels() {
        
        auto filterLambda = [ = ](const core_gen::RGroup & m) -> bool {
            return true;
        };
        
        std::map<std::string, sqlite::Value> where = {};
        
        auto filter = std::make_shared<ObjectFilter<core_gen::RGroup>>(filterLambda, where);
        
        auto sortLambda = [ = ](const core_gen::RGroup & c1, const core_gen::RGroup & c2) -> int {
            auto res = (*(c1.groupName)).compare(*(c2.groupName));
            return res;
        };
        
        auto equalLambda = [](const core_gen::RGroup & c1, const core_gen::RGroup & c2) {
            return c1.id == c2.id;
        };
        
        auto orderBy = {" `" + core_gen::RGroup::GROUPNAME + "` ASC "};
        
        auto sorter = std::make_shared<ObjectSorter<core_gen::RGroup>>(sortLambda, equalLambda, orderBy);
        
        return std::make_shared<ObjectFetcher<core_gen::RGroup, IGroupDao>>(m_daoFactory.lock(), filter, sorter);
    }
    
    std::shared_ptr<std::vector<std::shared_ptr<core_gen::RGroup>>> GroupDao::query(const std::vector<std::string> &column, const  std::map<std::string, sqlite::Value> & where, const std::vector<std::string> &orderBy, size_t count, size_t offset) {
        
        auto result = std::make_shared<std::vector<std::shared_ptr<core_gen::RGroup>>>();
        
        auto cursor = queryInternal(column, where, orderBy, count, offset);
        
        while (cursor.is_valid()) {
            auto contact = std::dynamic_pointer_cast<core_gen::RGroup>(toObject(cursor));
            result->push_back(contact);
            cursor.next();
        }
        
        return result;
    }
    
}