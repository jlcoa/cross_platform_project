#pragma once
#include "stl.hpp"
#include "json_store.hpp"
#include "../sqlite/db.hpp"
#include "../sqlite/transaction.hpp"

namespace core {

class SqliteStore final : public core::JsonStore {
  public:
    SqliteStore(const string& db_path);
    virtual json11::Json get(const string& key) override;
    virtual void set(const string& key, const json11::Json& value) override;
  private:
    shared_ptr<sqlite::Db> m_db;
    sqlite::TransactionStmts m_stmts;
    shared_ptr<sqlite::Stmt> m_insert;
    shared_ptr<sqlite::Stmt> m_update;
    shared_ptr<sqlite::Stmt> m_select;
};

}
