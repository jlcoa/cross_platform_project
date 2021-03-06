// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "native_i_action_callback.hpp"  // my header
#include "native_r_action_result.hpp"

namespace djinni_generated {

NativeIActionCallback::NativeIActionCallback() : ::djinni::JniInterface<::core_gen::IActionCallback, NativeIActionCallback>() {}

NativeIActionCallback::~NativeIActionCallback() = default;

NativeIActionCallback::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeIActionCallback::JavaProxy::~JavaProxy() = default;

void NativeIActionCallback::JavaProxy::onResponse(const ::core_gen::RActionResult & c_result) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeIActionCallback>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onResponse,
                           ::djinni::get(::djinni_generated::NativeRActionResult::fromCpp(jniEnv, c_result)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
