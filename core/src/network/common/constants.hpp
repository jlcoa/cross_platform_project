/*
 * Copyright (c) 2015 RingCentral Inc. All rights reserved.
 *
 * @Author jerry.cai
 */

#pragma once

#include <string>
#include "../../interface/e_error_type.hpp"

#include <memory>
#include <vector>
#include <functional>

#include "../../interface/r_future_error.hpp"
#include "../json/serialization_json.hpp"
#include "../../core/pal.hpp"
#include "../../interface/r_network_response.hpp"

typedef std::function<void(std::shared_ptr<core_gen::RNetworkResponse>)> RestApiCallback;

namespace core {
    
    class ContentType {
    public:
        static std::string text() {return "text/plain";};
        static std::string json() {return "application/json";}
        static std::string xml() {return "application/xml";}
        static std::string multipart_mixed() {return "multipart/mixed";}
        static std::string x_www_form_urlencoded() {return "application/x-www-form-urlencoded;charset=UTF-8";}
        static std::string pdf() {return "application/pdf";}
    };
    
    class HttpHeaderKey {
    public:
        static std::string content_type() {return "Content-Type";}
        static std::string accept() { return "Accept";}
        static std::string accpet_lanaguage() { return "Accept-Language";}
        static std::string host() {return "Host";}
        static std::string user_agent() {return "User-agent";}
        static std::string authorization() {return "Authorization";}
        static std::string if_none_match() {return "If-None-Match";}
        static std::string accept_encoding() {return "Accept-Encoding";}
        static std::string& user_agent_value()
        {
            static std::string  _agent_value;
            return _agent_value;
        }
    };
    
    class HttpMethodValue {
    public:
        static std::string method_delete() {return "DELETE";}
        static std::string method_get() {return "GET";}
        static std::string method_post() {return "POST";}
        static std::string method_put() {return "PUT";}
        static std::string method_unknow() {return "UNKNOWN";}
    };
    
    class Key {
    public:
        static std::string accessToken() {return "accessToken";}
        static std::string refreshToken() {return "refreshToken";}
        static std::string basicAccessToken() {return "basicAccessToken";}
    };
    
    // SC: Server Code
    enum HttpCode {
        SC_OK = 200,
        SC_NO_CONTENT = 204,
        SC_BAD_REQUEST = 400,
        SC_UNAUTHORIZED = 401,
        SC_FORBIDDEN = 403,
        SC_NOT_FOUND = 404,
        SC_TIMEOUT = 408,
        SC_TOO_MANAY_REQUESTS = 429,
        SC_INTERNAL_SERVER_ERROR = 500,
        SC_BAD_GATEWAY = 502,
        SC_SERVICE_UNAVAILABLE = 503,
        SC_GATEWAY_TIMEOUT = 504,
        SC_OTHER_4XX,
        SC_OTHER_5XX,
    };
    
}
