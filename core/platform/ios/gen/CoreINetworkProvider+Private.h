// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#include "i_network_provider.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@protocol CoreINetworkProvider;

namespace djinni_generated {

class INetworkProvider
{
public:
    using CppType = std::shared_ptr<::core_gen::INetworkProvider>;
    using CppOptType = std::shared_ptr<::core_gen::INetworkProvider>;
    using ObjcType = id<CoreINetworkProvider>;

    using Boxed = INetworkProvider;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

