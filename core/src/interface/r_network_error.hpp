// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network.djinni

#pragma once

#include <cstdint>
#include <utility>

namespace core_gen {

struct RNetworkError final {
    int32_t error_code;

    RNetworkError(int32_t error_code_)
    : error_code(std::move(error_code_))
    {}
    RNetworkError() {};
};

}  // namespace core_gen
