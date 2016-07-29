//
//  http_client.hpp
//  core
//
//  Created by Steve Chen on 12/15/15.
//  Copyright © 2015 Steve Chen. All rights reserved.
//

#pragma once

#include <map>
#include "../core/task_dispatcher.hpp"
#include "../interface/i_network_callback.hpp"
#include "../interface/r_network_request.hpp"
#include "./common/api_header_common.hpp"

#include "../interface/e_error_type.hpp"
#include "./common/type_parser.hpp"
#include "./future/future_type.hpp"
#include "./common/constants.hpp"
#include "../interface/r_future_error.hpp"

#include "./json/serialization_json.hpp"

#include <string>
#include <stdio.h>

#include "../utils/base64/Base64.hpp"

namespace core {
    
    using namespace std;
    
    using namespace core_gen;
    
    const char* const kTagHttpClient = "HttpClient";
    
    struct AuthContext {
    public:
        string m_authorization;
        AuthContext(const string &authorization = ""):m_authorization{authorization}{};
    };
    
    
    class HttpClient: public enable_shared_from_this<HttpClient> {
        
    public:
        HttpClient(shared_ptr<RNetworkRequest> request): m_request(request) {};
//        static shared_ptr<HttpClient> request(const ENetworkMethod httpMethod, const string &path, const string& data, const unordered_map<string, string> &header);
////
//        shared_ptr<HttpClient> setOnSuccess(RestApiCallback onSuccess) { m_onSuccess = onSuccess; return shared_from_this();};
//        shared_ptr<HttpClient> setOnFailure(RestApiCallback onFailure) { m_onFailure = onFailure; return shared_from_this();};
        
        static void setAuthContext(const shared_ptr<AuthContext> authContext) {
            s_authContext = authContext;
        };
        
        void execute(RestApiCallback callback);
        
        void onHandleResponse(shared_ptr<RNetworkResponse> response);
        
        static shared_ptr<RNetworkRequest> buildRequest(const ENetworkMethod httpMethod, const string &path, const string& body, const unordered_map<string, string> &header) {
            
            std::unordered_map<string, string> finalHeader = header;
            
            
            string auth;
            if (nullptr == s_authContext) {
                auth = "iOS_client:cfd8b9e61931250b7374585eec91d59035b44d13fe465f910ff1962c1dbb8e0f";
                const unsigned char *input = (unsigned char *)auth.c_str();
                unsigned inputlength = (unsigned)strlen(auth.c_str());
                auth = "Basic " + base64_encode(input, inputlength, false);
                
            }
            else {
                auth = "Bearer " + s_authContext->m_authorization;
            }
            
            finalHeader.insert({"Authorization", auth});
            finalHeader.insert({"Content-Type", "application/json"});
            
            shared_ptr<RNetworkRequest> xrequest = make_shared<RNetworkRequest>(1,
                                                                                s_baseUrl,
                                                                                path,
                                                                                httpMethod,
                                                                                finalHeader,
                                                                                body);
            return xrequest;
        }
        
        
        template<typename...Parameters>
        static shared_ptr<RNetworkRequest> buildRequest(const ENetworkMethod httpMethod, const string &url, const unordered_map<string, string> &header, const Parameters... parameters) {
            std::string body = toJsonString(parameters...);
            return buildRequest(httpMethod, url, body, header);
        };
        
        template<typename Type, typename...Parameters>
        static void performRequest(
                              shared_ptr<RNetworkRequest> request,
                              specificcallback<Type> callback,
                              std::shared_ptr<Future<Type>> result,
                              Parameters... parameters
                              ) {
            
            specificcallback<Type> wrapper = [result, callback](std::shared_ptr<Type> value, std::shared_ptr<RFutureError> error, const std::shared_ptr<RNetworkResponse> response) {
                result->setResult(value, error, response);
                if(callback)
                    callback(value, error, response);
            };
            
            RestApiCallback scb = [wrapper](const shared_ptr<RNetworkResponse> response){
                shared_ptr<RFutureError> error = make_shared<RFutureError>();
                shared_ptr<vector<uint8_t>> content = make_shared<vector<uint8_t>>();
                bool result = TypeParser<vector<uint8_t>>()(response->status, response, *content, *error);
                if (false == result) {
                    wrapper(nullptr, error, nullptr);
                } else {
                    shared_ptr<Type> value = make_shared<Type>();
                    result = TypeParser<Type>()(response->status, response, *value, *error);
                    if (result)
                        wrapper(value, nullptr, response);
                    else
                        wrapper(nullptr, error, response);
                }
            };
  
            make_shared<HttpClient>(request)->execute(scb);
        };

        
        
        
    private:
        static std::shared_ptr<AuthContext> s_authContext;
//
        static string s_baseUrl;
//
//        static XNetworkRequest buildRequest(const NetworkMethod httpMethod, const string &url, const unordered_map<string, string>& parameters={}, const string& body = "", const unordered_map<string, string>& header={});
//        
//        RestApiCallback m_onSuccess;
//        RestApiCallback m_onFailure;
        
        
        shared_ptr<RNetworkRequest> m_request;
        
        RestApiCallback m_callback;
        
        
        class HttpCallbackImpl final : public INetworkCallback {
        public:
            HttpCallbackImpl(const shared_ptr<HttpClient> httpClient): m_httpClient{httpClient} {};
            
            void handleResponse(const RNetworkResponse& response) {
                auto responsePtr = make_shared<RNetworkResponse>(std::move(response));
                m_httpClient->onHandleResponse(responsePtr);
                
            }
            
            void onSuccess(int64_t requestID, const RNetworkResponse & response) override {
//                LOG_DEBUG_F(kTagHttpClient, "onSucess", KV(response.data));
//                    if (m_httpClient->m_request->getOnSucess() != NULL) {
//                        m_httpClient->m_request->getOnSucess()(response);
//                    }
                handleResponse(response);
            };
            
            void onFailure(int64_t requestID, const RNetworkResponse & response) override {
//                LOG_DEBUG_F(kTagHttpClient, "onFailure");
//                if (m_httpClient->m_request->getOnFailure() != NULL) {
//                    m_httpClient->m_request->getOnFailure()(response);
//                }
                handleResponse(response);
            };
            
            /** For uploading/downloading tasks only */
            void onProgress(int64_t requestID, int32_t max_size, int32_t current_pos) override {};
            
        private:
            const shared_ptr<HttpClient> m_httpClient;
        };
        
       
    };
    
    
    
    
}
