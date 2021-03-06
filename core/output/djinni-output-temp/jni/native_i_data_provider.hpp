// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include "djinni_support.hpp"
#include "i_data_provider.hpp"

namespace djinni_generated {

class NativeIDataProvider final : ::djinni::JniInterface<::core_gen::IDataProvider, NativeIDataProvider> {
public:
    using CppType = std::shared_ptr<::core_gen::IDataProvider>;
    using CppOptType = std::shared_ptr<::core_gen::IDataProvider>;
    using JniType = jobject;

    using Boxed = NativeIDataProvider;

    ~NativeIDataProvider();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeIDataProvider>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeIDataProvider>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeIDataProvider();
    friend ::djinni::JniClass<NativeIDataProvider>;
    friend ::djinni::JniInterface<::core_gen::IDataProvider, NativeIDataProvider>;

};

}  // namespace djinni_generated
