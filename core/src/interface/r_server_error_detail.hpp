// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network.djinni

#pragma once

#include <optional/optional.hpp> 
#include <string>
#include <utility>

namespace core_gen {

struct RServerErrorDetail final {
    std::string error_code;
    std::string message;
    std::experimental::optional<std::string> parameter;
    std::experimental::optional<std::string> parameterName;

    RServerErrorDetail(std::string error_code_,
                       std::string message_,
                       std::experimental::optional<std::string> parameter_,
                       std::experimental::optional<std::string> parameterName_)
    : error_code(std::move(error_code_))
    , message(std::move(message_))
    , parameter(std::move(parameter_))
    , parameterName(std::move(parameterName_))
    {}
    RServerErrorDetail() {};
};

}  // namespace core_gen
