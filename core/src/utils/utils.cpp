//
//  Utils.cpp
//  core
//
//  Created by JianWei Chen on 6/23/15.
//
//

#include "utils.hpp"
//#include <uuid/uuid.h>

namespace core {
    
    using namespace std;
    
//    std::thread::id Utils::getCurrentThreadId() {
//        return std::this_thread::get_id();
//    }
//    
//    bool Utils::isUiThread() {
//        return Utils::getCurrentThreadId() == Utils::ui_thread_id;
//    }
//    
//    
//    int64_t Utils::currentTime() {
//        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
//        auto duration = now.time_since_epoch();
//        auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
//        
//        return millis;
//    }
//    
//    string Utils::trim(const string &str, const string &whitespace) {
//        const auto strBegin = str.find_first_not_of(whitespace);
//        if (strBegin == std::string::npos)
//            return ""; // no content
//        
//        const auto strEnd = str.find_last_not_of(whitespace);
//        const auto strRange = strEnd - strBegin + 1;
//        
//        return str.substr(strBegin, strRange);
//    }
    
}
