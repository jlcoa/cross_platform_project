// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#import "CoreIContactTableDataSource+Private.h"
#import "CoreIContactTableDataSource.h"
#import "CoreRContact+Private.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#include <exception>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface CoreIContactTableDataSource ()

- (id)initWithCpp:(const std::shared_ptr<::core_gen::IContactTableDataSource>&)cppRef;

@end

@implementation CoreIContactTableDataSource {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::core_gen::IContactTableDataSource>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::core_gen::IContactTableDataSource>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (int32_t)numberOfSections {
    try {
        auto r = _cppRefHandle.get()->numberOfSections();
        return ::djinni::I32::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (int32_t)numberOfRowsInSection:(int32_t)section {
    try {
        auto r = _cppRefHandle.get()->numberOfRowsInSection(::djinni::I32::toCpp(section));
        return ::djinni::I32::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull CoreRContact *)objectAt:(int32_t)section
                               row:(int32_t)row {
    try {
        auto r = _cppRefHandle.get()->objectAt(::djinni::I32::toCpp(section),
                                               ::djinni::I32::toCpp(row));
        return ::djinni_generated::RContact::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto IContactTableDataSource::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto IContactTableDataSource::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<CoreIContactTableDataSource>(cpp);
}

}  // namespace djinni_generated

@end