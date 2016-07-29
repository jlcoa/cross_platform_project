//
//  group_dao.hpp
//  core
//
//  Created by Steve Chen on 2/21/16.
//
//

#pragma once

#include "../i_group_dao.hpp"

namespace core {
    
    class GroupDao: public IGroupDao, public AbstractDao {
        
    public:
        
        GroupDao(std::weak_ptr<IDaoFactory> df);
        
        void onCreate(std::shared_ptr<DatabaseProvider> dbProvider) override;
        
        void onUpgrade(int oldVersion , int newVersion) override;
        
        void deleteModel(std::shared_ptr<core_gen::RGroup> model, std::shared_ptr<DataChangeMap> changeMap = nullptr) override;
        
        void saveModel(std::shared_ptr<core_gen::RGroup> model, std::shared_ptr<DataChangeMap> changeMap = nullptr) override;
        
        void saveModels(std::vector<std::shared_ptr<core_gen::RGroup>>& models, std::shared_ptr<DataChangeMap> changeMap = nullptr) override;
        
        std::shared_ptr<ObjectFetcher<core_gen::RGroup, IGroupDao>> allModels() override;
        
//        std::map<std::string, sqlite::Value> toDb(core_gen::RGroup& model) override;
//        
//        std::shared_ptr<core_gen::RGroup> toObject(sqlite::Cursor &cursor) override;
        
        std::shared_ptr<std::vector<std::shared_ptr<core_gen::RGroup>>> query(const std::vector<std::string> &column, const std::map<std::string, sqlite::Value> & where, const std::vector<std::string> &orderBy, size_t count = 0, size_t offset = 0) override;
        
        std::shared_ptr<core_gen::RGroup> objectByID(const std::string& id) override;
        
    protected:
        
        std::map<std::string, sqlite::Value> toDb(std::shared_ptr<core_gen::Model> model) override;
        
        std::shared_ptr<core_gen::Model> toObject(sqlite::Cursor &cursor) override;
        
    };
}