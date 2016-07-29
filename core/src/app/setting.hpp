//
//  setting.hpp
//  core
//
//  Created by Steve Chen on 2/20/16.
//
//

#pragma once

#include "../utils/storage/key_value_storage.hpp"
#include "stl.hpp"

#include "../dao/abstract_table_data_source.hpp"

namespace core {
    
    class Setting {
        
    public:
        
        Setting(const std::string& path);
        
        void putString(const std::string &key, const std::string &value);
        
        std::shared_ptr<std::string> getString(const std::string &key);
        
        void deleteByKey(const std::string &key);
        
        static std::shared_ptr<Setting> globalSetting();
        
        
        const static std::string KEY_USER;
        
    private:
        
        std::string m_filePath;
        std::shared_ptr<KeyValuesStorage> m_storage;
        
    };
    
}
