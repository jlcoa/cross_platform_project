// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network.djinni

#include "native_r_network_error.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeRNetworkError::NativeRNetworkError() = default;

NativeRNetworkError::~NativeRNetworkError() = default;

auto NativeRNetworkError::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeRNetworkError>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::I32::fromCpp(jniEnv, c.error_code)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeRNetworkError::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 2);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeRNetworkError>::get();
    return {::djinni::I32::toCpp(jniEnv, jniEnv->GetIntField(j, data.field_mErrorCode))};
}

}  // namespace djinni_generated