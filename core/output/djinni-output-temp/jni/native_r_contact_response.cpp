// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#include "native_r_contact_response.hpp"  // my header
#include "Marshal.hpp"
#include "native_r_contact.hpp"

namespace djinni_generated {

NativeRContactResponse::NativeRContactResponse() = default;

NativeRContactResponse::~NativeRContactResponse() = default;

auto NativeRContactResponse::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeRContactResponse>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::List<::djinni_generated::NativeRContact>>::fromCpp(jniEnv, c.contacts)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeRContactResponse::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 2);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeRContactResponse>::get();
    return {::djinni::Optional<std::experimental::optional, ::djinni::List<::djinni_generated::NativeRContact>>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mContacts))};
}

}  // namespace djinni_generated