// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "native_i_profile_ui_controller.hpp"  // my header
#include "native_i_action_callback.hpp"
#include "native_i_profile_view_model.hpp"
#include "native_i_request_upload_token_callback.hpp"
#include "native_r_avatar_info.hpp"

namespace djinni_generated {

NativeIProfileUiController::NativeIProfileUiController() : ::djinni::JniInterface<::core_gen::IProfileUiController, NativeIProfileUiController>("com/nextuc/IProfileUiController$CppProxy") {}

NativeIProfileUiController::~NativeIProfileUiController() = default;


CJNIEXPORT void JNICALL Java_com_nextuc_IProfileUiController_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::core_gen::IProfileUiController>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_nextuc_IProfileUiController_00024CppProxy_native_1getViewModel(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::IProfileUiController>(nativeRef);
        auto r = ref->getViewModel();
        return ::djinni::release(::djinni_generated::NativeIProfileViewModel::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_nextuc_IProfileUiController_00024CppProxy_native_1updateAvatar(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_avatarInfo, jobject j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::IProfileUiController>(nativeRef);
        ref->updateAvatar(::djinni_generated::NativeRAvatarInfo::toCpp(jniEnv, j_avatarInfo),
                          ::djinni_generated::NativeIActionCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_nextuc_IProfileUiController_00024CppProxy_native_1requestUploadToken(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::IProfileUiController>(nativeRef);
        ref->requestUploadToken(::djinni_generated::NativeIRequestUploadTokenCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_nextuc_IProfileUiController_00024CppProxy_native_1signout(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_callback)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::IProfileUiController>(nativeRef);
        ref->signout(::djinni_generated::NativeIActionCallback::toCpp(jniEnv, j_callback));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
