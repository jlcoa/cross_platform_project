// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

namespace core_gen {

struct RContact;
struct RGroup;

/**# data provider */
class IDataChangeDelegate {
public:
    virtual ~IDataChangeDelegate() {}

    virtual void onContactChanged(const RContact & contact) = 0;

    virtual void onGroupChanged(const RGroup & group) = 0;
};

}  // namespace core_gen
