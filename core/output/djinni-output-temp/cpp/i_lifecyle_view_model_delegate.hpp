// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from view_model.djinni

#pragma once

namespace core_gen {

enum class EAccountStatus;

/**# lifecycle */
class ILifecyleViewModelDelegate {
public:
    virtual ~ILifecyleViewModelDelegate() {}

    virtual void onAccountStatusChanged(EAccountStatus status) = 0;
};

}  // namespace core_gen
