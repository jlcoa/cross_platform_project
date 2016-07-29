#pragma once
#include "stl.hpp"
#include <json11/json11.hpp>
#include "event_loop.hpp"
#include "db/json_store.hpp"
#include "sqlite/sqlite.hpp"
#include "http.hpp"
#include "interface/api.hpp"
#include "single_thread_task_runner.hpp"

namespace core {

// the "api" of how the UI is allowed to talk to the c++ code
class Api final : public core_gen::Api {
  public:
    Api(
        const string & root_path,
        const shared_ptr<SingleThreadTaskRunner>& ui_runner,
        const shared_ptr<SingleThreadTaskRunner>& bg_runner,
        const shared_ptr<core_gen::Http> & http_impl
    );

    // whether a user already exists
    virtual bool has_user() override;
    // get the current username, or "" if none exists
    virtual string get_username() override;
    virtual void set_username(const string& name) override;
    virtual shared_ptr<core_gen::UserListVmHandle> observer_user_list() override;

  private:
    // set up the database
    void _setup_db();

    shared_ptr<sqlite::Db> m_sqlite;
    shared_ptr<sqlite::Db> m_read_db;

    unique_ptr<core::JsonStore> m_db;
    const shared_ptr<SingleThreadTaskRunner> m_ui_thread;
    const shared_ptr<SingleThreadTaskRunner> m_bg_thread;
    core::Http m_bg_http;
};

}
