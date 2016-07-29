// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include "djinni_support.hpp"
#include "user_list_vm_cell.hpp"

namespace djinni_generated {

class NativeUserListVmCell final {
public:
    using CppType = ::core_gen::UserListVmCell;
    using JniType = jobject;

    using Boxed = NativeUserListVmCell;

    ~NativeUserListVmCell();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeUserListVmCell();
    friend ::djinni::JniClass<NativeUserListVmCell>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/nextuc/UserListVmCell") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(JLjava/lang/String;)V") };
    const jfieldID field_mUserId { ::djinni::jniGetFieldID(clazz.get(), "mUserId", "J") };
    const jfieldID field_mName { ::djinni::jniGetFieldID(clazz.get(), "mName", "Ljava/lang/String;") };
};

}  // namespace djinni_generated
