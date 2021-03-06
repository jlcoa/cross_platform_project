// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_bundle.djinni

#include "i_pal_bundle.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@protocol CoreIPalBundle;

namespace djinni_generated {

class IPalBundle
{
public:
    using CppType = std::shared_ptr<::core_gen::IPalBundle>;
    using CppOptType = std::shared_ptr<::core_gen::IPalBundle>;
    using ObjcType = id<CoreIPalBundle>;

    using Boxed = IPalBundle;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

