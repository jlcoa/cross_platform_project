// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include <memory>

namespace core_gen {

class ILoginViewModel;

class ILoginUiController {
public:
    virtual ~ILoginUiController() {}

    virtual void login() = 0;

    virtual std::shared_ptr<ILoginViewModel> getViewModel() = 0;
};

}  // namespace core_gen
