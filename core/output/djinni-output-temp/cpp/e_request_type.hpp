// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#pragma once

#include <functional>

namespace core_gen {

enum class ERequestType : int {
    REST,
    DOWNLOAD,
    UPLOAD,
};

}  // namespace core_gen

namespace std {

template <>
struct hash<::core_gen::ERequestType> {
    size_t operator()(::core_gen::ERequestType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
