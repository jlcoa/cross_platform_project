// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include <memory>

namespace core_gen {

class IGroupViewModel;

class IGroupUiController {
public:
    virtual ~IGroupUiController() {}

    virtual std::shared_ptr<IGroupViewModel> getViewModel() = 0;
};

}  // namespace core_gen
