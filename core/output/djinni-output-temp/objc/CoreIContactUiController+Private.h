// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "i_contact_ui_controller.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class CoreIContactUiController;

namespace djinni_generated {

class IContactUiController
{
public:
    using CppType = std::shared_ptr<::core_gen::IContactUiController>;
    using CppOptType = std::shared_ptr<::core_gen::IContactUiController>;
    using ObjcType = CoreIContactUiController*;

    using Boxed = IContactUiController;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

