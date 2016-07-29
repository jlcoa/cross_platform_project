//
//  key_value_storage.cpp
//  rccore
//
//  Created by Nick Moskalenko on 6/3/15.
//
//

#include "key_value_storage.hpp"

namespace core {
    
//    const char* const kTagKeyValueStorage = "KeyValueStorage";
    
    void KeyValuesStorage::open(const std::string& filepath) {
        SYNCHRONIZE_BLOCK();
        
        _filename = filepath;
        
        _storage = std::make_shared<CSimpleIniA>();
        _storage->SetUnicode();
        if(_storage->LoadFile(_filename.c_str())) {
        } else {
            _isOpened = true;
        }
    }
    
    
    bool KeyValuesStorage::isOpened() {
        return _isOpened;
    }
    
    void KeyValuesStorage::close() {
        SYNCHRONIZE_BLOCK();
        _storage = nullptr;
        _isOpened = false;
    }
    
    void KeyValuesStorage::drop() {
        SYNCHRONIZE_BLOCK();
        _storage = nullptr;
        remove(_filename.c_str());
        _filename = "";
    }
    
    void KeyValuesStorage::putBool(const std::string &section, const std::string &key, bool value) {
        SYNCHRONIZE_BLOCK();
        
        _storage->SetBoolValue(section.c_str(), key.c_str(), value);
        
        //TODO : move to save() function
        _storage->SaveFile(_filename.c_str());
    }
    
    bool KeyValuesStorage::getBool(const std::string &section, const std::string &key, bool defaultValue) {
        return _storage->GetBoolValue(section.c_str(), key.c_str(), defaultValue);
    }
    
    void KeyValuesStorage::putString(const std::string& section, const std::string& key, const std::string& value) {
        SYNCHRONIZE_BLOCK();
        
        _storage->SetValue(section.c_str(), key.c_str(), value.c_str());
        
        //TODO : move to save() function
        _storage->SaveFile(_filename.c_str());
        
    }
    
    std::shared_ptr<std::string> KeyValuesStorage::getString(const std::string& section, const std::string& key) {
        SYNCHRONIZE_BLOCK();
        
        const char *value = _storage->GetValue(section.c_str(), key.c_str());
        
        if (value == NULL) {
            return nullptr;
        }
        
        return std::make_shared<std::string>(value);
    }
    
    void KeyValuesStorage::deleteValue(const std::string& section, const std::string& key) {
        SYNCHRONIZE_BLOCK();
        
        _storage->Delete(section.c_str(), key.c_str());
        
        //TODO : move to save() function
        _storage->SaveFile(_filename.c_str());
        
    }
    
}