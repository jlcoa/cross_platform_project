// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#pragma once

#include "e_network_method.hpp"
#include <cstdint>
#include <string>
#include <unordered_map>
#include <utility>

namespace core_gen {

struct RNetworkRequest final {
    int64_t requestID;
    std::string host;
    std::string path;
    ENetworkMethod request_method;
    std::unordered_map<std::string, std::string> header;
    std::string data;

    RNetworkRequest(int64_t requestID_,
                    std::string host_,
                    std::string path_,
                    ENetworkMethod request_method_,
                    std::unordered_map<std::string, std::string> header_,
                    std::string data_)
    : requestID(std::move(requestID_))
    , host(std::move(host_))
    , path(std::move(path_))
    , request_method(std::move(request_method_))
    , header(std::move(header_))
    , data(std::move(data_))
    {}
    RNetworkRequest() {};
};

}  // namespace core_gen