// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#include "i_network_status_delegate.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class CoreINetworkStatusDelegate;

namespace djinni_generated {

class INetworkStatusDelegate
{
public:
    using CppType = std::shared_ptr<::core_gen::INetworkStatusDelegate>;
    using CppOptType = std::shared_ptr<::core_gen::INetworkStatusDelegate>;
    using ObjcType = CoreINetworkStatusDelegate*;

    using Boxed = INetworkStatusDelegate;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

