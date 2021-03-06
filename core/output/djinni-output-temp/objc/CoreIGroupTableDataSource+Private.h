// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#include "i_group_table_data_source.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class CoreIGroupTableDataSource;

namespace djinni_generated {

class IGroupTableDataSource
{
public:
    using CppType = std::shared_ptr<::core_gen::IGroupTableDataSource>;
    using CppOptType = std::shared_ptr<::core_gen::IGroupTableDataSource>;
    using ObjcType = CoreIGroupTableDataSource*;

    using Boxed = IGroupTableDataSource;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

