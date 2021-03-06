// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include "djinni_support.hpp"
#include "i_lifecyle_view_model_delegate.hpp"

namespace djinni_generated {

class NativeILifecyleViewModelDelegate final : ::djinni::JniInterface<::core_gen::ILifecyleViewModelDelegate, NativeILifecyleViewModelDelegate> {
public:
    using CppType = std::shared_ptr<::core_gen::ILifecyleViewModelDelegate>;
    using CppOptType = std::shared_ptr<::core_gen::ILifecyleViewModelDelegate>;
    using JniType = jobject;

    using Boxed = NativeILifecyleViewModelDelegate;

    ~NativeILifecyleViewModelDelegate();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeILifecyleViewModelDelegate>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeILifecyleViewModelDelegate>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeILifecyleViewModelDelegate();
    friend ::djinni::JniClass<NativeILifecyleViewModelDelegate>;
    friend ::djinni::JniInterface<::core_gen::ILifecyleViewModelDelegate, NativeILifecyleViewModelDelegate>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::core_gen::ILifecyleViewModelDelegate
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void onAccountStatusChanged(::core_gen::EAccountStatus status) override;

    private:
        friend ::djinni::JniInterface<::core_gen::ILifecyleViewModelDelegate, ::djinni_generated::NativeILifecyleViewModelDelegate>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nextuc/ILifecyleViewModelDelegate") };
    const jmethodID method_onAccountStatusChanged { ::djinni::jniGetMethodID(clazz.get(), "onAccountStatusChanged", "(Lcom/nextuc/EAccountStatus;)V") };
};

}  // namespace djinni_generated
