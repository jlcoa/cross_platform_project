// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#import "CoreUserListVm+Private.h"
#import "CoreUserListVm.h"
#import "CoreUserListVmCell+Private.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#include <exception>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface CoreUserListVm ()

- (id)initWithCpp:(const std::shared_ptr<::core_gen::UserListVm>&)cppRef;

@end

@implementation CoreUserListVm {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::core_gen::UserListVm>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::core_gen::UserListVm>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (int32_t)count {
    try {
        auto r = _cppRefHandle.get()->count();
        return ::djinni::I32::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable CoreUserListVmCell *)get:(int32_t)index {
    try {
        auto r = _cppRefHandle.get()->get(::djinni::I32::toCpp(index));
        return ::djinni::Optional<std::experimental::optional, ::djinni_generated::UserListVmCell>::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)deleteRow:(int32_t)index {
    try {
        _cppRefHandle.get()->delete_row(::djinni::I32::toCpp(index));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto UserListVm::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto UserListVm::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<CoreUserListVm>(cpp);
}

}  // namespace djinni_generated

@end
