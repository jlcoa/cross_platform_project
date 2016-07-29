// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from http.djinni

#pragma once

#include "djinni_support.hpp"
#include "http_callback.hpp"

namespace djinni_generated {

class NativeHttpCallback final : ::djinni::JniInterface<::core_gen::HttpCallback, NativeHttpCallback> {
public:
    using CppType = std::shared_ptr<::core_gen::HttpCallback>;
    using CppOptType = std::shared_ptr<::core_gen::HttpCallback>;
    using JniType = jobject;

    using Boxed = NativeHttpCallback;

    ~NativeHttpCallback();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeHttpCallback>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeHttpCallback>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeHttpCallback();
    friend ::djinni::JniClass<NativeHttpCallback>;
    friend ::djinni::JniInterface<::core_gen::HttpCallback, NativeHttpCallback>;

};

}  // namespace djinni_generated
