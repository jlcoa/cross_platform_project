// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "native_r_action_result.hpp"  // my header
#include "Marshal.hpp"
#include "native_e_callback_result.hpp"

namespace djinni_generated {

NativeRActionResult::NativeRActionResult() = default;

NativeRActionResult::~NativeRActionResult() = default;

auto NativeRActionResult::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeRActionResult>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni_generated::NativeECallbackResult::fromCpp(jniEnv, c.result)),
                                                           ::djinni::get(::djinni::I32::fromCpp(jniEnv, c.code)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeRActionResult::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 3);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeRActionResult>::get();
    return {::djinni_generated::NativeECallbackResult::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mResult)),
            ::djinni::I32::toCpp(jniEnv, jniEnv->GetIntField(j, data.field_mCode))};
}

}  // namespace djinni_generated