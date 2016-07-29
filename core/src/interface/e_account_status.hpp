// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#pragma once

#include <functional>

namespace core_gen {

enum class EAccountStatus : int {
    NOT_LOGGED_IN,
    IN_PROGRESS,
    LOGGED_IN,
};

}  // namespace core_gen

namespace std {

template <>
struct hash<::core_gen::EAccountStatus> {
    size_t operator()(::core_gen::EAccountStatus type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std