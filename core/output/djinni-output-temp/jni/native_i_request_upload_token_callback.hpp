// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include "djinni_support.hpp"
#include "i_request_upload_token_callback.hpp"

namespace djinni_generated {

class NativeIRequestUploadTokenCallback final : ::djinni::JniInterface<::core_gen::IRequestUploadTokenCallback, NativeIRequestUploadTokenCallback> {
public:
    using CppType = std::shared_ptr<::core_gen::IRequestUploadTokenCallback>;
    using CppOptType = std::shared_ptr<::core_gen::IRequestUploadTokenCallback>;
    using JniType = jobject;

    using Boxed = NativeIRequestUploadTokenCallback;

    ~NativeIRequestUploadTokenCallback();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeIRequestUploadTokenCallback>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeIRequestUploadTokenCallback>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeIRequestUploadTokenCallback();
    friend ::djinni::JniClass<NativeIRequestUploadTokenCallback>;
    friend ::djinni::JniInterface<::core_gen::IRequestUploadTokenCallback, NativeIRequestUploadTokenCallback>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::core_gen::IRequestUploadTokenCallback
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void onTokenGet(const std::experimental::optional<::core_gen::RUploadToken> & token, const ::core_gen::RActionResult & result) override;

    private:
        friend ::djinni::JniInterface<::core_gen::IRequestUploadTokenCallback, ::djinni_generated::NativeIRequestUploadTokenCallback>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nextuc/IRequestUploadTokenCallback") };
    const jmethodID method_onTokenGet { ::djinni::jniGetMethodID(clazz.get(), "onTokenGet", "(Lcom/nextuc/RUploadToken;Lcom/nextuc/RActionResult;)V") };
};

}  // namespace djinni_generated
