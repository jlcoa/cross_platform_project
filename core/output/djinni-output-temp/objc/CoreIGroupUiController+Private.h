// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "i_group_ui_controller.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class CoreIGroupUiController;

namespace djinni_generated {

class IGroupUiController
{
public:
    using CppType = std::shared_ptr<::core_gen::IGroupUiController>;
    using CppOptType = std::shared_ptr<::core_gen::IGroupUiController>;
    using ObjcType = CoreIGroupUiController*;

    using Boxed = IGroupUiController;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

