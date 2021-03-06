// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#import "CoreIGroupUpdateUiController+Private.h"
#import "CoreIGroupUpdateUiController.h"
#import "CoreIGroupCallback+Private.h"
#import "CoreIGroupUpdateViewModel+Private.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#include <exception>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface CoreIGroupUpdateUiController ()

- (id)initWithCpp:(const std::shared_ptr<::core_gen::IGroupUpdateUiController>&)cppRef;

@end

@implementation CoreIGroupUpdateUiController {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::core_gen::IGroupUpdateUiController>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::core_gen::IGroupUpdateUiController>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (void)updateGroupName:(nonnull NSString *)groupName
               callback:(nullable id<CoreIGroupCallback>)callback {
    try {
        _cppRefHandle.get()->updateGroupName(::djinni::String::toCpp(groupName),
                                             ::djinni_generated::IGroupCallback::toCpp(callback));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable CoreIGroupUpdateViewModel *)getViewModel {
    try {
        auto r = _cppRefHandle.get()->getViewModel();
        return ::djinni_generated::IGroupUpdateViewModel::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto IGroupUpdateUiController::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto IGroupUpdateUiController::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<CoreIGroupUpdateUiController>(cpp);
}

}  // namespace djinni_generated

@end
