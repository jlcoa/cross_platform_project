//
//  i_dao_factory.cpp
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#include "i_dao_factory.hpp"

#include "../core/pal.hpp"
#include "../interface/i_file_storage_provider.hpp"

#include "../sqlite/sqlite.hpp"

#include "../utils/utils.hpp"

namespace core {
    
    DatabaseProvider::DatabaseProvider(const std::string &rootPath) {
        m_readDb = createDb(rootPath);
        m_writeDb = createDb(rootPath);
    }
    
    void AbstractDao::addColumn(const std::string &colunm, const std::string &type) {
        auto holder = std::make_shared<ModelHolder>();
        holder->column = colunm;
        holder->type = type;
        holder->position = (int32_t) m_columnVector.size();
        m_columnVector.push_back(holder);
        
        m_columnMap.insert({colunm, holder});
        
    }
    
    std::string AbstractDao::getDbSchema() {
        
        std::string sql = "CREATE TABLE IF NOT EXISTS " + m_tableName + " (";
        
        for (auto iter = m_columnVector.begin(); iter != m_columnVector.end(); iter ++) {
            
            auto model = *iter;
            
            sql += "`" + model->column + "` " + model->type + ", ";
        }
        
        sql += " PRIMARY KEY(`" + m_primaryKey + "`) );";
        
        return std::move(sql);
        
    }
    
    void AbstractDao::initTable() {
        
        std::string dbScript = getDbSchema();
        m_dbProvider->getDatabase(DatabaseType::WRITE)->exec(dbScript);
    }
    
//    void AbstractDao::saveModel(std::shared_ptr<core_gen::Model> model, std::shared_ptr<DataChangeMap> changeMap) {
//        
//    }
//    
//    void AbstractDao::saveModels(std::vector<core_gen::Model>& models, std::shared_ptr<DataChangeMap> changeMap) {
//        
//    }
    
    std::shared_ptr<std::vector<EModelChangeType>> AbstractDao::save(std::vector<std::map<std::string, sqlite::Value>>& rows) {
        
        auto saveTypeVector = std::make_shared<std::vector<EModelChangeType>>(rows.size());
        
        for (auto item : rows) {
            saveTypeVector->push_back(save(item));
        }
        
        return saveTypeVector;
    }
    
    EModelChangeType AbstractDao::save(std::map<std::string, sqlite::Value> &row) {
        
        EModelChangeType saveType;
        
        auto db = m_dbProvider->getDatabase(DatabaseType::WRITE);
        
        std::string updateSql = "UPDATE `" + m_tableName + "` SET ";
        std::string insertSql = "INSERT INTO `" + m_tableName + "` (";
        
        std::string insertColumnSql = "";
        int index = 1;
        for (auto iter = row.begin(); iter != row.end(); iter ++, index ++) {
            updateSql += "`" + iter->first + "` = ?" + std_patch::to_string(index);
            insertColumnSql += "`" + iter->first + "`";
            if (iter != --row.end()) {
                insertColumnSql += ", ";
                updateSql += ", ";
            }
        }
        
        updateSql += " WHERE `" + m_primaryKey + "` = ?" + std_patch::to_string(index) + " ;";
        
        insertSql += insertColumnSql;
        
        insertSql+= ") VALUES (";
        index = 1;
        for (auto iter = row.begin(); iter != row.end(); iter ++, index ++) {
            insertSql += "?" + std_patch::to_string(index);
            if (iter != --row.end()) {
                insertSql += ", ";
            }
        }
        
        insertSql += ");";
        
        auto updateStmt = db->prepare(updateSql);
        auto insertStmt = db->prepare(insertSql);
        
        sqlite::TransactionStmts transaction_stmts {db};
        sqlite::WriteTransaction guard {transaction_stmts};
        
        updateStmt->reset();
        insertStmt->reset();
 
        updateStmt->bind(index, row.find(m_primaryKey)->second);
        
        index = 1;
        for (auto iter = row.begin(); iter != row.end(); iter ++, index ++) {
            updateStmt->bind(index, iter->second);
            insertStmt->bind(index, iter->second);
        }

        if ( updateStmt->exec() == 0 ) {
            insertStmt->reset();
            insertStmt->exec();
            saveType = EModelChangeType::Inserted;
        }
        else {
            saveType = EModelChangeType::Updated;
        }
        guard.commit();
        
        return saveType;
    }
    
