// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#pragma once

#include <functional>

namespace core_gen {

enum class ECallbackResult : int {
    SUCCESS,
    FAILURE,
};

}  // namespace core_gen

namespace std {

template <>
struct hash<::core_gen::ECallbackResult> {
    size_t operator()(::core_gen::ECallbackResult type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std