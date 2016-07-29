//
//  contact_dao.cpp
//  core
//
//  Created by Steve Chen on 2/13/16.
//
//

#include "contact_dao.hpp"
#include "../../interface/r_group_member.hpp"

namespace core {
    
    ContactDao::ContactDao(std::weak_ptr<IDaoFactory> df) : AbstractDao{df, std::type_index(typeid(core_gen::RContact))} {
        addColumn(core_gen::RContact::ID, SQL_TEXT);
        addColumn(core_gen::RContact::USERNAME, SQL_TEXT);
        addColumn(core_gen::RContact::EMAIL, SQL_TEXT);
        addColumn(core_gen::RContact::FIRSTNAME, SQL_TEXT);
        addColumn(core_gen::RContact::LASTNAME, SQL_TEXT);
        addColumn(core_gen::RContact::DISPLAYNAME, SQL_TEXT);
        addColumn(core_gen::RContact::COMPANYID, SQL_TEXT);
        addColumn(core_gen::RContact::AVATARURL, SQL_TEXT);
        m_primaryKey = core_gen::RContact::ID;
    }
    
    void ContactDao::onCreate(std::shared_ptr<DatabaseProvider> dbProvider) {
        AbstractDao::onCreate(dbProvider);
    }
    
    void ContactDao::onUpgrade(int oldVersion, int newVersion) {
        
    }
    
    std::shared_ptr<core_gen::Model> ContactDao::toObject(sqlite::Cursor &cursor) {
        
        auto contact = std::make_shared<core_gen::RContact>();
        
        fillStringValue(cursor, m_columnMap[core_gen::RContact::ID]->position, contact->id);
        fillStringValue(cursor, m_columnMap[core_gen::RContact::USERNAME]->position, contact->username);
        fillStringValue(cursor, m_columnMap[core_gen::RContact::EMAIL]->position, contact->email);
        fillStringValue(cursor, m_columnMap[core_gen::RContact::FIRSTNAME]->position, contact->firstName);
        fillStringValue(cursor, m_columnMap[core_gen::RContact::LASTNAME]->position, contact->lastName);
        fillStringValue(cursor, m_columnMap[core_gen::RContact::DISPLAYNAME]->position, contact->displayName);
        fillStringValue(cursor, m_columnMap[core_gen::RContact::COMPANYID]->position, contact->companyId);
        fillStringValue(cursor, m_columnMap[core_gen::RContact::AVATARURL]->position, contact->avatarUrl);
        return contact;
        
    };
    
    std::map<std::string, sqlite::Value> ContactDao::toDb(std::shared_ptr<core_gen::Model> model) {
        
        
        auto contact = std::dynamic_pointer_cast<core_gen::RContact>(model);
        
        std::map<std::string, sqlite::Value> contents;
        
        extractStringValue(contents, core_gen::RContact::ID, contact->id);
        extractStringValue(contents, core_gen::RContact::USERNAME, contact->username);
        extractStringValue(contents, core_gen::RContact::EMAIL, contact->email);
        extractStringValue(contents, core_gen::RContact::FIRSTNAME, contact->firstName);
        extractStringValue(contents, core_gen::RContact::LASTNAME, contact->lastName);
        extractStringValue(contents, core_gen::RContact::DISPLAYNAME, contact->displayName);
        extractStringValue(contents, core_gen::RContact::COMPANYID, contact->companyId);
        extractStringValue(contents, core_gen::RContact::AVATARURL, contact->avatarUrl);
        return contents;
    }
    
    void ContactDao::saveModel(std::shared_ptr<core_gen::RContact> model, std::shared_ptr<DataChangeMap> changeMap) {
        saveModelInternal(model, changeMap);
    }
    
    void ContactDao::saveModels(std::vector<std::shared_ptr<core_gen::RContact>>& models, std::shared_ptr<DataChangeMap> changeMap) {
        AbstractDao::saveModelsInternal(models, changeMap);
    }
    
    std::shared_ptr<core_gen::RContact> ContactDao::objectByID(const std::string& id) {
        
        std::map<std::string, sqlite::Value> where = {{"`" + core_gen::RContact::ID + "` = ?%d", id}};
        
        auto result = query({}, where, {});
        
        return result->size() > 0 ? result->at(0) : nullptr;
    }
    
    
    std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> ContactDao::allContacts() {
        
        auto filterLambda = [ = ](const core_gen::RContact & m) -> bool {
            return true;
        };
        
        std::map<std::string, sqlite::Value> where = {}; //{{" `" + core_gen::RContact::DISPLAYNAME + "` like ?%d", "%Steve%"}};
        
        auto filter = std::make_shared<ObjectFilter<core_gen::RContact>>(filterLambda, where);
        
        auto sortLambda = [ = ](const core_gen::RContact & c1, const core_gen::RContact & c2) -> int {
            auto res = (*(c1.displayName)).compare(*(c2.displayName));
            return res;
        };
        
        auto equalLambda = [](const core_gen::RContact & c1, const core_gen::RContact & c2) {
            return c1.id == c2.id;
        };
        
        auto orderBy = {" `" + core_gen::RContact::DISPLAYNAME + "` ASC "};
        
        auto sorter = std::make_shared<ObjectSorter<core_gen::RContact>>(sortLambda, equalLambda, orderBy);
        
        return std::make_shared<ObjectFetcher<core_gen::RContact, IContactDao>>(m_daoFactory.lock(), filter, sorter);
    }
    
    std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> ContactDao::groupMembers(std::shared_ptr<core_gen::RGroup> group) {
        
        auto filterLambda = [ = ](const core_gen::RContact & m) -> bool {
            return true;
        };
        
        std::map<std::string, sqlite::Value> where = {{" `" + core_gen::RContact::ID + "` IN ( select `" + core_gen::RGroupMember::USERID + "` from `" + typeid(core_gen::RGroupMember).name() + "` where `" + core_gen::RGroupMember::GROUPID + "` = ?%d )", *group->id}};
        
        auto filter = std::make_shared<ObjectFilter<core_gen::RContact>>(filterLambda, where);
        
        auto sortLambda = [ = ](const core_gen::RContact & c1, const core_gen::RContact & c2) -> int {
            auto res = (*(c1.displayName)).compare(*(c2.displayName));
            return res;
        };
        
        auto equalLambda = [](const core_gen::RContact & c1, const core_gen::RContact & c2) {
            return c1.id == c2.id;
        };
        
        auto orderBy = {" `" + core_gen::RContact::DISPLAYNAME + "` ASC "};
        
        auto sorter = std::make_shared<ObjectSorter<core_gen::RContact>>(sortLambda, equalLambda, orderBy);
        
        return std::make_shared<ObjectFetcher<core_gen::RContact, IContactDao>>(m_daoFactory.lock(), filter, sorter);
    }
    
    std::shared_ptr<std::vector<std::shared_ptr<core_gen::RContact>>> ContactDao::query(const std::vector<std::string> &column, const  std::map<std::string, sqlite::Value> & where, const std::vector<std::string> &orderBy, size_t count, size_t offset) {
        
        auto result = std::make_shared<std::vector<std::shared_ptr<core_gen::RContact>>>();
        
        auto cursor = queryInternal(column, where, orderBy, count, offset);
        
        while (cursor.is_valid()) {
            auto contact = std::dynamic_pointer_cast<core_gen::RContact>(toObject(cursor));
            result->push_back(contact);
            cursor.next();
        }
        
        return result;
    }
    
}