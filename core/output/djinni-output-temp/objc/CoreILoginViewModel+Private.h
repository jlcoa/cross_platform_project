// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "i_login_view_model.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class CoreILoginViewModel;

namespace djinni_generated {

class ILoginViewModel
{
public:
    using CppType = std::shared_ptr<::core_gen::ILoginViewModel>;
    using CppOptType = std::shared_ptr<::core_gen::ILoginViewModel>;
    using ObjcType = CoreILoginViewModel*;

    using Boxed = ILoginViewModel;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated
