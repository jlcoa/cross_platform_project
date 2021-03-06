// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "native_i_contact_table_data_source.hpp"  // my header
#include "Marshal.hpp"
#include "native_r_contact.hpp"

namespace djinni_generated {

NativeIContactTableDataSource::NativeIContactTableDataSource() : ::djinni::JniInterface<::core_gen::IContactTableDataSource, NativeIContactTableDataSource>("com/nextuc/IContactTableDataSource$CppProxy") {}

NativeIContactTableDataSource::~NativeIContactTableDataSource() = default;


CJNIEXPORT void JNICALL Java_com_nextuc_IContactTableDataSource_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<djinni::CppProxyHandle<::core_gen::IContactTableDataSource>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jint JNICALL Java_com_nextuc_IContactTableDataSource_00024CppProxy_native_1numberOfSections(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::IContactTableDataSource>(nativeRef);
        auto r = ref->numberOfSections();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jint JNICALL Java_com_nextuc_IContactTableDataSource_00024CppProxy_native_1numberOfRowsInSection(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_section)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::IContactTableDataSource>(nativeRef);
        auto r = ref->numberOfRowsInSection(::djinni::I32::toCpp(jniEnv, j_section));
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_nextuc_IContactTableDataSource_00024CppProxy_native_1objectAt(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_section, jint j_row)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::core_gen::IContactTableDataSource>(nativeRef);
        auto r = ref->objectAt(::djinni::I32::toCpp(jniEnv, j_section),
                               ::djinni::I32::toCpp(jniEnv, j_row));
        return ::djinni::release(::djinni_generated::NativeRContact::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
