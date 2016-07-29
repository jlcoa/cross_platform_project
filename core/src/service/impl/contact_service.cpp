//
//  contact_service.cpp
//  core
//
//  Created by Steve Chen on 2/14/16.
//
//

#include "contact_service.hpp"

#include "../../core/pal.hpp"

#include "../../network/http_client.hpp"

#include "../../interface/r_contact_response.hpp"

#include "../../app/unified_factory.hpp"
#include "../../dao/i_contact_dao.hpp"
#include "../../network/api_helper.hpp"

#include "../../interface/r_group.hpp"
#include "../../interface/r_group_response.hpp"

#include "../../dao/i_group_dao.hpp"
#include "../../dao/i_group_member_dao.hpp"

#include "../i_account_service.hpp"

namespace core {
    
    void ContactService::syncContact() {
        
        if (m_syncingContact) {
            return;
        }
        
        m_syncingContact = true;
        
        auto self = std::enable_shared_from_this<ContactService>::shared_from_this();
        
        specificcallback<core_gen::RContactResponse> xcallback = [self](std::shared_ptr<core_gen::RContactResponse> data,
                                                                     std::shared_ptr<core_gen::RFutureError> error,
                                                                     const std::shared_ptr<core_gen::RNetworkResponse> response) {
            
            if (error) {
                
            }
            else {
                
                self->storeData([self, data](std::shared_ptr<DataChangeMap> changeMap) {
                    
                    auto uf = self->m_unifiedFactory.lock();
                    auto dao = uf->getDaoFactory()->getDao<IContactDao>();
                    if (data->contacts) {
                        for (auto model : *data->contacts) {
                            dao->saveModel(std::make_shared<core_gen::RContact>(model), changeMap);
                        }
                    }

                });

            }
            
            dispatchToUI([self] {
                self->m_syncingContact = false;
            });
            
        };
        Api::syncContact(xcallback);
        
    }
    
    void ContactService::syncGroup() {
        
        if (m_syncingGroup) {
            return;
        }
        
        m_syncingGroup = true;
        
        auto self = std::enable_shared_from_this<ContactService>::shared_from_this();
        
        specificcallback<core_gen::RGroupResponse> xcallback = [self](std::shared_ptr<core_gen::RGroupResponse> data,
                                                                     std::shared_ptr<core_gen::RFutureError> error,
                                                                     const std::shared_ptr<core_gen::RNetworkResponse> response) {
            
            if (error) {
                
            }
            else {
                
                self->storeData([self, data](std::shared_ptr<DataChangeMap> changeMap) {
                    auto uf = self->m_unifiedFactory.lock();
                    auto dao = uf->getDaoFactory()->getDao<IGroupDao>();
                    if (data->groups) {
                        for (auto model : *data->groups) {
                            dao->saveModel(std::make_shared<core_gen::RGroup>(model), changeMap);
                        }
                    }
                });
            }
            
            dispatchToUI([self] {
                self->m_syncingGroup = false;
            });
            
        };
        Api::syncGroup(xcallback);
    }
    
    std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> ContactService::allContacts() {
        auto dao = m_unifiedFactory.lock()->getDaoFactory()->getDao<IContactDao>();
        return dao->allContacts();
    }
    
    std::shared_ptr<ObjectFetcher<core_gen::RGroup, IGroupDao>> ContactService::allGroups() {
        auto dao = m_unifiedFactory.lock()->getDaoFactory()->getDao<IGroupDao>();
        
        auto objectFetcher = dao->allModels();
        objectFetcher->initNotification(m_unifiedFactory.lock()->getBizServiceFactory()->getService<IDataChangeNotificationService>());
        
        return objectFetcher;
    }
    
    std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> ContactService::groupMembers(std::shared_ptr<core_gen::RGroup> group) {
        auto dao = m_unifiedFactory.lock()->getDaoFactory()->getDao<IContactDao>();
        return dao->groupMembers(group);
    }
    
//    
//    void ContactService::updateGroup(std::shared_ptr<core_gen::RGroup> group, std::shared_ptr<CallbackResult<core_gen::RGroup>> responseCB, std::function<void()> func) {
//        
//        specificcallback<core_gen::RGroup> xcallback = [=](std::shared_ptr<core_gen::RGroup> data,
//                                                           std::shared_ptr<core_gen::RFutureError> error,
//                                                           const std::shared_ptr<core_gen::RNetworkResponse> response) {
//            
//            if (error) {
//                
//                dispatchToUI([=]() {
//                    responseCB->result = core_gen::ECallbackResult::FAILURE;
//                    responseCB->callback(groupPtr);
//                    
//                });
//            }
//            else {
//                auto uf = m_unifiedFactory.lock();
//                auto dao = uf->getDaoFactory()->getDao<IGroupDao>();
//                dao->save(*data);
//                
//                dispatchToUI([=]() {
//                    responseCB->result = core_gen::ECallbackResult::SUCCESS;
//                    responseCB->callback(data);
//                    
//                });
//                
//            }
//            
//        };
//        
//        Api::creatGroup(groupPtr, xcallback);
//        
//    }
    
