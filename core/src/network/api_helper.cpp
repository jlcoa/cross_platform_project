//
//  ApiHelper.cpp
//  core
//
//  Created by Steve Chen on 2/19/16.
//
//

#include "api_helper.hpp"

#include "../core/pal.hpp"


namespace core {
    
    //login
    std::shared_ptr<Future<core_gen::RAccountResponse>> Api::login(std::shared_ptr<core_gen::RAccount> account, specificcallback<core_gen::RAccountResponse> xcallback) {
        return Api::doRequest(core_gen::ENetworkMethod::POST, "oauth/token", xcallback, account);
    }
    
    
    //    NSDictionary *parameters = @{@"username": acc.userName, @"password":acc.password, @"firstName":acc.firstName, @"lastName": acc.lastName};
//    
//    [RestAPIHelper POST:@"users" parameters:parameters parseBlock:^id(id responseObject) {
//     return account;
//     } callback:cb];

    
    std::shared_ptr<Future<core_gen::RAccountResponse>> Api::signUp(std::shared_ptr<core_gen::RAccount> account, specificcallback<core_gen::RAccountResponse> xcallback) {
        return Api::doRequest(core_gen::ENetworkMethod::POST, "users", xcallback, account);
    }
    
    //contact
    std::shared_ptr<Future<core_gen::RContactResponse>> Api::syncContact(specificcallback<core_gen::RContactResponse> xcallback) {
        return Api::doRequest(core_gen::ENetworkMethod::GET, "contacts", xcallback);
    }
    
    //group
    std::shared_ptr<Future<core_gen::RGroupResponse>> Api::syncGroup(specificcallback<core_gen::RGroupResponse> xcallback) {
        return Api::doRequest(core_gen::ENetworkMethod::GET, "groups", xcallback);
    }
    
    std::shared_ptr<Future<core_gen::RGroup>> Api::creatGroup(std::shared_ptr<core_gen::RGroup> group, specificcallback<core_gen::RGroup> xcallback) {
        return Api::doRequest(core_gen::ENetworkMethod::POST, "groups", xcallback, group);
    }
    
    std::shared_ptr<Future<core_gen::RGroupUpdateResponse>> Api::updateGroup(const std::string& groupId,std::shared_ptr<core_gen::RGroup> group, specificcallback<core_gen::RGroupUpdateResponse> xcallback) {
        return Api::doRequest(core_gen::ENetworkMethod::POST, "groups/" + groupId, xcallback, group);
    }
    
    std::shared_ptr<Future<core_gen::RGroup>> Api::addGroupMember(const std::vector<std::string> &memberIds, const std::string& groupId, specificcallback<core_gen::RGroup> xcallback) {
        
        std::shared_ptr<core_gen::RGroup> group = std::make_shared<core_gen::RGroup>();
        group->userIds = memberIds;
        
        return Api::doRequest(core_gen::ENetworkMethod::POST, "groups/" + groupId + "/users", xcallback, group);
    }
    
    std::shared_ptr<Future<core_gen::RGroup>> Api::deleteGroupMember(const std::vector<std::string> &memberIds, const std::string& groupId, specificcallback<core_gen::RGroup> xcallback) {
        
        std::shared_ptr<core_gen::RGroup> group = std::make_shared<core_gen::RGroup>();
        group->userIds = memberIds;
        
        return Api::doRequest(core_gen::ENetworkMethod::DELETE, "groups/" + groupId + "/users", xcallback, group);
    }
    
    std::shared_ptr<Future<core_gen::RGroup>> Api::deleteGroup(const std::string& groupId, specificcallback<core_gen::RGroup> xcallback) {
        return Api::doRequest(core_gen::ENetworkMethod::DELETE, "groups/" + groupId, xcallback);
    }
    
    std::shared_ptr<Future<core_gen::RUploadToken>> Api::getUploadToken(specificcallback<core_gen::RUploadToken> xcallback) {
        return Api::doRequest(core_gen::ENetworkMethod::GET, "avatar/uploadToken", xcallback);
    }
    
    std::shared_ptr<Future<core_gen::RAvatarInfo>> Api::updateAvata(std::shared_ptr<core_gen::RAvatarInfo> avatarInfo,  specificcallback<core_gen::RAvatarInfo> xcallback) {
        return Api::doRequest(core_gen::ENetworkMethod::POST, "avatar/url", xcallback, avatarInfo);
    }
    
    std::shared_ptr<Future<core_gen::RAvatarDomain>> Api::getAvatarDomain(specificcallback<core_gen::RAvatarDomain> xcallback) {
        return Api::doRequest(core_gen::ENetworkMethod::GET, "avatar/domain", xcallback);
    }
}
