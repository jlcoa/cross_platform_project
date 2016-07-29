// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.djinni

#include "api.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class CoreApi;

namespace djinni_generated {

class Api
{
public:
    using CppType = std::shared_ptr<::core_gen::Api>;
    using CppOptType = std::shared_ptr<::core_gen::Api>;
    using ObjcType = CoreApi*;

    using Boxed = Api;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

