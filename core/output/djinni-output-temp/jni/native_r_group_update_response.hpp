// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#pragma once

#include "djinni_support.hpp"
#include "r_group_update_response.hpp"

namespace djinni_generated {

class NativeRGroupUpdateResponse final {
public:
    using CppType = ::core_gen::RGroupUpdateResponse;
    using JniType = jobject;

    using Boxed = NativeRGroupUpdateResponse;

    ~NativeRGroupUpdateResponse();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeRGroupUpdateResponse();
    friend ::djinni::JniClass<NativeRGroupUpdateResponse>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nextuc/RGroupUpdateResponse") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Lcom/nextuc/RGroup;)V") };
    const jfieldID field_mGroup { ::djinni::jniGetFieldID(clazz.get(), "mGroup", "Lcom/nextuc/RGroup;") };
};

}  // namespace djinni_generated
