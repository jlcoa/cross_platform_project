//
//  i_contact_dao.hpp
//  core
//
//  Created by Steve Chen on 2/13/16.
//
//

#pragma once

#include "i_dao_factory.hpp"
#include "../interface/r_contact.hpp"
#include "../interface/r_group.hpp"
#include "../dao/object_fetcher.hpp"

#include "data_change_map.hpp"

namespace core {
    
    class IContactDao: public IDao {
        
    public:
        
        virtual void saveModel(std::shared_ptr<core_gen::RContact> model, std::shared_ptr<DataChangeMap> changeMap = nullptr) = 0;
        
        virtual void saveModels(std::vector<std::shared_ptr<core_gen::RContact>>& models, std::shared_ptr<DataChangeMap> changeMap = nullptr) = 0;
        
        virtual std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> allContacts() = 0;
        
        virtual std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> groupMembers(std::shared_ptr<core_gen::RGroup> group) = 0;
        
        virtual std::shared_ptr<std::vector<std::shared_ptr<core_gen::RContact>>> query(const std::vector<std::string> &column, const std::map<std::string, sqlite::Value> & where, const std::vector<std::string> &orderBy, size_t count = 0, size_t offset = 0) = 0;
        
        virtual std::shared_ptr<core_gen::RContact> objectByID(const std::string& id) = 0;
    };
    
}
