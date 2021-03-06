// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#pragma once

#include <functional>

namespace core_gen {

enum class ENetworkMethod : int {
    GET,
    POST,
    DELETE,
    PUT,
};

}  // namespace core_gen

namespace std {

template <>
struct hash<::core_gen::ENetworkMethod> {
    size_t operator()(::core_gen::ENetworkMethod type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
