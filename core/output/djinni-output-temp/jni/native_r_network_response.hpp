// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#pragma once

#include "djinni_support.hpp"
#include "r_network_response.hpp"

namespace djinni_generated {

class NativeRNetworkResponse final {
public:
    using CppType = ::core_gen::RNetworkResponse;
    using JniType = jobject;

    using Boxed = NativeRNetworkResponse;

    ~NativeRNetworkResponse();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeRNetworkResponse();
    friend ::djinni::JniClass<NativeRNetworkResponse>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nextuc/RNetworkResponse") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(JLjava/util/HashMap;Lcom/nextuc/ERequestResult;[BLjava/lang/String;)V") };
    const jfieldID field_mCode { ::djinni::jniGetFieldID(clazz.get(), "mCode", "J") };
    const jfieldID field_mHeader { ::djinni::jniGetFieldID(clazz.get(), "mHeader", "Ljava/util/HashMap;") };
    const jfieldID field_mStatus { ::djinni::jniGetFieldID(clazz.get(), "mStatus", "Lcom/nextuc/ERequestResult;") };
    const jfieldID field_mData { ::djinni::jniGetFieldID(clazz.get(), "mData", "[B") };
    const jfieldID field_mContentType { ::djinni::jniGetFieldID(clazz.get(), "mContentType", "Ljava/lang/String;") };
};

}  // namespace djinni_generated