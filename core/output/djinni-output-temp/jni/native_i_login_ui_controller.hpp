// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include "djinni_support.hpp"
#include "i_login_ui_controller.hpp"

namespace djinni_generated {

class NativeILoginUiController final : ::djinni::JniInterface<::core_gen::ILoginUiController, NativeILoginUiController> {
public:
    using CppType = std::shared_ptr<::core_gen::ILoginUiController>;
    using CppOptType = std::shared_ptr<::core_gen::ILoginUiController>;
    using JniType = jobject;

    using Boxed = NativeILoginUiController;

    ~NativeILoginUiController();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeILoginUiController>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeILoginUiController>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeILoginUiController();
    friend ::djinni::JniClass<NativeILoginUiController>;
    friend ::djinni::JniInterface<::core_gen::ILoginUiController, NativeILoginUiController>;

};

}  // namespace djinni_generated