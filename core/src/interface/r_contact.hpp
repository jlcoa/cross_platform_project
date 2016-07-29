// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#pragma once

#include "../model/model.hpp"
#include "../network/json/serialization_json.hpp"
#include <optional/optional.hpp> 
#include <string>
#include <utility>

namespace core_gen {

/** contact  */
struct RContact: public Model  {
    std::experimental::optional<std::string> username;
    std::experimental::optional<std::string> id;
    std::experimental::optional<std::string> email;
    std::experimental::optional<std::string> firstName;
    std::experimental::optional<std::string> lastName;
    std::experimental::optional<std::string> displayName;
    std::experimental::optional<std::string> companyId;
    std::experimental::optional<std::string> avatarUrl;

    const static std::string USERNAME;
    const static std::string ID;
    const static std::string EMAIL;
    const static std::string FIRSTNAME;
    const static std::string LASTNAME;
    const static std::string DISPLAYNAME;
    const static std::string COMPANYID;
    const static std::string AVATARURL;


    JSON_SERIALIZE("username", username, "id", id, "email", email, "firstName", firstName, "lastName", lastName, "displayName", displayName, "companyId", companyId, "avatarUrl", avatarUrl)

    RContact(std::experimental::optional<std::string> username_,
             std::experimental::optional<std::string> id_,
             std::experimental::optional<std::string> email_,
             std::experimental::optional<std::string> firstName_,
             std::experimental::optional<std::string> lastName_,
             std::experimental::optional<std::string> displayName_,
             std::experimental::optional<std::string> companyId_,
             std::experimental::optional<std::string> avatarUrl_)
    : username(std::move(username_))
    , id(std::move(id_))
    , email(std::move(email_))
    , firstName(std::move(firstName_))
    , lastName(std::move(lastName_))
    , displayName(std::move(displayName_))
    , companyId(std::move(companyId_))
    , avatarUrl(std::move(avatarUrl_))
    {}
    RContact() {};
};

}  // namespace core_gen