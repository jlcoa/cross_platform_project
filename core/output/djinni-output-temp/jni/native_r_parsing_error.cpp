// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network.djinni

#include "native_r_parsing_error.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeRParsingError::NativeRParsingError() = default;

NativeRParsingError::~NativeRParsingError() = default;

auto NativeRParsingError::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeRParsingError>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.message)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeRParsingError::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 2);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeRParsingError>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mMessage))};
}

}  // namespace djinni_generated
