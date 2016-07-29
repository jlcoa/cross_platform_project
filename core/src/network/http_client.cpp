//
//  http_client.cpp
//  GlipCore
//
//  Created by Steve Chen on 12/15/15.
//  Copyright © 2015 RingCentral. All rights reserved.
//

#include "http_client.hpp"
#include "stl.hpp"

#include "../core/pal.hpp"
#include "../interface/i_network_provider.hpp"

namespace core {
    
    shared_ptr<AuthContext> HttpClient::s_authContext = nullptr;
    
    string HttpClient::s_baseUrl = "http://nextucdev.duapp.com/api/v1/";
    
//    shared_ptr<HttpClient> HttpClient::request(const NetworkMethod httpMethod, const string &url, const unordered_map<string, string> &parameters, const string& body, const unordered_map<string, string> &header) {
//        shared_ptr<HttpClient> httpClient = make_shared<HttpClient>();
//        
//        auto httpCallback = make_shared<HttpCallbackImpl>(httpClient);
//        getPalBundle()->getNetworkProvider()->request(buildRequest(httpMethod, url, parameters, body, header), httpCallback);
//        
//        return httpClient;
//    }
    
    void HttpClient::onHandleResponse(shared_ptr<core_gen::RNetworkResponse> response) {
        m_callback(response);
    }
    
    void HttpClient::execute(RestApiCallback callback) {
        m_callback = callback;
        
        auto httpCallback =  make_shared<HttpCallbackImpl>(shared_from_this());
        getPal()->getNetworkProvider()->request(*m_request, httpCallback);
    }
    
//    XNetworkRequest HttpClient::buildRequest(const NetworkMethod httpMethod, const string &url, const unordered_map<string, string> &parameters, const string& body, const unordered_map<string, string> &header) {
//        
//        unordered_map<string, string> finalParameter = parameters;
//        if (!s_authContext.m_x_authorization.empty()) {
//            finalParameter.insert({"tk", ""});
//        }
//        
//        XNetworkRequest request(0,
//                             s_baseUrl,
//                                url,
//                             httpMethod,
//                             header,
//                             finalParameter,
//                             body);
//        return request;
//    }
    
}