// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_file_storage_provider.djinni

#import "CoreIFileStorageProvider+Private.h"
#import "CoreIFileStorageProvider.h"
#import "DJIMarshal+Private.h"
#import "DJIObjcWrapperCache+Private.h"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

namespace djinni_generated {

class IFileStorageProvider::ObjcProxy final
: public ::core_gen::IFileStorageProvider
, public ::djinni::ObjcProxyCache::Handle<ObjcType>
{
public:
    using Handle::Handle;
    std::string getDocumentsPath(const std::string & c_relative_path) override
    {
        @autoreleasepool {
            auto r = [Handle::get() getDocumentsPath:(::djinni::String::fromCpp(c_relative_path))];
            return ::djinni::String::toCpp(r);
        }
    }
    void createRelativeFolder(const std::string & c_relative_path) override
    {
        @autoreleasepool {
            [Handle::get() createRelativeFolder:(::djinni::String::fromCpp(c_relative_path))];
        }
    }
    void remove(const std::string & c_path) override
    {
        @autoreleasepool {
            [Handle::get() remove:(::djinni::String::fromCpp(c_path))];
        }
    }
};

}  // namespace djinni_generated

namespace djinni_generated {

auto IFileStorageProvider::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return ::djinni::get_objc_proxy<ObjcProxy>(objc);
}

auto IFileStorageProvider::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return dynamic_cast<ObjcProxy&>(*cpp).Handle::get();
}

}  // namespace djinni_generated
