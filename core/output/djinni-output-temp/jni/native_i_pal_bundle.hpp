// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_bundle.djinni

#pragma once

#include "djinni_support.hpp"
#include "i_pal_bundle.hpp"

namespace djinni_generated {

class NativeIPalBundle final : ::djinni::JniInterface<::core_gen::IPalBundle, NativeIPalBundle> {
public:
    using CppType = std::shared_ptr<::core_gen::IPalBundle>;
    using CppOptType = std::shared_ptr<::core_gen::IPalBundle>;
    using JniType = jobject;

    using Boxed = NativeIPalBundle;

    ~NativeIPalBundle();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeIPalBundle>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeIPalBundle>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeIPalBundle();
    friend ::djinni::JniClass<NativeIPalBundle>;
    friend ::djinni::JniInterface<::core_gen::IPalBundle, NativeIPalBundle>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::core_gen::IPalBundle
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        std::shared_ptr<::core_gen::INetworkProvider> getNetworkProvider() override;
        std::shared_ptr<::core_gen::ILog> getLog() override;
        std::shared_ptr<::core_gen::IFileStorageProvider> getFileStorageProvider() override;
        std::shared_ptr<::core_gen::INetworkStatusProvider> getNetworkStatusProvider() override;
        std::shared_ptr<::core_gen::ITaskDispatcher> getTaskDispatcher() override;

    private:
        friend ::djinni::JniInterface<::core_gen::IPalBundle, ::djinni_generated::NativeIPalBundle>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nextuc/IPalBundle") };
    const jmethodID method_getNetworkProvider { ::djinni::jniGetMethodID(clazz.get(), "getNetworkProvider", "()Lcom/nextuc/INetworkProvider;") };
    const jmethodID method_getLog { ::djinni::jniGetMethodID(clazz.get(), "getLog", "()Lcom/nextuc/ILog;") };
    const jmethodID method_getFileStorageProvider { ::djinni::jniGetMethodID(clazz.get(), "getFileStorageProvider", "()Lcom/nextuc/IFileStorageProvider;") };
    const jmethodID method_getNetworkStatusProvider { ::djinni::jniGetMethodID(clazz.get(), "getNetworkStatusProvider", "()Lcom/nextuc/INetworkStatusProvider;") };
    const jmethodID method_getTaskDispatcher { ::djinni::jniGetMethodID(clazz.get(), "getTaskDispatcher", "()Lcom/nextuc/ITaskDispatcher;") };
};

}  // namespace djinni_generated