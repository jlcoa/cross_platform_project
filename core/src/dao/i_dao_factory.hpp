//
//  i_dao_factory.hpp
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#pragma once
#include "stl.hpp"

#include "../sqlite/sqlite.hpp"

#include "../core/pal.hpp"
#include "../interface/i_file_storage_provider.hpp"

#include <typeindex>
#include <map>

#include "data_change_map.hpp"

namespace core {
    
    enum class DatabaseType: int {
        READ,
        WRITE
    };
    
    class IUnifiedFactory;
    
    class DatabaseProvider {
        
    public:
        
        static std::shared_ptr<core::sqlite::Db> createDb(const std::string &rootPath) {
            
            getPal()->getFileStorageProvider()->createRelativeFolder(rootPath);
            std::string dbFilePath = getPal()->getFileStorageProvider()->getDocumentsPath(rootPath + "/nextuc.sqlite");
            return core::sqlite::Db::open(dbFilePath);
            
        };
        
        DatabaseProvider(const std::string &rootPath);
        
        std::shared_ptr<core::sqlite::Db> getDatabase( DatabaseType type = DatabaseType::WRITE) {
            return type == DatabaseType::READ ? m_readDb : m_writeDb;
        };
        
        void enableWal() {
            m_writeDb->enable_wal();
        };
        
    private:
        
        std::shared_ptr<core::sqlite::Db> m_readDb;
        std::shared_ptr<core::sqlite::Db> m_writeDb;
        
    };
    
    class IDao {
    public:
        virtual void onCreate(std::shared_ptr<DatabaseProvider> dbProvider) = 0;
        virtual void onUpgrade(int oldVersion , int newVersion) = 0;
        
    };
    
    class IDaoFactory;
    
    const static std::string SQL_BLOB = "BLOB";
    const static std::string SQL_TEXT = "TEXT";
    const static std::string SQL_INTEGER = "INTEGER";
    
    class ModelHolder {
    public:
        std::string column;
        std::string type;
        int32_t position;
    };
    
    class AbstractDao {
        
    public:
        
        void onCreate(std::shared_ptr<DatabaseProvider> dbProvider) {
            m_dbProvider = dbProvider;
            initTable();
        };
        
        AbstractDao(std::weak_ptr<IDaoFactory> df, const std::type_index &modelType): m_daoFactory{df}, m_modelType(modelType),m_tableName{modelType.name()} {};
        
        const std::type_index& getModelType() const {return m_modelType;};
        
    protected:
        
        virtual std::map<std::string, sqlite::Value> toDb(std::shared_ptr<core_gen::Model> model) = 0;
        
        virtual std::shared_ptr<core_gen::Model> toObject(sqlite::Cursor &cursor) = 0;
        
        std::shared_ptr<DatabaseProvider> m_dbProvider;
        
        std::weak_ptr<IDaoFactory> m_daoFactory;
        
        std::type_index m_modelType;
        
        std::string m_tableName;
        
        std::map<std::string, std::shared_ptr<ModelHolder>> m_columnMap;
        
        std::vector<std::shared_ptr<ModelHolder>> m_columnVector;
        
        std::string m_primaryKey;
        
        std::string getDbSchema();
        
        void addColumn(const std::string &colunm, const std::string &type);
        
        void initTable();
        
        EModelChangeType save(std::map<std::string, sqlite::Value> &row);
        
        std::shared_ptr<std::vector<EModelChangeType>> save(std::vector<std::map<std::string, sqlite::Value>>& rows);
        
        void deleteInternal(const std::string & where, const std::vector<sqlite::Value> & value);
        
        sqlite::Cursor queryInternal(const std::vector<std::string> &column, const std::map<std::string, sqlite::Value> & where, const std::vector<std::string> &orderBy, size_t count = 0, size_t offset = 0);
        
        void fillStringValue(sqlite::Cursor &cursor, int pos, std::experimental::optional<std::string> &target);
        void fillIntValue(sqlite::Cursor &cursor, int pos, std::experimental::optional<int64_t> &target);
        
        void extractStringValue(std::map<std::string, sqlite::Value>& content,  const std::string& key, std::experimental::optional<std::string> &value);
        void extractIntValue(std::map<std::string, sqlite::Value>& content,  const std::string& key, std::experimental::optional<std::int64_t> &value);
        
        
        template<class T>
        void generateChangeMap(std::shared_ptr<T>&  model, EModelChangeType changeType, std::shared_ptr<DataChangeMap> changeMap) {
            
            if (changeMap) {
                changeMap->addModelChanged(model, changeType);
                
            }
        };
        
        template<class T>
        void deleteModelInternal(std::shared_ptr<T>& model, std::shared_ptr<DataChangeMap> changeMap) {
            
        }
        
        template<class T>
        void saveModelInternal(std::shared_ptr<T>& model, std::shared_ptr<DataChangeMap> changeMap) {
            auto content = toDb(model);
            auto type = AbstractDao::save(content);
            generateChangeMap(model, type, changeMap);
        };
        
        template<class T>
        void saveModelsInternal(const std::vector<std::shared_ptr<T>>& models, std::shared_ptr<DataChangeMap> changeMap) {
            
            for (auto model : models) {
                saveModelInternal(model, changeMap);
            }
            
        };
    };
    
    class IDaoFactory {
        
    public:
        
        virtual void clear() = 0;
        
        virtual void setupDb(const std::string &user) = 0;
        
        virtual std::shared_ptr<IDao> getDao (std::string &key) = 0;
        
        //        virtual std::shared_ptr<IDao> getDaoByModel(std::type_index type) = 0;
        
        template<class T> std::shared_ptr<T> getDao() {
            std::string key = typeid(T).name();
            return std::dynamic_pointer_cast<T>(getDao(key));
        };
        
        //        template<class T> std::shared_ptr<T> getDaoByModel() {
        //            return std::dynamic_pointer_cast<T>(getDaoByModel(std::type_index(typeid(T))));
        //        };
    };
    
}

