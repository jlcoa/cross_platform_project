// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#include "http_callback.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class CoreHttpCallback;

namespace djinni_generated {

class HttpCallback
{
public:
    using CppType = std::shared_ptr<::core_gen::HttpCallback>;
    using CppOptType = std::shared_ptr<::core_gen::HttpCallback>;
    using ObjcType = CoreHttpCallback*;

    using Boxed = HttpCallback;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

