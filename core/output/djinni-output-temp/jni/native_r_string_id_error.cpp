// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network.djinni

#include "native_r_string_id_error.hpp"  // my header
#include "Marshal.hpp"
#include "native_r_future_error.hpp"

namespace djinni_generated {

NativeRStringIdError::NativeRStringIdError() = default;

NativeRStringIdError::~NativeRStringIdError() = default;

auto NativeRStringIdError::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeRStringIdError>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.id)),
                                                           ::djinni::get(::djinni_generated::NativeRFutureError::fromCpp(jniEnv, c.error)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeRStringIdError::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 3);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeRStringIdError>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mId)),
            ::djinni_generated::NativeRFutureError::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mError))};
}

}  // namespace djinni_generated
