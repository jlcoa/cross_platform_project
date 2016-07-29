//
//  Utils.h
//  core
//
//  Created by JianWei Chen on 6/23/15.
//
//

#pragma once

#include <cstdlib>
#include <string>

#include <pthread.h>
#include <future>

#include <iostream>
#include <memory>

namespace core {
    
    class Utils {
    public:
        
//        static std::thread::id getCurrentThreadId();
//        
//        static int64_t currentTime();
//        
//        static bool isUiThread();
//        
//        static std::thread::id ui_thread_id;
//        
//        static std::thread::id bg_thread_id;
//        
//        static string currentStringTime();
        
    };
    
    template<typename ... Args>
    std::string string_format(const std::string& format, Args ... args){
        size_t size = 1 + snprintf(nullptr, 0, format.c_str(), args ...);
        std::unique_ptr<char[]> buf(new char[size]);
        std::snprintf(buf.get(), size, format.c_str(), args ...);
        return std::string(buf.get(), buf.get() + size);
        
        
    }
}