    void ContactService::createGroup(const std::vector<core_gen::RContact> & contacts, std::shared_ptr<CallbackResult<core_gen::RGroup>> responseCB) {
        
        auto groupPtr = std::make_shared<core_gen::RGroup>();
        
        groupPtr->groupType = core_gen::RGroup::TYPE_GROUP;
        
        std::string groupName = "";
        
        std::vector<std::string> userIds;
        
        for (auto iter = contacts.begin(); iter != contacts.end(); iter ++) {
            
            groupName += *iter->displayName;
            
            if (iter != --contacts.end()) {
                groupName += ", ";
            }
            
            userIds.push_back(*(iter->id));
        }
        groupPtr->groupName = groupName;
        groupPtr->userIds = userIds;
        
        auto self = std::enable_shared_from_this<ContactService>::shared_from_this();
        
        specificcallback<core_gen::RGroup> xcallback = [self, responseCB, groupPtr](std::shared_ptr<core_gen::RGroup> data,
                                                           std::shared_ptr<core_gen::RFutureError> error,
                                                           const std::shared_ptr<core_gen::RNetworkResponse> response) {
            
            auto result = std::make_shared<core_gen::RActionResult>();
            responseCB->result = result;
            
            if (error) {
                result->result  = core_gen::ECallbackResult::FAILURE;
                dispatchToUI([responseCB, groupPtr, result]() {
                    responseCB->callback(groupPtr);
                    
                });
            }
            else {
                result->result  = core_gen::ECallbackResult::SUCCESS;
                self->storeData([self, data, responseCB](std::shared_ptr<DataChangeMap> changeMap) {
                    
                    auto uf = self->m_unifiedFactory.lock();
                    auto dao = uf->getDaoFactory()->getDao<IGroupDao>();
                    
                    dao->saveModel(data, changeMap);
                    
                    dispatchToUI([responseCB, data]() {
                        responseCB->callback(data);
                        
                    });
                    
                });
                
            }
            
        };
        
        Api::creatGroup(groupPtr, xcallback);
        
    }
    
    void ContactService::updateGroupName(std::shared_ptr<core_gen::RGroup> group, const std::string &groupName, std::shared_ptr<CallbackResult<core_gen::RGroup>> responseCB) {
        
        auto self = std::enable_shared_from_this<ContactService>::shared_from_this();
        
        specificcallback<core_gen::RGroupUpdateResponse> xcallback = [self, responseCB, group](std::shared_ptr<core_gen::RGroupUpdateResponse> data,
                                                           std::shared_ptr<core_gen::RFutureError> error,
                                                           const std::shared_ptr<core_gen::RNetworkResponse> response) {
            auto result = std::make_shared<core_gen::RActionResult>();
            responseCB->result = result;
            
            if (error) {
                
                result->result  = core_gen::ECallbackResult::FAILURE;
                
                dispatchToUI([group, responseCB]() {
                    responseCB->callback(group);
                    
                });
            }
            else {
                
                result->result  = core_gen::ECallbackResult::SUCCESS;
                
                self->storeData([self, data, responseCB](std::shared_ptr<DataChangeMap> changeMap) {
                    
                    auto uf = self->m_unifiedFactory.lock();
                    auto dao = uf->getDaoFactory()->getDao<IGroupDao>();
                    
                    auto model = data->group;
                    
                    auto updatedGroup = std::make_shared<core_gen::RGroup>(*model);
                    
                    dao->saveModel(updatedGroup, changeMap);
                    
                    dispatchToUI([responseCB, updatedGroup]() {
                        responseCB->callback(updatedGroup);
                        
                    });
                    
                });

            }
            
        };
        
        auto groupParameter = std::make_shared<core_gen::RGroup>();
        groupParameter->groupName = groupName;
        
        Api::updateGroup(*group->id, groupParameter, xcallback);
        
    }
    
