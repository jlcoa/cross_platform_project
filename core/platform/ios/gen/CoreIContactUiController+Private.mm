// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#import "CoreIContactUiController+Private.h"
#import "CoreIContactUiController.h"
#import "CoreIContactViewModel+Private.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#include <exception>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface CoreIContactUiController ()

- (id)initWithCpp:(const std::shared_ptr<::core_gen::IContactUiController>&)cppRef;

@end

@implementation CoreIContactUiController {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::core_gen::IContactUiController>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::core_gen::IContactUiController>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (nullable CoreIContactViewModel *)getViewModel {
    try {
        auto r = _cppRefHandle.get()->getViewModel();
        return ::djinni_generated::IContactViewModel::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto IContactUiController::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto IContactUiController::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<CoreIContactUiController>(cpp);
}

}  // namespace djinni_generated

@end
