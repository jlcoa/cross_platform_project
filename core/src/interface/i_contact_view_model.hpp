// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include <memory>

namespace core_gen {

class IContactTableDataSource;

class IContactViewModel {
public:
    virtual ~IContactViewModel() {}

    virtual void setDataSource(const std::shared_ptr<IContactTableDataSource> & dataSource) = 0;

    virtual std::shared_ptr<IContactTableDataSource> getDataSource() = 0;
};

}  // namespace core_gen