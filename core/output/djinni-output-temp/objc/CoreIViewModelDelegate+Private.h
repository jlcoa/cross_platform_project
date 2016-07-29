// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "i_view_model_delegate.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@protocol CoreIViewModelDelegate;

namespace djinni_generated {

class IViewModelDelegate
{
public:
    using CppType = std::shared_ptr<::core_gen::IViewModelDelegate>;
    using CppOptType = std::shared_ptr<::core_gen::IViewModelDelegate>;
    using ObjcType = id<CoreIViewModelDelegate>;

    using Boxed = IViewModelDelegate;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated
