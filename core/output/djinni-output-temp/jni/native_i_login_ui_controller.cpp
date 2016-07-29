// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "native_i_login_ui_controller.hpp"  // my header
#include "native_i_login_view_model.hpp"

namespace djinni_generated {

NativeILoginUiController::NativeILoginUiController() : ::djinni::JniInterface<::core_gen::ILoginUiController, NativeILoginUiController>("com/nextuc/ILoginUiController$CppProxy") {}

NativeILoginUiController::~NativeILoginUiController() = default;


CJNIEXPORT void JNICALL Java_com_nextuc_ILoginUiController_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::core_gen::ILoginUiController>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_nextuc_ILoginUiController_00024CppProxy_native_1login(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::ILoginUiController>(nativeRef);
        ref->login();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_nextuc_ILoginUiController_00024CppProxy_native_1getViewModel(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::ILoginUiController>(nativeRef);
        auto r = ref->getViewModel();
        return ::djinni::release(::djinni_generated::NativeILoginViewModel::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
