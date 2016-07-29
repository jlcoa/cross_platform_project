// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_logger.djinni

#include "native_i_log.hpp"  // my header
#include "Marshal.hpp"
#include "native_log_level.hpp"

namespace djinni_generated {

NativeILog::NativeILog() : ::djinni::JniInterface<::core_gen::ILog, NativeILog>() {}

NativeILog::~NativeILog() = default;

NativeILog::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeILog::JavaProxy::~JavaProxy() = default;

void NativeILog::JavaProxy::error(const std::string & c_tag, const std::string & c_message) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeILog>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_error,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_tag)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_message)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeILog::JavaProxy::warning(const std::string & c_tag, const std::string & c_message) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeILog>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_warning,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_tag)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_message)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeILog::JavaProxy::info(const std::string & c_tag, const std::string & c_message) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeILog>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_info,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_tag)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_message)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeILog::JavaProxy::debug(const std::string & c_tag, const std::string & c_message) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeILog>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_debug,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_tag)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_message)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeILog::JavaProxy::verbose(const std::string & c_tag, const std::string & c_message) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeILog>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_verbose,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_tag)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_message)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void NativeILog::JavaProxy::setLogLevel(::core_gen::LogLevel c_level) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeILog>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_setLogLevel,
                           ::djinni::get(::djinni_generated::NativeLogLevel::fromCpp(jniEnv, c_level)));
    ::djinni::jniExceptionCheck(jniEnv);
}
bool NativeILog::JavaProxy::visible(::core_gen::LogLevel c_level) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeILog>::get();
    auto jret = jniEnv->CallBooleanMethod(Handle::get().get(), data.method_visible,
                                          ::djinni::get(::djinni_generated::NativeLogLevel::fromCpp(jniEnv, c_level)));
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::Bool::toCpp(jniEnv, jret);
}

}  // namespace djinni_generated