//
//  data_provider.cpp
//  core
//
//  Created by Steve Chen on 2/21/16.
//
//

#include "data_provider.hpp"
#include "../interface/i_data_provider.hpp"
#include "../interface/i_data_change_delegate.hpp"
#include "../dao/i_contact_dao.hpp"
#include "../dao/i_group_dao.hpp"

#include "../service/i_contact_service.hpp"

namespace core {
    
    void DataProvider::makesureInited() {
        if (m_inited) {
            return;
        }
        
        m_inited = true;
        
        auto unifiedFactroy = m_unifedFactroy.lock();
        auto notificationService = unifiedFactroy->getBizServiceFactory()->getService<IDataChangeNotificationService>();
        notificationService->subscribe<core_gen::RContact>(shared_from_this());
        notificationService->subscribe<core_gen::RGroup>(shared_from_this());
    }
    
    bool DataProvider::hasGroup(const std::string & id) {
        makesureInited();
        
        auto unifiedFactroy = m_unifedFactroy.lock();
        auto dao = unifiedFactroy->getDaoFactory()->getDao<IGroupDao>();
        bool groupExist = dao->objectByID(id) != nullptr;
        
        if (!groupExist) {
            unKnownGroupIdSet.insert(id);
            unifiedFactroy->getBizServiceFactory()->getService<IContactService>()->syncGroup();
        }
        
        return groupExist;
    }
    
    bool DataProvider::hasContact(const std::string & id) {
        makesureInited();
        
        auto unifiedFactroy = m_unifedFactroy.lock();
        auto dao = unifiedFactroy->getDaoFactory()->getDao<IContactDao>();
        
        bool contactExist = dao->objectByID(id) != nullptr;
        if (!contactExist) {
            unKnownContactIdSet.insert(id);
            unifiedFactroy->getBizServiceFactory()->getService<IContactService>()->syncContact();
        }
        return contactExist;
    }
    
    core_gen::RContact DataProvider::getContact(const std::string & id) {
        auto unifiedFactroy = m_unifedFactroy.lock();
        auto dao = unifiedFactroy->getDaoFactory()->getDao<IContactDao>();
        return * (dao->objectByID(id));
    }
    
    core_gen::RGroup DataProvider::getGroup(const std::string & id) {
        auto unifiedFactroy = m_unifedFactroy.lock();
        auto dao = unifiedFactroy->getDaoFactory()->getDao<IGroupDao>();
        return * (dao->objectByID(id));
    }
    
    void DataProvider::onDataChanged(const string &modelName, shared_ptr<ModelChangeTypeMap> changeMap) {
        if (typeid(core_gen::RGroup).name() == modelName) {
            for (auto iter = changeMap->begin(); iter != changeMap->end(); iter ++) {
                for (auto modelIter = iter->second->begin(); modelIter != iter->second->end(); modelIter ++) {
                    auto group = std::dynamic_pointer_cast<core_gen::RGroup>(*modelIter);
                    auto targetIter = unKnownGroupIdSet.find(*group->id);
                    if (targetIter !=unKnownGroupIdSet.end()) {
                        if (m_delegate) {
                            m_delegate->onGroupChanged(*group);
                            unKnownGroupIdSet.erase(targetIter);
                        }
                    }
                }
            }
        }
        
        else if (typeid(core_gen::RContact).name() == modelName) {
            for (auto iter = changeMap->begin(); iter != changeMap->end(); iter ++) {
                for (auto modelIter = iter->second->begin(); modelIter != iter->second->end(); modelIter ++) {
                    auto model = std::dynamic_pointer_cast<core_gen::RContact>(*modelIter);
                    auto targetIter = unKnownContactIdSet.find(*model->id);
                    if (targetIter !=unKnownContactIdSet.end()) {
                        if (m_delegate) {
                            m_delegate->onContactChanged(*model);
                            unKnownContactIdSet.erase(targetIter);
                        }
                        
                    }
                }
            }
        }
        
    }
    
    void DataProvider::setDelegate(const std::shared_ptr<core_gen::IDataChangeDelegate> &delegate) {
        m_delegate = delegate;
    }
}