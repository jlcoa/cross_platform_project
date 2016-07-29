//
//  account_service.cpp
//  core
//
//  Created by Steve Chen on 2/13/16.
//
//

#include "account_service.hpp"

#include "../../core/pal.hpp"

#include "../../network/http_client.hpp"

#include "../../interface/r_account.hpp"

#include "../../app/unified_factory.hpp"
#include "../../dao/i_contact_dao.hpp"

#include "../../service/i_contact_service.hpp"

#include "../../network/api_helper.hpp"

#include "../../app/setting.hpp"

#include "../../interface/r_avatar_domain.hpp"

namespace core {
    
    void AccountService::initData() {
        
        const std::string userId = *(m_accountInfo->user.id);
        
        m_unifiedFactory.lock()->getDaoFactory()->setupDb(userId);
        
        auto authCtx = std::make_shared<AuthContext>(m_accountInfo->access_token);
        HttpClient::setAuthContext(authCtx);
    }
    
    void AccountService::login(shared_ptr<core_gen::RAccount> account, LoginCallback cb) {
        
        if (m_accountStatus == core_gen::EAccountStatus::NOT_LOGGED_IN) {
            specificcallback<core_gen::RAccountResponse> xcallback = [=](std::shared_ptr<core_gen::RAccountResponse> data,
                                                                         std::shared_ptr<core_gen::RFutureError> error,
                                                                         const std::shared_ptr<core_gen::RNetworkResponse> response) {
                
                if (error) {
                    
                    dispatchToUI([=]() {
                        m_accountStatus = core_gen::EAccountStatus::NOT_LOGGED_IN;
                        
                        notifyAccountStatusChanged();
                        
                        if (cb) {
                            cb(core_gen::ELoginStatus::FAILURE);
                        }
                        
                    });
                    
                }
                else {
                    auto uf = m_unifiedFactory.lock();
                    
                    m_accountInfo = data;
                    
                    Setting::globalSetting()->putString(Setting::KEY_USER, toJsonString(*m_accountInfo));
                    
                    initData();
                    
                    dispatchToUI([=]() {
                        
                        m_accountStatus = core_gen::EAccountStatus::LOGGED_IN;
                        
                        if (cb) {
                            cb(core_gen::ELoginStatus::SUCCESS);
                        }
                        
                        notifyAccountStatusChanged();
                        
                        handleLoggedIn();
                        
                    });
                }
                
            };
            
            m_accountStatus = core_gen::EAccountStatus::IN_PROGRESS;
            
            Api::login(account, xcallback);
        }
        
    }
    
    void AccountService::handleLoggedIn() {
        auto uf = m_unifiedFactory.lock();
        auto contactService = uf->getBizServiceFactory()->getService<IContactService>();
        contactService->syncContact();
        contactService->syncGroup();
    }
    
    void AccountService::notifyAccountStatusChanged() {
        
        notifyObserver4Change<IAccountServiceObserver>(m_accountObservers, [=](std::shared_ptr<IAccountServiceObserver> observer) {
            observer->onAccountStatusChanged(m_accountStatus);
        });
        
    }
    
    void AccountService::start() {
        
        auto user = Setting::globalSetting()->getString(Setting::KEY_USER);
        
        if (user) {
            
            auto account = std::make_shared<core_gen::RAccountResponse>();
            
            account->jdeserialize(stringToJson(*user));
            
            m_accountInfo = account;
            initData();
            m_accountStatus = core_gen::EAccountStatus::LOGGED_IN;
            
            handleLoggedIn();
        }
        else {
            m_accountStatus = core_gen::EAccountStatus::NOT_LOGGED_IN;
        }
        
        notifyAccountStatusChanged();
    }
    
    void AccountService::signout(std::shared_ptr<CallbackResult<core_gen::RActionResult> > responseCB) {
        
        m_accountInfo = nullptr;
        m_accountStatus = core_gen::EAccountStatus::NOT_LOGGED_IN;
        
        m_unifiedFactory.lock()->getDaoFactory()->clear();
        
        HttpClient::setAuthContext(nullptr);
        
        Setting::globalSetting()->deleteByKey(Setting::KEY_USER);
        
        notifyAccountStatusChanged();
        
        auto result = std::make_shared<core_gen::RActionResult>();
        result->result = core_gen::ECallbackResult::SUCCESS;
        responseCB->result = result;
        responseCB->callback(result);
    }
    
