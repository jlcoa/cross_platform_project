//
//  setting.cpp
//  core
//
//  Created by Steve Chen on 2/20/16.
//
//

#include "setting.hpp"

#include "../core/pal.hpp"

namespace core {
    
    const std::string KEY_SECTION_GLOBAL = "global";
    
    const std::string Setting::KEY_USER = "KEY_USER";
    
    Setting::Setting(const std::string &path):m_filePath(path) {
        m_storage = std::make_shared<KeyValuesStorage>();
        m_storage->open(path);
    }
    
    void Setting::putString(const std::string &key, const std::string &value) {
        m_storage->putString(KEY_SECTION_GLOBAL, key, value);
    }
    
    void Setting::deleteByKey(const std::string &key) {
        m_storage->deleteValue(KEY_SECTION_GLOBAL, key);
    }
    
    std::shared_ptr<std::string> Setting::getString(const std::string &key) {
        return m_storage->getString(KEY_SECTION_GLOBAL, key);
    }
    
    std::shared_ptr<Setting> Setting::globalSetting() {
        
        static std::shared_ptr<Setting> s_globalSetting;
        static std::once_flag flag;
        
        std::call_once(flag, [] {
            
            auto path = getPal()->getFileStorageProvider()->getDocumentsPath("global_setting.ini");
            
            s_globalSetting = std::make_shared<Setting>(path);
        });
        
        return s_globalSetting;
    }
    
}