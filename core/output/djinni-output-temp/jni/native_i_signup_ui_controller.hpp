// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include "djinni_support.hpp"
#include "i_signup_ui_controller.hpp"

namespace djinni_generated {

class NativeISignupUiController final : ::djinni::JniInterface<::core_gen::ISignupUiController, NativeISignupUiController> {
public:
    using CppType = std::shared_ptr<::core_gen::ISignupUiController>;
    using CppOptType = std::shared_ptr<::core_gen::ISignupUiController>;
    using JniType = jobject;

    using Boxed = NativeISignupUiController;

    ~NativeISignupUiController();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeISignupUiController>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeISignupUiController>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeISignupUiController();
    friend ::djinni::JniClass<NativeISignupUiController>;
    friend ::djinni::JniInterface<::core_gen::ISignupUiController, NativeISignupUiController>;

};

}  // namespace djinni_generated