    void AbstractDao::deleteInternal(const std::string & where, const std::vector<sqlite::Value> & value) {
        
        std::string sql = " delete from `" + m_tableName + "` ";
        
        if (!where.empty()) {
            sql += " where " + where;
        }
        
        shared_ptr<sqlite::Stmt> queryStmt = m_dbProvider->getDatabase(DatabaseType::READ)->prepare(sql);
        
        if (value.size() > 0) {
            int index = 1;
            for (auto iter = value.begin(); iter != value.end(); iter ++, index ++) {
                queryStmt->bind(index, *iter);
            }
        }
        
        queryStmt->exec();
        
    }
    
    sqlite::Cursor AbstractDao::queryInternal(const std::vector<std::string> &column, const std::map<std::string, sqlite::Value> &where, const std::vector<std::string> &orderBy, size_t count, size_t offset) {
        
        std::string sql = " select ";
        if (column.size() > 0) {
            for (auto iter = column.begin(); iter != column.end(); iter ++) {
                sql += " `" + *iter + "` ";
                
                if (iter != --column.end()) {
                    sql += ", ";
                }
            }
        }
        else {
            sql += " * ";
        }
        sql += " from `" + m_tableName + "` ";
        
        if (where.size() > 0) {
            
            sql += " where ";
            
            std::string whereSql = "";
            int index = 1;
            for (auto iter = where.begin(); iter != where.end(); iter ++, index ++) {
                
                auto key = iter->first;
                auto value = std_patch::to_string(index);
                std::string w = string_format(key, index);
                
                whereSql +=w;
                if (iter != --where.end()) {
                    whereSql += " AND ";
                }
            }
            
            sql += whereSql;
        }
        
        if (orderBy.size() > 0) {
            sql += " order by ";
            
            for (auto iter = orderBy.begin(); iter != orderBy.end(); iter ++) {
                sql += " " + *iter + " ";
                
                if (iter != --orderBy.end()) {
                    sql += ", ";
                }
            }
        }
        
        if (count > 0) {
            sql += " limit " + std_patch::to_string(offset) + ", " + std_patch::to_string(count);
        }
        
        shared_ptr<sqlite::Stmt> queryStmt = m_dbProvider->getDatabase(DatabaseType::READ)->prepare(sql);
        
        if (where.size() > 0) {
            int index = 1;
            for (auto iter = where.begin(); iter != where.end(); iter ++, index ++) {
                queryStmt->bind(index, iter->second);
            }
        }
        
        return queryStmt->exec_query();
        
    }
    
    void AbstractDao::fillStringValue(sqlite::Cursor &cursor, int pos,  std::experimental::optional<std::string> &target) {
        if (!cursor.is_null(pos)) {
            target = cursor.string_value(pos);
        }
    }
    
    void AbstractDao::extractStringValue(std::map<std::string, sqlite::Value>& content, const std::string& key, std::experimental::optional<std::string> &value) {
        
        if (value) {
            content.insert({key, *(value)});
        }
    }
    
    void AbstractDao::fillIntValue(sqlite::Cursor &cursor, int pos,  std::experimental::optional<int64_t> &target) {
        if (!cursor.is_null(pos)) {
            target = cursor.int64_value(pos);
        }
    }
    
    void AbstractDao::extractIntValue(std::map<std::string, sqlite::Value>& content, const std::string& key, std::experimental::optional<int64_t> &value) {
        
        if (value) {
            content.insert({key, *(value)});
        }
    }
}