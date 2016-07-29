// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include <cstdint>
#include <string>
#include <utility>

namespace core_gen {

struct UserListVmCell final {
    int64_t user_id;
    std::string name;

    UserListVmCell(int64_t user_id_,
                   std::string name_)
    : user_id(std::move(user_id_))
    , name(std::move(name_))
    {}
    UserListVmCell() {};
};

}  // namespace core_gen