    void ContactService::addMembers(const std::string &groupId, const std::vector<std::string> & memberIds, std::shared_ptr<CallbackResult<core_gen::RGroup>> responseCB) {
        
        auto groupParameter = std::make_shared<core_gen::RGroup>();
        groupParameter->userIds = memberIds;
        
        auto self = std::enable_shared_from_this<ContactService>::shared_from_this();
        
        specificcallback<core_gen::RGroup> xcallback = [self, groupParameter, responseCB](std::shared_ptr<core_gen::RGroup> data,
                                                                         std::shared_ptr<core_gen::RFutureError> error,
                                                                         const std::shared_ptr<core_gen::RNetworkResponse> response) {
            auto result = std::make_shared<core_gen::RActionResult>();
            responseCB->result = result;
            
            if (error) {
                result->result  = core_gen::ECallbackResult::FAILURE;
                
                dispatchToUI([groupParameter, responseCB]() {
                    responseCB->callback(groupParameter);
                });
                
            }
            else {
                result->result  = core_gen::ECallbackResult::SUCCESS;
                
                self->storeData([self, data, responseCB](std::shared_ptr<DataChangeMap> changeMap) {
                    
                    auto uf = self->m_unifiedFactory.lock();
                    auto dao = uf->getDaoFactory()->getDao<IGroupDao>();
                    
                    auto model = data;
                    dao->saveModel(model, changeMap);
                    
                    auto updatedGroup = model;
                    
                    dispatchToUI([responseCB, updatedGroup]() {
                        responseCB->callback(updatedGroup);
                        
                    });
                    
                });
                
            }
            
        };
        
        Api::addGroupMember(memberIds, groupId, xcallback);
    }
    
    void ContactService::removeMembers(const std::string &groupId, const std::vector<std::string> & memberIds,  std::shared_ptr<CallbackResult<core_gen::RGroup>> responseCB) {
        
        auto groupParameter = std::make_shared<core_gen::RGroup>();
        groupParameter->userIds = memberIds;
        
        bool containSelf = false;
        
        auto accountService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IAccountService>();
        auto accountInfor = accountService->getAccountInfo();
        auto accountUserId = *accountInfor->user.id;
        
        containSelf = std::find(memberIds.begin(), memberIds.end(), accountUserId) != memberIds.end();
        
        auto self = std::enable_shared_from_this<ContactService>::shared_from_this();
        specificcallback<core_gen::RGroup> xcallback = [self, groupParameter, groupId, memberIds, containSelf, responseCB](std::shared_ptr<core_gen::RGroup> data,
                                                           std::shared_ptr<core_gen::RFutureError> error,
                                                           const std::shared_ptr<core_gen::RNetworkResponse> response) {
            
            auto result = std::make_shared<core_gen::RActionResult>();
            responseCB->result = result;
            
            if (error) {
                result->result  = core_gen::ECallbackResult::FAILURE;
                
                dispatchToUI([self, groupParameter, responseCB]() {
                    responseCB->callback(groupParameter);
                    
                });
                
            }
            else {
                result->result  = core_gen::ECallbackResult::SUCCESS;
                self->storeData([self, data, groupId, memberIds, containSelf, responseCB](std::shared_ptr<DataChangeMap> changeMap) {
                    
                    auto uf = self->m_unifiedFactory.lock();
                    auto dao = uf->getDaoFactory()->getDao<IGroupDao>();
                    
                    auto model = data;
                    dao->saveModel(model, changeMap);
                    
                    auto groupMemberDao = uf->getDaoFactory()->getDao<IGroupMemberDao>();
                    groupMemberDao->removeMember4Group(groupId, memberIds);
                    
                    if (containSelf) {
                        dao->deleteModel(model, changeMap);
                    }
                    
                    auto updatedGroup = model;
                    
                    dispatchToUI([responseCB, updatedGroup]() {
                        responseCB->callback(updatedGroup);
                        
                    });
                    
                });
                
            }

        };
        
        dispatchToBG([self, containSelf, memberIds, groupId, accountUserId, xcallback](){
            
            bool isDeleteGroup = false;
            
            if (containSelf) {
                auto dao = self->m_unifiedFactory.lock()->getDaoFactory()->getDao<IGroupMemberDao>();
                isDeleteGroup = dao->isGroupAdminOrOwner(groupId, accountUserId);
            }
            
            if (isDeleteGroup) {
                Api::deleteGroup(groupId, xcallback);
            }
            else {
                Api::deleteGroupMember(memberIds, groupId, xcallback);
            }
            
        });
        
    }
    
    void ContactService::quitGroup(std::shared_ptr<core_gen::RGroup> group, std::shared_ptr<CallbackResult<core_gen::RActionResult>> responseCB) {
        
        auto tcallback = std::make_shared<CallbackResult<core_gen::RGroup>>();
        tcallback->callback = [responseCB, tcallback](std::shared_ptr<core_gen::RGroup> data) {
            responseCB->callback(tcallback->result);

        };
        
        auto accountService = m_unifiedFactory.lock()->getBizServiceFactory()->getService<IAccountService>();
        auto accountInfor = accountService->getAccountInfo();
        removeMembers(*group->id, {*accountInfor->user.id}, tcallback);
    }
}