// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include "djinni_support.hpp"
#include "i_contact_ui_controller.hpp"

namespace djinni_generated {

class NativeIContactUiController final : ::djinni::JniInterface<::core_gen::IContactUiController, NativeIContactUiController> {
public:
    using CppType = std::shared_ptr<::core_gen::IContactUiController>;
    using CppOptType = std::shared_ptr<::core_gen::IContactUiController>;
    using JniType = jobject;

    using Boxed = NativeIContactUiController;

    ~NativeIContactUiController();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeIContactUiController>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeIContactUiController>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeIContactUiController();
    friend ::djinni::JniClass<NativeIContactUiController>;
    friend ::djinni::JniInterface<::core_gen::IContactUiController, NativeIContactUiController>;

};

}  // namespace djinni_generated
