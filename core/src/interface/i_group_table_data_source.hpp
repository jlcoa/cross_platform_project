// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include <cstdint>

namespace core_gen {

struct RGroup;

/**# group  */
class IGroupTableDataSource {
public:
    virtual ~IGroupTableDataSource() {}

    virtual int32_t numberOfSections() = 0;

    virtual int32_t numberOfRowsInSection(int32_t section) = 0;

    virtual RGroup objectAt(int32_t section, int32_t row) = 0;
};

}  // namespace core_gen