// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network.djinni

#pragma once

#include <string>
#include <utility>

namespace core_gen {

struct RParsingError final {
    std::string message;

    RParsingError(std::string message_)
    : message(std::move(message_))
    {}
    RParsingError() {};
};

}  // namespace core_gen