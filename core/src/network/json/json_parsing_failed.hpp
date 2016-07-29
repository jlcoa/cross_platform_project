/*
 * Copyright (c) 2015 RingCentral Inc. All rights reserved.
 *
 * @Author jerry.cai
 */

#pragma once

#include <stdexcept>
#include <string>

class JsonParsingFailed : public std::runtime_error {
public:
    JsonParsingFailed(const std::string& raw, const std::string& error)
        : std::runtime_error("raw:" + raw + "\r\nwith error:\r\n" + error) {}
};
