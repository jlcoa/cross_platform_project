// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "native_i_group_update_view_model.hpp"  // my header
#include "native_r_group.hpp"

namespace djinni_generated {

NativeIGroupUpdateViewModel::NativeIGroupUpdateViewModel() : ::djinni::JniInterface<::core_gen::IGroupUpdateViewModel, NativeIGroupUpdateViewModel>("com/nextuc/IGroupUpdateViewModel$CppProxy") {}

NativeIGroupUpdateViewModel::~NativeIGroupUpdateViewModel() = default;


CJNIEXPORT void JNICALL Java_com_nextuc_IGroupUpdateViewModel_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::core_gen::IGroupUpdateViewModel>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_nextuc_IGroupUpdateViewModel_00024CppProxy_native_1setGroup(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_group)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::IGroupUpdateViewModel>(nativeRef);
        ref->setGroup(::djinni_generated::NativeRGroup::toCpp(jniEnv, j_group));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_nextuc_IGroupUpdateViewModel_00024CppProxy_native_1getGroup(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::IGroupUpdateViewModel>(nativeRef);
        auto r = ref->getGroup();
        return ::djinni::release(::djinni_generated::NativeRGroup::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
