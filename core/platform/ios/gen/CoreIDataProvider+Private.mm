// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#import "CoreIDataProvider+Private.h"
#import "CoreIDataProvider.h"
#import "CoreIDataChangeDelegate+Private.h"
#import "CoreRContact+Private.h"
#import "CoreRGroup+Private.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#include <exception>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface CoreIDataProvider ()

- (id)initWithCpp:(const std::shared_ptr<::core_gen::IDataProvider>&)cppRef;

@end

@implementation CoreIDataProvider {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::core_gen::IDataProvider>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::core_gen::IDataProvider>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (void)setDelegate:(nullable id<CoreIDataChangeDelegate>)delegate {
    try {
        _cppRefHandle.get()->setDelegate(::djinni_generated::IDataChangeDelegate::toCpp(delegate));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)hasContact:(nonnull NSString *)id {
    try {
        auto r = _cppRefHandle.get()->hasContact(::djinni::String::toCpp(id));
        return ::djinni::Bool::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)hasGroup:(nonnull NSString *)id {
    try {
        auto r = _cppRefHandle.get()->hasGroup(::djinni::String::toCpp(id));
        return ::djinni::Bool::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull CoreRContact *)getContact:(nonnull NSString *)id {
    try {
        auto r = _cppRefHandle.get()->getContact(::djinni::String::toCpp(id));
        return ::djinni_generated::RContact::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull CoreRGroup *)getGroup:(nonnull NSString *)id {
    try {
        auto r = _cppRefHandle.get()->getGroup(::djinni::String::toCpp(id));
        return ::djinni_generated::RGroup::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto IDataProvider::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto IDataProvider::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<CoreIDataProvider>(cpp);
}

}  // namespace djinni_generated

@end