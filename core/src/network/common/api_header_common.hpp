/*
 * Copyright (c) 2015 RingCentral Inc. All rights reserved.
 *
 * @Author Easton Hou <easton.hou@ringcentral.com>
 *
 * Shared by all api header files and indirectly included by external modules.
 */

#pragma once

#include <memory>
#include <vector>
#include <functional>
#include "../../interface/r_future_error.hpp"
#include "../json/serialization_json.hpp"
#include "../../core/pal.hpp"
#include "../../interface/r_network_response.hpp"

template<typename Type>
using specificcallback = std::function<void(std::shared_ptr<Type>, std::shared_ptr<core_gen::RFutureError>, const std::shared_ptr<core_gen::RNetworkResponse> response)>;

namespace core {
    
    enum class TypeTrait : int {
        Single,
        Json,
        Batch,
        String,
        Binary,
        None
    };
    
    template<typename Type>
    struct determine_type {
        enum {value = (int)TypeTrait::Single};
    };
    
    template<>
    struct determine_type<json11::Json> {
        enum {value = (int)TypeTrait::Json};
    };
    
    template<>
    struct determine_type<std::vector<uint8_t>> {
        enum {value = (int)TypeTrait::Binary};
    };
    
    template<>
    struct determine_type<std::string> {
        enum {value = (int)TypeTrait::String};
    };
    
    template<>
    struct determine_type<EmptyJsonType> {
        enum {value = (int)TypeTrait::None};
    };
}