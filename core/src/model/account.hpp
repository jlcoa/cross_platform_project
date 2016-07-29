//
//  account.hpp
//  core
//
//  Created by Steve Chen on 2/3/16.
//
//

#pragma once

#include <optional/optional_core.hpp>
#include <string>
#include <utility>

#include "../network/json/serialization_json.hpp"

namespace core {
    
    struct Account final {
        
        std::experimental::optional<std::string> username;
        
        std::experimental::optional<std::string> password;
        
        std::experimental::optional<std::string> grant_type;
        
        std::experimental::optional<std::string> access_token;
        
        std::experimental::optional<std::string> refresh_token;
        
        std::experimental::optional<std::string> userId;
        
        std::experimental::optional<std::string> email;
        
        JSON_SERIALIZE("username", username, "password", password, "grant_type", grant_type, "access_token", access_token);
        
        Account(
                std::experimental::optional<std::string> un,
                std::experimental::optional<std::string> pwd,
                std::experimental::optional<std::string> gt,
                std::experimental::optional<std::string> at
                ) :
        username(std::move(un)),
        password(std::move(pwd)),
        grant_type(std::move(gt)),
        access_token(std::move(at))
         {
        }
        
        Account(){}
    };
    
}