    void AccountService::signup(shared_ptr<core_gen::RAccount> account, std::shared_ptr<CallbackResult<core_gen::RActionResult>> responseCB) {
        
        auto self = shared_from_this();
        
        specificcallback<core_gen::RAccountResponse> xcallback = [self, responseCB](std::shared_ptr<core_gen::RAccountResponse> data,
                                                                                    std::shared_ptr<core_gen::RFutureError> error,
                                                                                    const std::shared_ptr<core_gen::RNetworkResponse> response) {
            
            auto result = std::make_shared<core_gen::RActionResult>();
            
            if (error && !error->parsingError) {
                
                result->result = core_gen::ECallbackResult::FAILURE;
                
                dispatchToUI([responseCB, result]() {
                    responseCB->result = result;
                    responseCB->callback(result);
                    
                });
            }
            else {
                result->result = core_gen::ECallbackResult::SUCCESS;
                
                dispatchToUI([responseCB, result]() {
                    responseCB->result = result;
                    responseCB->callback(result);
                    
                });
                
            }
            
        };
        
        
        Api::signUp(account, xcallback);
        
    }
    
    
    void AccountService::requestUploadToken(std::shared_ptr<CallbackResult<core_gen::RUploadToken>> responseCB) {
        
        auto self = shared_from_this();
        
        specificcallback<core_gen::RUploadToken> xcallback = [self, responseCB](std::shared_ptr<core_gen::RUploadToken> data,
                                                                                    std::shared_ptr<core_gen::RFutureError> error,
                                                                                    const std::shared_ptr<core_gen::RNetworkResponse> response) {
            
            auto result = std::make_shared<core_gen::RActionResult>();
            
            if (error && !error->parsingError) {
                
                result->result = core_gen::ECallbackResult::FAILURE;
                
                dispatchToUI([responseCB, result]() {
                    responseCB->result = result;
                    responseCB->callback(std::make_shared<core_gen::RUploadToken>());
                    
                });
            }
            else {
                result->result = core_gen::ECallbackResult::SUCCESS;
                
                dispatchToUI([responseCB, data, result]() {
                    responseCB->result = result;
                    responseCB->callback(data);
                });
            }
            
        };
        
        Api::getUploadToken(xcallback);
    }
    
    void AccountService::updateAvatar2Server(std::shared_ptr<core_gen::RAvatarInfo> avatar, std::shared_ptr<CallbackResult<core_gen::RAvatarInfo>> responseCB, const std::string &domain) {
        
        auto self = shared_from_this();
        
        specificcallback<core_gen::RAvatarInfo> xcallback = [self, responseCB](std::shared_ptr<core_gen::RAvatarInfo> data,
                                                                               std::shared_ptr<core_gen::RFutureError> error,
                                                                               const std::shared_ptr<core_gen::RNetworkResponse> response) {
            
            auto result = std::make_shared<core_gen::RActionResult>();
            
            if (error && !error->parsingError) {
                
                result->result = core_gen::ECallbackResult::FAILURE;
                
                dispatchToUI([responseCB, result]() {
                    responseCB->result = result;
                    responseCB->callback(std::make_shared<core_gen::RAvatarInfo>());
                    
                });
            }
            else {
                result->result = core_gen::ECallbackResult::SUCCESS;
    
                dispatchToUI([responseCB, data, result]() {
                    responseCB->result = result;
                    responseCB->callback(data);
                });
            }
            
        };
        
        avatar->avatarUrl = domain + *avatar->userId;
        Api::updateAvata(avatar, xcallback);
    }
    
    void AccountService::updateAvatar(std::shared_ptr<core_gen::RAvatarInfo> avatar, std::shared_ptr<CallbackResult<core_gen::RAvatarInfo> > responseCB) {
        
        auto self = shared_from_this();
        
        specificcallback<core_gen::RAvatarDomain> xcallback = [self, avatar, responseCB](std::shared_ptr<core_gen::RAvatarDomain> data,
                                                                                std::shared_ptr<core_gen::RFutureError> error,
                                                                                const std::shared_ptr<core_gen::RNetworkResponse> response) {
            
            auto result = std::make_shared<core_gen::RActionResult>();
            
            if (error && !error->parsingError) {
                
                result->result = core_gen::ECallbackResult::FAILURE;
                
                dispatchToUI([responseCB, result]() {
                    responseCB->result = result;
                    responseCB->callback(std::make_shared<core_gen::RAvatarInfo>());
                    
                });
            }
            else {
//                result->result = core_gen::ECallbackResult::SUCCESS;
                
                self->updateAvatar2Server(avatar, responseCB, *data->domain);
                
                
//                dispatchToUI([responseCB, data, result]() {
//                    responseCB->result = result;
//                    responseCB->callback(data);
//                });
            }
            
        };
        
//        Api::getUploadToken(xcallback);

        Api::getAvatarDomain(xcallback);
    }
    
}