// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#include "native_r_account_response.hpp"  // my header
#include "Marshal.hpp"
#include "native_r_account.hpp"

namespace djinni_generated {

NativeRAccountResponse::NativeRAccountResponse() = default;

NativeRAccountResponse::~NativeRAccountResponse() = default;

auto NativeRAccountResponse::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeRAccountResponse>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.access_token)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.refresh_token)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::I32>::fromCpp(jniEnv, c.expires_in)),
                                                           ::djinni::get(::djinni_generated::NativeRAccount::fromCpp(jniEnv, c.user)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeRAccountResponse::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 5);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeRAccountResponse>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mAccessToken)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mRefreshToken)),
            ::djinni::Optional<std::experimental::optional, ::djinni::I32>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mExpiresIn)),
            ::djinni_generated::NativeRAccount::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mUser))};
}

}  // namespace djinni_generated
