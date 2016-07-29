#pragma once
#include "stl.hpp"
#include <json11/json11.hpp>

namespace core {

class JsonStore {
  public:
    virtual ~JsonStore() {}
    virtual json11::Json get(const string& key) = 0;
    virtual void set(const string& key, const json11::Json& value) = 0;
};

}
