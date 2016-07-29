// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#include "native_http.hpp"  // my header
#include "Marshal.hpp"
#include "native_http_callback.hpp"

namespace djinni_generated {

NativeHttp::NativeHttp() : ::djinni::JniInterface<::core_gen::Http, NativeHttp>() {}

NativeHttp::~NativeHttp() = default;

NativeHttp::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeHttp::JavaProxy::~JavaProxy() = default;

void NativeHttp::JavaProxy::get(const std::string & c_url, const std::shared_ptr<::core_gen::HttpCallback> & c_callback) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeHttp>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_get,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_url)),
                           ::djinni::get(::djinni_generated::NativeHttpCallback::fromCpp(jniEnv, c_callback)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
