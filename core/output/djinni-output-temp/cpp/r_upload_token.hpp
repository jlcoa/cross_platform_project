// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#pragma once

#include "../network/json/serialization_json.hpp"
#include <optional/optional.hpp> 
#include <string>
#include <utility>

namespace core_gen {

struct RUploadToken final {
    std::experimental::optional<std::string> userId;
    std::experimental::optional<std::string> avatarUploadToken;

    JSON_SERIALIZE("userId", userId, "avatarUploadToken", avatarUploadToken)

    RUploadToken(std::experimental::optional<std::string> userId_,
                 std::experimental::optional<std::string> avatarUploadToken_)
    : userId(std::move(userId_))
    , avatarUploadToken(std::move(avatarUploadToken_))
    {}
    RUploadToken() {};
};

}  // namespace core_gen
