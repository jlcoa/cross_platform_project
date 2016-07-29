// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.djinni

#pragma once

#include <memory>
#include <string>

namespace core_gen {

class EventLoop;
class Http;
class ThreadLauncher;
class UserListVmHandle;

class Api {
public:
    virtual ~Api() {}

    static std::shared_ptr<Api> create_api(const std::string & root_path, const std::shared_ptr<EventLoop> & ui_thread, const std::shared_ptr<Http> & http_impl, const std::shared_ptr<ThreadLauncher> & launcher);

    virtual std::shared_ptr<UserListVmHandle> observer_user_list() = 0;

    virtual bool has_user() = 0;

    virtual std::string get_username() = 0;

    virtual void set_username(const std::string & username) = 0;
};

}  // namespace core_gen