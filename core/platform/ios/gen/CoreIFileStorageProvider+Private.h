// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_file_storage_provider.djinni

#include "i_file_storage_provider.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@protocol CoreIFileStorageProvider;

namespace djinni_generated {

class IFileStorageProvider
{
public:
    using CppType = std::shared_ptr<::core_gen::IFileStorageProvider>;
    using CppOptType = std::shared_ptr<::core_gen::IFileStorageProvider>;
    using ObjcType = id<CoreIFileStorageProvider>;

    using Boxed = IFileStorageProvider;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

