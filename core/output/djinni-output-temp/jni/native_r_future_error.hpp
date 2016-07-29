// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network.djinni

#pragma once

#include "djinni_support.hpp"
#include "r_future_error.hpp"

namespace djinni_generated {

class NativeRFutureError final {
public:
    using CppType = ::core_gen::RFutureError;
    using JniType = jobject;

    using Boxed = NativeRFutureError;

    ~NativeRFutureError();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeRFutureError();
    friend ::djinni::JniClass<NativeRFutureError>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nextuc/RFutureError") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Lcom/nextuc/EErrorType;Lcom/nextuc/RServerError;Lcom/nextuc/RParsingError;Lcom/nextuc/RNetworkError;Ljava/lang/String;)V") };
    const jfieldID field_mType { ::djinni::jniGetFieldID(clazz.get(), "mType", "Lcom/nextuc/EErrorType;") };
    const jfieldID field_mServerSrror { ::djinni::jniGetFieldID(clazz.get(), "mServerSrror", "Lcom/nextuc/RServerError;") };
    const jfieldID field_mParsingError { ::djinni::jniGetFieldID(clazz.get(), "mParsingError", "Lcom/nextuc/RParsingError;") };
    const jfieldID field_mNetworkError { ::djinni::jniGetFieldID(clazz.get(), "mNetworkError", "Lcom/nextuc/RNetworkError;") };
    const jfieldID field_mGeneralMessage { ::djinni::jniGetFieldID(clazz.get(), "mGeneralMessage", "Ljava/lang/String;") };
};

}  // namespace djinni_generated
