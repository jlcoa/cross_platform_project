// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "native_user_list_vm_cell.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeUserListVmCell::NativeUserListVmCell() = default;

NativeUserListVmCell::~NativeUserListVmCell() = default;

auto NativeUserListVmCell::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeUserListVmCell>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::I64::fromCpp(jniEnv, c.user_id)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.name)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeUserListVmCell::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 3);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeUserListVmCell>::get();
    return {::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_mUserId)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mName))};
}

}  // namespace djinni_generated
