// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#import "CoreRNetworkRequest.h"
#include "r_network_request.hpp"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class CoreRNetworkRequest;

namespace djinni_generated {

struct RNetworkRequest
{
    using CppType = ::core_gen::RNetworkRequest;
    using ObjcType = CoreRNetworkRequest*;

    using Boxed = RNetworkRequest;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCpp(const CppType& cpp);
};

}  // namespace djinni_generated