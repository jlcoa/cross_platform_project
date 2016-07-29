//
//  ApiHelper.hpp
//  core
//
//  Created by Steve Chen on 2/19/16.
//
//

#pragma once

#include "../interface/r_account.hpp"
#include "../interface/r_account_response.hpp"
#include "../interface/e_network_method.hpp"

#include "../interface/r_contact.hpp"
#include "../interface/r_contact_response.hpp"

#include "../interface/r_group.hpp"
#include "../interface/r_group_update_response.hpp"
#include "../interface/r_group_response.hpp"

#include "../network/future/future_type.hpp"

#include "./common/api_header_common.hpp"

#include "../network/http_client.hpp"

#include "../interface/r_upload_token.hpp"

#include "../interface/r_avatar_info.hpp"
#include "../interface/r_avatar_domain.hpp"


namespace core {
    
    class Api {
        
    private:
        
        template<class Response, class Param>
        static std::shared_ptr<Future<Response>> doRequest(core_gen::ENetworkMethod method, const std::string &uri, specificcallback<Response> xcallback, std::shared_ptr<Param> param = nullptr, const unordered_map<string, string> &header = {}) {
            
            std::shared_ptr<Future<Response>> result = std::make_shared<Future<Response>>();
            
            std::shared_ptr<core_gen::RNetworkRequest>  request = nullptr;
            if (param) {
                request = HttpClient::buildRequest(method, uri, header, *param);
            }
            else {
                request = HttpClient::buildRequest(method, uri, header);
            }
            
            HttpClient::performRequest(request, xcallback, result);
            
            return result;
        }
        
        template<class Response>
        static std::shared_ptr<Future<Response>> doRequest(core_gen::ENetworkMethod method, const std::string &uri, specificcallback<Response> xcallback, const unordered_map<string, string> &header = {}) {
            
            return Api::doRequest<Response, core_gen::RAccount>(method, uri, xcallback, nullptr, header);
        }
        
    public:
        
        //account
        static std::shared_ptr<Future<core_gen::RAccountResponse>> login(std::shared_ptr<core_gen::RAccount> account, specificcallback<core_gen::RAccountResponse> xcallback);
        
        static std::shared_ptr<Future<core_gen::RAccountResponse>> signUp(std::shared_ptr<core_gen::RAccount> account, specificcallback<core_gen::RAccountResponse> xcallback);
        
        
        //contact
        static std::shared_ptr<Future<core_gen::RContactResponse>> syncContact(specificcallback<core_gen::RContactResponse> xcallback);
        
        //group
        static std::shared_ptr<Future<core_gen::RGroupResponse>> syncGroup(specificcallback<core_gen::RGroupResponse> xcallback);
        
        static std::shared_ptr<Future<core_gen::RGroup>> creatGroup(std::shared_ptr<core_gen::RGroup> group, specificcallback<core_gen::RGroup> xcallback);
        
        static std::shared_ptr<Future<core_gen::RGroupUpdateResponse>> updateGroup(const std::string& groupId, std::shared_ptr<core_gen::RGroup> group, specificcallback<core_gen::RGroupUpdateResponse> xcallback);
        
        static std::shared_ptr<Future<core_gen::RGroup>> addGroupMember(const std::vector<std::string> &memberIds, const std::string& groupId, specificcallback<core_gen::RGroup> xcallback);
        
        static std::shared_ptr<Future<core_gen::RGroup>> deleteGroupMember(const std::vector<std::string> &memberIds, const std::string& groupId, specificcallback<core_gen::RGroup> xcallback);
        
        static std::shared_ptr<Future<core_gen::RGroup>> deleteGroup(const std::string& groupId, specificcallback<core_gen::RGroup> xcallback);
        
        //updata avatar
        static std::shared_ptr<Future<core_gen::RUploadToken>> getUploadToken(specificcallback<core_gen::RUploadToken> xcallback);
        
        static std::shared_ptr<Future<core_gen::RAvatarInfo>> updateAvata(std::shared_ptr<core_gen::RAvatarInfo> avatarInfo, specificcallback<core_gen::RAvatarInfo> xcallback);
        
        static std::shared_ptr<Future<core_gen::RAvatarDomain>> getAvatarDomain(specificcallback<core_gen::RAvatarDomain> xcallback);
        
    };
    
}
