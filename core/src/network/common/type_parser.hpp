
/*
 * Copyright (c) 2015 RingCentral Inc. All rights reserved.
 *
 * @Author easton.hou
 */

#pragma once
#include "../../interface/r_future_error.hpp"
#include "../../core/pal.hpp"
#include <sstream>
#include "api_header_common.hpp"

namespace core {
    
    struct HttpContent {
        std::string type;
        std::string content;
    };
    
    bool expectRequestResultSuccessful(core_gen::ERequestResult requestResult, core_gen::RFutureError& error);
    bool expectJsonResponse(std::shared_ptr<core_gen::RNetworkResponse> response, json11::Json& value, core_gen::RFutureError& error);
    //bool expectJsonNoServerError(const json11::Json& json, core_gen::RFutureError& error);
    bool expectMultiMixed(std::shared_ptr<core_gen::RNetworkResponse> response, std::vector<HttpContent>& contents, core_gen::RFutureError& error);
    bool expectJsons(const std::vector<HttpContent>& contents, std::vector<json11::Json>& jsons, core_gen::RFutureError& error);
    bool expectStringContent(std::shared_ptr<core_gen::RNetworkResponse> response, std::string& content, core_gen::RFutureError& error);
    bool expectBinaryContent(std::shared_ptr<core_gen::RNetworkResponse> response, std::vector<uint8_t>& binary, core_gen::RFutureError& error);
    bool expectNoServerError(std::shared_ptr<core_gen::RNetworkResponse> response, core_gen::RFutureError& error);
    void makeParsingError(core_gen::RFutureError& e, const std::string& message);
    
    template<typename Type>
    bool deserializeType(const json11::Json& json, Type& value, core_gen::RFutureError& error) {
        try {
            value.jdeserialize(json);
            return true;
        } catch (const JsonMissingKey& e) {
            makeParsingError(error, e.what());
            return false;
        }
    }
    
    template<typename Type>
    bool deserializeBatchType(std::vector<json11::Json>& jsons, Type& value, core_gen::RFutureError& error) {
        if (1 > jsons.size()) {
            makeParsingError(error, "deserialize batch type: no jsons");
            return false;
        }
        if (false == jsons[0].is_object() || false == jsons[0]["response"].is_array()) {
            makeParsingError(error, "batch request header requires response array:\r\n" + jsons[0].dump());
            return false;
        }
        const std::vector<json11::Json>& jsonResponseHeaders = jsons[0]["response"].array_items();
        if (0 == jsonResponseHeaders.size()) {
            makeParsingError(error, "batch request header is empty array");
            return false;
        }
        if (jsonResponseHeaders.size() != jsons.size() - 1) {
            makeParsingError(error, "batch request header size mismatches body size");
            return false;
        }
        
        typedef typename decltype(Type().records)::value_type Record;
        typedef typename decltype(Type().errors)::value_type Error;
        typedef decltype(Error().id) IdType;
        std::vector<Record>& records = value.records;
        std::vector<Error>& errors = value.errors;
        
        for (size_t k = 0; k < jsonResponseHeaders.size(); ++k) {
            const json11::Json& header = jsonResponseHeaders[k];
            if (false == header.is_object()) {
                makeParsingError(error, "header requires json object:\r\n" + header.dump());
                return false;
            }
            
            //decode response header
            std::string href;
            int status;
            std::string description;
            try {
                json11::json_deserialize(header.object_items(), "href", href, "status", status, "responseDescription", description);
            } catch (const JsonMissingKey& e) {
                makeParsingError(error, e.what());
                return false;
            }
            //decode id
            IdType id;
            std::string::size_type pos = href.find_last_of('/');
            if (href.npos == pos) {
                id = IdType();
            } else {
                std::stringstream ss;
                try {
                    ss << href.substr(pos + 1);
                    ss >> id;
                } catch (...) {
                    id = IdType();
                }
            }
            
            //decode body
            const json11::Json& body = jsons[k + 1];
            if (false == body.is_object()) {
                Error error;
                error.id = id;
                makeParsingError(error.error, "batch response body requires json object:\r\n" + body.dump());
                errors.push_back(error);
                continue;
            }
            
            if (200 <= status && 300 > status) {
                try {
                    Record record;
                    record.jdeserialize(body);
                    records.push_back(record);
                } catch (const JsonMissingKey& e) {
                    Error error;
                    error.id = id;
                    makeParsingError(error.error, e.what());
                    errors.push_back(error);
                }
            } else {
                Error error;
                error.error.generalMessage = body.dump();
                error.id = id;
                try {
                    //                    std::experimental::optional<std::string> error_code_,
                    //                    std::experimental::optional<std::string> message_,
                    //                    std::experimental::optional<std::string> parameterName_,
                    //                    std::experimental::optional<std::string> parameter_,
                    //                    std::vector<RServerErrorDetail> errors_,
                    //                    std::experimental::optional<std::string> error_,
                    //                    std::experimental::optional<std::string> error_description_
                    
                    
                    std::vector<core_gen::RServerErrorDetail> errors;
                    
                    //                    core_gen::RServerError se("", "", "", "", errors, "", "");
                    //                    se.jdeserialize(body);
                    //                    error.error.type = core_gen::EErrorType::SERVER_FAILURE;
                    //                    error.error.serverError = se;
                } catch (const JsonMissingKey&) {
                    error.error.type = core_gen::EErrorType::UNKNOWN;
                }
                errors.push_back(error);
            }
        }
        return true;
    }
    
