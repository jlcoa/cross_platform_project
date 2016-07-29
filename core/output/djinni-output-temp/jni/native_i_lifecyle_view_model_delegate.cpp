// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "native_i_lifecyle_view_model_delegate.hpp"  // my header
#include "native_e_account_status.hpp"

namespace djinni_generated {

NativeILifecyleViewModelDelegate::NativeILifecyleViewModelDelegate() : ::djinni::JniInterface<::core_gen::ILifecyleViewModelDelegate, NativeILifecyleViewModelDelegate>() {}

NativeILifecyleViewModelDelegate::~NativeILifecyleViewModelDelegate() = default;

NativeILifecyleViewModelDelegate::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeILifecyleViewModelDelegate::JavaProxy::~JavaProxy() = default;

void NativeILifecyleViewModelDelegate::JavaProxy::onAccountStatusChanged(::core_gen::EAccountStatus c_status) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeILifecyleViewModelDelegate>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onAccountStatusChanged,
                           ::djinni::get(::djinni_generated::NativeEAccountStatus::fromCpp(jniEnv, c_status)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated