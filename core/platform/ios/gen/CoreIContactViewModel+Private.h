// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "i_contact_view_model.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class CoreIContactViewModel;

namespace djinni_generated {

class IContactViewModel
{
public:
    using CppType = std::shared_ptr<::core_gen::IContactViewModel>;
    using CppOptType = std::shared_ptr<::core_gen::IContactViewModel>;
    using ObjcType = CoreIContactViewModel*;

    using Boxed = IContactViewModel;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

