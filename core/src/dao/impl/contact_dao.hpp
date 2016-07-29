//
//  contact_dao.hpp
//  core
//
//  Created by Steve Chen on 2/13/16.
//
//

#pragma once

#include "../i_contact_dao.hpp"

namespace core {
    
    class ContactDao: public IContactDao, public AbstractDao {
    
    public:
        
        ContactDao(std::weak_ptr<IDaoFactory> df);
        
        void onCreate(std::shared_ptr<DatabaseProvider> dbProvider) override;
        
        void onUpgrade(int oldVersion , int newVersion) override;
        
        void saveModel(std::shared_ptr<core_gen::RContact> model, std::shared_ptr<DataChangeMap> changeMap = nullptr) override;
        
        void saveModels(std::vector<std::shared_ptr<core_gen::RContact>>& models, std::shared_ptr<DataChangeMap> changeMap = nullptr) override;
        
        std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> allContacts() override;
        
        std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> groupMembers(std::shared_ptr<core_gen::RGroup> group) override;
        
        std::shared_ptr<std::vector<std::shared_ptr<core_gen::RContact>>> query(const std::vector<std::string> &column, const std::map<std::string, sqlite::Value> & where, const std::vector<std::string> &orderBy, size_t count = 0, size_t offset = 0) override;
        
        std::shared_ptr<core_gen::RContact> objectByID(const std::string& id) override;
        
    protected:
        
        std::map<std::string, sqlite::Value> toDb(std::shared_ptr<core_gen::Model> model) override;
        
        std::shared_ptr<core_gen::Model> toObject(sqlite::Cursor &cursor) override;
        
    };
}