    template<typename Type, int Trait = determine_type<Type>::value>
    struct TypeParser {
        bool operator()(
                        core_gen::ERequestResult requestResult,
                        std::shared_ptr<core_gen::RNetworkResponse> response,
                        Type& value,
                        core_gen::RFutureError& error) {
            json11::Json json;
            return
            expectRequestResultSuccessful(requestResult, error) &&
            expectNoServerError(response, error) &&
            expectJsonResponse(response, json, error) &&
            deserializeType(json, value, error);
        }
    };
    
    template<>
    struct TypeParser<json11::Json, (int)TypeTrait::Json> {
        bool operator()(
                        core_gen::ERequestResult requestResult,
                        std::shared_ptr<core_gen::RNetworkResponse> response,
                        json11::Json& value,
                        core_gen::RFutureError& error) {
            return
            expectRequestResultSuccessful(requestResult, error) &&
            expectNoServerError(response, error) &&
            expectJsonResponse(response, value, error);
        }
    };
    
    template<>
    struct TypeParser<std::string, (int)TypeTrait::String> {
        bool operator()(
                        core_gen::ERequestResult requestResult,
                        std::shared_ptr<core_gen::RNetworkResponse> response,
                        std::string& value,
                        core_gen::RFutureError& error) {
            return
            expectRequestResultSuccessful(requestResult, error) &&
            expectNoServerError(response, error) &&
            expectStringContent(response, value, error);
        }
    };
    
    template<>
    struct TypeParser<EmptyJsonType, (int)TypeTrait::None> {
        bool operator()(
                        core_gen::ERequestResult requestResult,
                        std::shared_ptr<core_gen::RNetworkResponse> response,
                        EmptyJsonType&,
                        core_gen::RFutureError& error) {
            return
            expectRequestResultSuccessful(requestResult, error) &&
            expectNoServerError(response, error);
        }
    };
    
    template<>
    struct TypeParser<std::vector<uint8_t>, (int)TypeTrait::Binary> {
        bool operator()(
                        core_gen::ERequestResult requestResult,
                        std::shared_ptr<core_gen::RNetworkResponse> response,
                        std::vector<uint8_t>& value,
                        core_gen::RFutureError& error) {
            return
            expectRequestResultSuccessful(requestResult, error) &&
            expectNoServerError(response, error) &&
            expectBinaryContent(response, value, error);
        }
    };
    
    template<typename Type>
    struct TypeParser<Type, (int)TypeTrait::Batch> {
        bool operator()(
                        core_gen::ERequestResult requestResult,
                        std::shared_ptr<core_gen::RNetworkResponse> response,
                        Type& value,
                        core_gen::RFutureError& error) {
            std::string content;
            std::vector<HttpContent> contents;
            std::vector<json11::Json> jsons;
            json11::Json json;
            
            if (false == expectRequestResultSuccessful(requestResult, error) || false == expectNoServerError(response, error))
                return false;
            if (expectMultiMixed(response, contents, error)) {
                return expectJsons(contents, jsons, error) && deserializeBatchType(jsons, value, error);
            } else if (expectJsonResponse(response, json, error)) {
                typename decltype(Type().records)::value_type record;
                if (deserializeType(json, record, error)) {
                    value.records.push_back(record);
                    return true;
                } else { //parsing error
                    return false;
                }
            } else {
                makeParsingError(error, "unsupported content type: " + response->content_type);
                return false;
            }
        }
    };
    
}
