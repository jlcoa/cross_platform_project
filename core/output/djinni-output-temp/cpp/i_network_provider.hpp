// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from pal_network_provider.djinni

#pragma once

#include <memory>

namespace core_gen {

class INetworkCallback;
struct RNetworkRequest;

class INetworkProvider {
public:
    virtual ~INetworkProvider() {}

    virtual void request(const RNetworkRequest & request, const std::shared_ptr<INetworkCallback> & callback) = 0;
};

}  // namespace core_gen