// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#import "CoreINetworkStatusProvider+Private.h"
#import "CoreINetworkStatusProvider.h"
#import "CoreINetworkStatusDelegate+Private.h"
#import "DJIMarshal+Private.h"
#import "DJIObjcWrapperCache+Private.h"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

namespace djinni_generated {

class INetworkStatusProvider::ObjcProxy final
: public ::core_gen::INetworkStatusProvider
, public ::djinni::ObjcProxyCache::Handle<ObjcType>
{
public:
    using Handle::Handle;
    void setDelegate(const std::shared_ptr<::core_gen::INetworkStatusDelegate> & c_delegate) override
    {
        @autoreleasepool {
            [Handle::get() setDelegate:(::djinni_generated::INetworkStatusDelegate::fromCpp(c_delegate))];
        }
    }
    ::core_gen::ENetworkStatus getNetworkStatus() override
    {
        @autoreleasepool {
            auto r = [Handle::get() getNetworkStatus];
            return ::djinni::Enum<::core_gen::ENetworkStatus, CoreENetworkStatus>::toCpp(r);
        }
    }
    void startMonitoring() override
    {
        @autoreleasepool {
            [Handle::get() startMonitoring];
        }
    }
    void stopMonitoring() override
    {
        @autoreleasepool {
            [Handle::get() stopMonitoring];
        }
    }
};

}  // namespace djinni_generated

namespace djinni_generated {

auto INetworkStatusProvider::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return ::djinni::get_objc_proxy<ObjcProxy>(objc);
}

auto INetworkStatusProvider::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return dynamic_cast<ObjcProxy&>(*cpp).Handle::get();
}

}  // namespace djinni_generated
