// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "native_i_request_upload_token_callback.hpp"  // my header
#include "Marshal.hpp"
#include "native_r_action_result.hpp"
#include "native_r_upload_token.hpp"

namespace djinni_generated {

NativeIRequestUploadTokenCallback::NativeIRequestUploadTokenCallback() : ::djinni::JniInterface<::core_gen::IRequestUploadTokenCallback, NativeIRequestUploadTokenCallback>() {}

NativeIRequestUploadTokenCallback::~NativeIRequestUploadTokenCallback() = default;

NativeIRequestUploadTokenCallback::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeIRequestUploadTokenCallback::JavaProxy::~JavaProxy() = default;

void NativeIRequestUploadTokenCallback::JavaProxy::onTokenGet(const std::experimental::optional<::core_gen::RUploadToken> & c_token, const ::core_gen::RActionResult & c_result) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeIRequestUploadTokenCallback>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onTokenGet,
                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni_generated::NativeRUploadToken>::fromCpp(jniEnv, c_token)),
                           ::djinni::get(::djinni_generated::NativeRActionResult::fromCpp(jniEnv, c_result)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
