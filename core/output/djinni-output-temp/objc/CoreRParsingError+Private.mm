// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from network.djinni

#import "CoreRParsingError+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto RParsingError::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::String::toCpp(obj.message)};
}

auto RParsingError::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[CoreRParsingError alloc] initWithMessage:(::djinni::String::fromCpp(cpp.message))];
}

}  // namespace djinni_generated
