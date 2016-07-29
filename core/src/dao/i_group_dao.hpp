//
//  i_group_dao.hpp
//  core
//
//  Created by Steve Chen on 2/21/16.
//
//

#pragma once

#include "i_dao_factory.hpp"

#include "../interface/r_group.hpp"

#include "../dao/object_fetcher.hpp"

namespace core {
    
    class IGroupDao: public IDao {
        
    public:
        
        virtual void saveModel(std::shared_ptr<core_gen::RGroup> model, std::shared_ptr<DataChangeMap> changeMap = nullptr) = 0;
        
        virtual void saveModels(std::vector<std::shared_ptr<core_gen::RGroup>>& models, std::shared_ptr<DataChangeMap> changeMap = nullptr) = 0;
        
        virtual void deleteModel(std::shared_ptr<core_gen::RGroup> model, std::shared_ptr<DataChangeMap> changeMap = nullptr) = 0;
        
        virtual std::shared_ptr<ObjectFetcher<core_gen::RGroup, IGroupDao>> allModels() = 0;
        
//        virtual std::map<std::string, sqlite::Value> toDb(core_gen::RGroup& model) = 0;
//        
//        virtual std::shared_ptr<core_gen::RGroup> toObject(sqlite::Cursor &cursor) = 0;
        
        virtual std::shared_ptr<std::vector<std::shared_ptr<core_gen::RGroup>>> query(const std::vector<std::string> &column, const std::map<std::string, sqlite::Value> & where, const std::vector<std::string> &orderBy, size_t count = 0, size_t offset = 0) = 0;
        
        virtual std::shared_ptr<core_gen::RGroup> objectByID(const std::string& id) = 0;
    };
    
}