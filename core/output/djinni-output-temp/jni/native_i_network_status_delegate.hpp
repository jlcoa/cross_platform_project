// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#pragma once

#include "djinni_support.hpp"
#include "i_network_status_delegate.hpp"

namespace djinni_generated {

class NativeINetworkStatusDelegate final : ::djinni::JniInterface<::core_gen::INetworkStatusDelegate, NativeINetworkStatusDelegate> {
public:
    using CppType = std::shared_ptr<::core_gen::INetworkStatusDelegate>;
    using CppOptType = std::shared_ptr<::core_gen::INetworkStatusDelegate>;
    using JniType = jobject;

    using Boxed = NativeINetworkStatusDelegate;

    ~NativeINetworkStatusDelegate();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeINetworkStatusDelegate>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeINetworkStatusDelegate>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeINetworkStatusDelegate();
    friend ::djinni::JniClass<NativeINetworkStatusDelegate>;
    friend ::djinni::JniInterface<::core_gen::INetworkStatusDelegate, NativeINetworkStatusDelegate>;

};

}  // namespace djinni_generated
