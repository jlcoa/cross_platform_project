// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include <memory>
#include <string>

namespace core_gen {

class IActionCallback;

class ISignupUiController {
public:
    virtual ~ISignupUiController() {}

    virtual void signup(const std::string & userName, const std::string & password, const std::string & firstName, const std::string & lastName, const std::shared_ptr<IActionCallback> & callback) = 0;
};

}  // namespace core_gen
