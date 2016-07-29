#pragma once
#include "stl.hpp"
#include <json11/json11.hpp>
#include "types.hpp"
#include "../http.hpp"

namespace github {

github::User parse_user(const json11::Json& json);
void get_users(core::Http http, optional<uint64_t> since, function<void(vector<github::User>)>);

class Client final {
  public:
    Client(core::Http http_client);
    void get_users(optional<uint64_t> since, function<void(vector<github::User>)>);
  private:
    core::Http m_http;
};

}
