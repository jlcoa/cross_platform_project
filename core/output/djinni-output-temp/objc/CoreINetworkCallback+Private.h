// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#include "i_network_callback.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class CoreINetworkCallback;

namespace djinni_generated {

class INetworkCallback
{
public:
    using CppType = std::shared_ptr<::core_gen::INetworkCallback>;
    using CppOptType = std::shared_ptr<::core_gen::INetworkCallback>;
    using ObjcType = CoreINetworkCallback*;

    using Boxed = INetworkCallback;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

