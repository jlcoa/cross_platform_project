// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#include "native_r_network_request.hpp"  // my header
#include "Marshal.hpp"
#include "native_e_network_method.hpp"

namespace djinni_generated {

NativeRNetworkRequest::NativeRNetworkRequest() = default;

NativeRNetworkRequest::~NativeRNetworkRequest() = default;

auto NativeRNetworkRequest::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeRNetworkRequest>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.requestID)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.host)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.path)),
                                                           ::djinni::get(::djinni_generated::NativeENetworkMethod::fromCpp(jniEnv, c.request_method)),
                                                           ::djinni::get(::djinni::Map<::djinni::String, ::djinni::String>::fromCpp(jniEnv, c.header)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.data)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeRNetworkRequest::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 7);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeRNetworkRequest>::get();
    return {::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_mRequestID)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mHost)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mPath)),
            ::djinni_generated::NativeENetworkMethod::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mRequestMethod)),
            ::djinni::Map<::djinni::String, ::djinni::String>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mHeader)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mData))};
}

}  // namespace djinni_generated