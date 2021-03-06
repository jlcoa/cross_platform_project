// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "native_i_group_ui_controller.hpp"  // my header
#include "native_i_group_view_model.hpp"

namespace djinni_generated {

NativeIGroupUiController::NativeIGroupUiController() : ::djinni::JniInterface<::core_gen::IGroupUiController, NativeIGroupUiController>("com/nextuc/IGroupUiController$CppProxy") {}

NativeIGroupUiController::~NativeIGroupUiController() = default;


CJNIEXPORT void JNICALL Java_com_nextuc_IGroupUiController_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::core_gen::IGroupUiController>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_nextuc_IGroupUiController_00024CppProxy_native_1getViewModel(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::IGroupUiController>(nativeRef);
        auto r = ref->getViewModel();
        return ::djinni::release(::djinni_generated::NativeIGroupViewModel::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
