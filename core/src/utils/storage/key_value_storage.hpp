//
//  key_value_storage.hpp
//  rccore
//
//  Created by Nick Moskalenko on 6/3/15.
//
//

#pragma once

#include <simpleini/SimpleIni.h>
#include "../lockable.hpp"

#include <string>
#include <memory>

namespace core {
    
    
    /** @class KeyValuesStorage
     * @brief Provides basic KeyValueStorage for Core library.
     * Shouldn't be used directly: settings clases should inherite this KeyValuesStorage to provide more specific functionality,
     * for example see @class CoreSettings
     *
     * Thread-safe.
     *
     */
    class KeyValuesStorage : public Lockable {
        
    public:
        /**
         @brief opens storage for usage
         @param filepath storage file full path
         */
        void open(const std::string& filepath);
        
        /**
         @brief checks if storage is opened and ready for data access
         */
        bool isOpened();
        
        /**
         @brief closes storage
         */
        void close();
        
        /**
         @brief closes and drops storage completely
         */
        void drop();
        
        /**
         @brief saves string value for corresponding key
         @param section key/value pair section
         @param key key by which value may be received in future
         @param value value we want to store
         */
        void putString(const std::string& section, const std::string& key, const std::string& value);
        
        /**
         @brief retrieves string value for corresponding key
         @param section key/value pair section
         @param key key by which we want to find the value
         @return found value or nullptr if not found
         */
         std::shared_ptr<std::string> getString(const std::string& section, const std::string& key);
        
        
        void putBool(const std::string& section, const std::string& key, bool value);
        
        bool getBool(const std::string& section, const std::string& key, bool defaultValue);
        
        /**
         @brief deletes value for corresponding key
         @param section key/value pair section
         @param key key by which we want to delete the value
         */
        void deleteValue(const std::string& section, const std::string& key);
        
    protected:
        std::string _filename;
        
    private:
        bool _isOpened;
        std::shared_ptr<CSimpleIniA> _storage;
        
    };
    
}