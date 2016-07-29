// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

#include <memory>

namespace core_gen {

class IActionCallback;
class IProfileViewModel;
class IRequestUploadTokenCallback;
struct RAvatarInfo;

class IProfileUiController {
public:
    virtual ~IProfileUiController() {}

    virtual std::shared_ptr<IProfileViewModel> getViewModel() = 0;

    virtual void updateAvatar(const RAvatarInfo & avatarInfo, const std::shared_ptr<IActionCallback> & callback) = 0;

    virtual void requestUploadToken(const std::shared_ptr<IRequestUploadTokenCallback> & callback) = 0;

    virtual void signout(const std::shared_ptr<IActionCallback> & callback) = 0;
};

}  // namespace core_gen
