/*
 * Copyright (c) 2015 RingCentral Inc. All rights reserved.
 *
 * @Author Kent Chen <kent.chen@ringcentral.com>
 */

#pragma once
#include <json11/json11.hpp>

#include <stdexcept>

class JsonMissingKey : public std::runtime_error {
public:
    JsonMissingKey(const json11::Json& json, const std::string& name)
        : std::runtime_error("JsonMissingKey:" + name + "\r\nwith json:\r\n" + json.dump()) {}
};
