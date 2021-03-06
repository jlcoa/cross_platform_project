// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#pragma once

#include "djinni_support.hpp"
#include "r_network_request.hpp"

namespace djinni_generated {

class NativeRNetworkRequest final {
public:
    using CppType = ::core_gen::RNetworkRequest;
    using JniType = jobject;

    using Boxed = NativeRNetworkRequest;

    ~NativeRNetworkRequest();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeRNetworkRequest();
    friend ::djinni::JniClass<NativeRNetworkRequest>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nextuc/RNetworkRequest") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(JLjava/lang/String;Ljava/lang/String;Lcom/nextuc/ENetworkMethod;Ljava/util/HashMap;Ljava/lang/String;)V") };
    const jfieldID field_mRequestID { ::djinni::jniGetFieldID(clazz.get(), "mRequestID", "J") };
    const jfieldID field_mHost { ::djinni::jniGetFieldID(clazz.get(), "mHost", "Ljava/lang/String;") };
    const jfieldID field_mPath { ::djinni::jniGetFieldID(clazz.get(), "mPath", "Ljava/lang/String;") };
    const jfieldID field_mRequestMethod { ::djinni::jniGetFieldID(clazz.get(), "mRequestMethod", "Lcom/nextuc/ENetworkMethod;") };
    const jfieldID field_mHeader { ::djinni::jniGetFieldID(clazz.get(), "mHeader", "Ljava/util/HashMap;") };
    const jfieldID field_mData { ::djinni::jniGetFieldID(clazz.get(), "mData", "Ljava/lang/String;") };
};

}  // namespace djinni_generated
