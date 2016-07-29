#pragma once

#include <string>
#include <time.h>
#include <iomanip>
#include <sstream>

namespace time_utils
{
    inline std::time_t parseTimeString(const std::string& str, std::string format) {
        struct std::tm tm;
#ifdef _MSC_VER
        std::istringstream ss(str);
        ss >> std::get_time(&tm, format.c_str());
#else
        strptime(str.c_str(), format.c_str(), &tm);
#endif
        return mktime(&tm);
    }
    
    inline std::string currentDateTime() {
        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
#ifdef _MSC_VER
        localtime_s(&tstruct, &now);
#else
        tstruct = *localtime(&now);
#endif // __MSC_VER__
        
        // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
        // for more information about date/time format
        strftime(buf, sizeof(buf), "%Y-%m-%d-%H%M%S", &tstruct);
        return buf;
    }
}
