// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#include "native_i_network_callback.hpp"  // my header
#include "Marshal.hpp"
#include "native_r_network_response.hpp"

namespace djinni_generated {

NativeINetworkCallback::NativeINetworkCallback() : ::djinni::JniInterface<::core_gen::INetworkCallback, NativeINetworkCallback>("com/nextuc/INetworkCallback$CppProxy") {}

NativeINetworkCallback::~NativeINetworkCallback() = default;


CJNIEXPORT void JNICALL Java_com_nextuc_INetworkCallback_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::core_gen::INetworkCallback>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_nextuc_INetworkCallback_00024CppProxy_native_1onSuccess(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_requestID, jobject j_response)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::INetworkCallback>(nativeRef);
        ref->onSuccess(::djinni::I64::toCpp(jniEnv, j_requestID),
                       ::djinni_generated::NativeRNetworkResponse::toCpp(jniEnv, j_response));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_nextuc_INetworkCallback_00024CppProxy_native_1onFailure(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_requestID, jobject j_response)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::INetworkCallback>(nativeRef);
        ref->onFailure(::djinni::I64::toCpp(jniEnv, j_requestID),
                       ::djinni_generated::NativeRNetworkResponse::toCpp(jniEnv, j_response));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_nextuc_INetworkCallback_00024CppProxy_native_1onProgress(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_requestID, jint j_maxSize, jint j_currentPos)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::INetworkCallback>(nativeRef);
        ref->onProgress(::djinni::I64::toCpp(jniEnv, j_requestID),
                        ::djinni::I32::toCpp(jniEnv, j_maxSize),
                        ::djinni::I32::toCpp(jniEnv, j_currentPos));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated