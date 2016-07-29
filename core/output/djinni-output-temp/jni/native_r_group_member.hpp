// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#pragma once

#include "djinni_support.hpp"
#include "r_group_member.hpp"

namespace djinni_generated {

class NativeRGroupMember final {
public:
    using CppType = ::core_gen::RGroupMember;
    using JniType = jobject;

    using Boxed = NativeRGroupMember;

    ~NativeRGroupMember();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeRGroupMember();
    friend ::djinni::JniClass<NativeRGroupMember>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nextuc/RGroupMember") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Lcom/nextuc/EGroupMemberType;)V") };
    const jfieldID field_mId { ::djinni::jniGetFieldID(clazz.get(), "mId", "Ljava/lang/String;") };
    const jfieldID field_mGroupId { ::djinni::jniGetFieldID(clazz.get(), "mGroupId", "Ljava/lang/String;") };
    const jfieldID field_mUserId { ::djinni::jniGetFieldID(clazz.get(), "mUserId", "Ljava/lang/String;") };
    const jfieldID field_mType { ::djinni::jniGetFieldID(clazz.get(), "mType", "Lcom/nextuc/EGroupMemberType;") };
};

}  // namespace djinni_generated