
/*
 * Copyright (c) 2015 RingCentral Inc. All rights reserved.
 *
 * @Author easton.hou
 */


#include "type_parser.hpp"
#include "constants.hpp"

#include "string_algo.hpp"

using namespace std;
using namespace string_algo;

using namespace core_gen;

namespace core {
    
    EErrorType translateErrorType(ERequestResult code) {
        switch (code) {
            case ERequestResult::SUCCESS:
                return EErrorType::SUCCESS;
            case ERequestResult::NO_NETWORK:
                return EErrorType::NETWORK_FAILURE;
            case ERequestResult::TIMEOUT:
                return EErrorType::TIMEOUT;
            default:
                return EErrorType::UNKNOWN;
        }
    }
    
    void makeParsingError(RFutureError& e, const std::string& message) {
        e.type = EErrorType::PARSE_FAILURE;
        e.parsingError = RParsingError(message);
        e.generalMessage = message;
    }
    
    string decodeString(std::shared_ptr<RNetworkResponse> response) {
        auto data = response->data;
        return string(data.begin(), data.end());
    }
    
    bool expectRequestResultSuccessful(ERequestResult requestResult, RFutureError& error) {
        if (ERequestResult::SUCCESS == requestResult)
            return true;
        error.type = translateErrorType(requestResult);
        error.generalMessage = string("no response from server");
        return false;
    }
    
    bool expectJsonResponse(std::shared_ptr<RNetworkResponse> response, json11::Json& value, RFutureError& error) {
        if (icontains(response->content_type, ContentType::json())) {
            string content = decodeString(response);
            string e;
            value = json11::Json::parse(content, e);
            if (e.empty())
                return true;
            else {
                makeParsingError(error, e);
                return false;
            }
        } else {
            makeParsingError(error, "expecting application/json, current is " + response->content_type);
            return false;
        }
    }
    
    bool expectJsonNoServerError(const json11::Json& , RFutureError& ) {
//        RServerError serverError;
        try {
//            serverError.jdeserialize(json);
//            bool case1 = (serverError.parameter || serverError.parameterName) && serverError.errorCode;
//            bool case2 = serverError.error && serverError.error_description;
//            if (case1 || case2) {
//                error.type = ErrorType::SERVER_FAILURE;
//                error.serverError = serverError;
//                if (case1)
//                    error.generalMessage = serverError.message;
//                else
//                    error.generalMessage = serverError.error_description;
//                return false;
//            } else
                return true;
        } catch (const JsonMissingKey&) {
            return true;
        }
    }
    
    bool expectNoServerError(std::shared_ptr<RNetworkResponse> response, RFutureError& error) {
        if (nullptr == response)
        {
            error.type = EErrorType::NETWORK_FAILURE;
            error.networkError = RNetworkError(-1);
            error.generalMessage = (std::string)"network failure: no response";
            return false;
        }
        if (200 > response->code || 300 <= response->code) {
            json11::Json json;
            if (expectJsonResponse(response, json, error)) {
//                error.serverError = ServerError();
//                error.type = ErrorType::SERVER_FAILURE;
//                error.generalMessage = "error code: " + string_algo::to_string(response->getHttpCode()) + "\r\ncontent:\r\n" + decodeString(response);
                if (expectJsonNoServerError(json, error)) {
//                    error.serverError.value().message = error.generalMessage;
                }
            }
            else {
//                error.type = ErrorType::NETWORK_FAILURE;
//                error.networkError = NetworkError(response->getHttpCode());
//                error.generalMessage = "network failure: " + string_algo::to_string(response->getHttpCode());
            }
            return false;
        }
        return true;
    }
    
    bool expectMultiMixed(std::shared_ptr<RNetworkResponse> response, std::vector<HttpContent>& contents, RFutureError& error) {
        string contentType = response->content_type;
        
        if (false == icontains(contentType, ContentType::multipart_mixed())) {
            makeParsingError(error, "expecting multipart/mixed, current is " + response->content_type);
            return false;
        }
        string text = decodeString(response);
        contents.clear();
        auto boundaryStart = ifind_after(contentType.begin(), contentType.end(), "boundary=");
        string boundary;
        if (contentType.end() == boundaryStart) {
            if (istartsWith(text, "--Boundary")) {
                string lineFeed = "\r\n";
                auto boundaryEnd = search(text.begin(), text.end(), lineFeed.begin(), lineFeed.end());
                if (text.end() != boundaryEnd) {
                    boundary = string(text.begin(), boundaryEnd);
                }
            }
            if (boundary.empty()) {
                makeParsingError(error, "no boundary found");
                return false;
            }
        } else
            boundary = "--" + string(boundaryStart, contentType.end());
        auto position = find_after(text.begin(), text.end(), boundary);
        while (text.end() != position) {
            auto typeBegin = ifind_after(position, text.end(), "Content-Type: ");
            auto contentBegin = find_after(typeBegin, text.end(), "\r\n");
            auto contentEnd = search(contentBegin, text.end(), boundary.begin(), boundary.end());
            if (text.end() != contentEnd) {
                auto typeEnd = contentBegin - 2;
                HttpContent c;
                c.type = string(typeBegin, typeEnd);
                c.content = string(contentBegin, contentEnd);
                contents.push_back(c);
            }
            position = find_after(contentEnd, text.end(), boundary);
        }
        if (0 == contents.size()) {
            makeParsingError(error, "not multipart/mixed format:\r\n" + text);
            return false;
        } else
            return true;
    }
    bool expectJsons(const std::vector<HttpContent>& contents, std::vector<json11::Json>& jsons, RFutureError& error) {
        
        for (auto& c : contents) {
            if (false == icontains(c.type, ContentType::json())) {
                makeParsingError(error, "expecting application/json, current is " + c.type + "; content = " + c.content);
                return false;
            }
            string e;
            json11::Json json = json11::Json::parse(c.content, e);
            if (false == e.empty()) {
                makeParsingError(error, "json parsing error: " + e);
                return false;
            }
            jsons.push_back(json);
        }
        return true;
    }
    bool expectStringContent(std::shared_ptr<RNetworkResponse> response, std::string& content, RFutureError& error) {
        if (response->content_type.empty()) {
            content.clear();
            return true;
        } else if (icontains(response->content_type, ContentType::json()) ||
                   icontains(response->content_type, ContentType::multipart_mixed()) ||
                   icontains(response->content_type, ContentType::text()) ||
                   icontains(response->content_type, ContentType::xml()) ||
                   icontains(response->content_type, ContentType::x_www_form_urlencoded())) {
            content = decodeString(response);
            return true;
        } else {
            makeParsingError(error, "unexpected content type: " + response->content_type);
            return false;
        }
    }
    bool expectBinaryContent(std::shared_ptr<RNetworkResponse> response, std::vector<uint8_t>& binary, RFutureError&) {
        binary = response->data;
        return true;
    }
    
}

