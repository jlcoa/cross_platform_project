//
//  dao_factory.hpp
//  core
//
//  Created by Steve Chen on 2/13/16.
//
//

#pragma once

#include "../i_dao_factory.hpp"
#include "contact_dao.hpp"
#include "group_dao.hpp"
#include "group_member_dao.hpp"

namespace core {
    
    class DaoFactory: public IDaoFactory, public std::enable_shared_from_this<DaoFactory> {
        
    public:
        DaoFactory(std::weak_ptr<IUnifiedFactory> unifiedFactory):m_unifiedFactory{unifiedFactory} {};
        
        std::shared_ptr<IDao> getDao (std::string &key) override {
            auto daoIter = m_daoMap.find(key);
            return daoIter != m_daoMap.end()? daoIter->second : nullptr;
        };
        
//        std::shared_ptr<IDao> getDaoByModel(std::type_index type) override {
//            auto daoIter = m_modelDaoMap.find(type);
//            return daoIter != m_modelDaoMap.end()? daoIter->second : nullptr;
//        }
        
        void clear() override {
            m_dbProvider = nullptr;
            m_daoMap.clear();
        }
        
        void setupDb(const std::string &user) override {
            m_dbProvider = std::make_shared<DatabaseProvider>(user);
//            m_dbProvider->enableWal();
            
            registerDao<IContactDao, ContactDao>();
            
            registerDao<IGroupDao, GroupDao>();
            
            registerDao<IGroupMemberDao, GroupMemberDao>();
        };
        
    
    private:
        
        std::weak_ptr<IUnifiedFactory> m_unifiedFactory;
        std::shared_ptr<DatabaseProvider> m_dbProvider;
        std::map<std::string, shared_ptr<IDao>> m_daoMap;
        
//        std::map<std::type_index, shared_ptr<IDao>> m_modelDaoMap;
        
        template<class Inter, class Impl> void registerDao() {
            auto dao = std::make_shared<Impl>(shared_from_this());
            dao->onCreate(m_dbProvider);
            
            const std::string key = typeid(Inter).name();
            m_daoMap.insert({key, dao});
            
//            auto adao = std::dynamic_pointer_cast<AbstractDao>(dao);
//            m_modelDaoMap.insert({adao->getModelType(), dao});
        }
    };
    
}
