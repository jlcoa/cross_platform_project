// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from model.djinni

#include "native_r_group_member.hpp"  // my header
#include "Marshal.hpp"
#include "native_e_group_member_type.hpp"

namespace djinni_generated {

NativeRGroupMember::NativeRGroupMember() = default;

NativeRGroupMember::~NativeRGroupMember() = default;

auto NativeRGroupMember::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeRGroupMember>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.id)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.groupId)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.userId)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni_generated::NativeEGroupMemberType>::fromCpp(jniEnv, c.type)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeRGroupMember::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 5);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeRGroupMember>::get();
    return {::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mId)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mGroupId)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mUserId)),
            ::djinni::Optional<std::experimental::optional, ::djinni_generated::NativeEGroupMemberType>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mType))};
}

}  // namespace djinni_generated