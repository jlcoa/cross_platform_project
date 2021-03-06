// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_logger.djinni

#pragma once

#include <functional>

namespace core_gen {

enum class LogLevel : int {
    VERBOSS,
    DEBUG,
    INFO,
    WARNING,
    ERROR,
};

}  // namespace core_gen

namespace std {

template <>
struct hash<::core_gen::LogLevel> {
    size_t operator()(::core_gen::LogLevel type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
