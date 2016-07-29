//
//  logger.hpp
//  core
//
//  Created by Steve Chen on 2/15/16.
//
//

#pragma once
#include "pal.hpp"
#include "../interface/i_log.hpp"
#include "../network/common/string_algo.hpp"

namespace core {
    
    class Logger {
        
    public:

            template<typename... Parameters>
            void w(const std::string& tag, const Parameters&... parameters)
            {
                std::string message = string_algo::combineString(parameters...);
                getPal()->getLog()->warning(tag, message);
            }
            
            template<typename... Parameters>
            void e(const std::string& tag, const Parameters&... parameters)
            {
                std::string message = string_algo::combineString(parameters...);
                getPal()->getLog()->error(tag, message);
            }
            
            template<typename... Parameters>
            void i(const std::string& tag, const Parameters&... parameters)
            {
                std::string message = string_algo::combineString(parameters...);
                getPal()->getLog()->info(tag, message);
            }
            
            template<typename... Parameters>
            void d(const std::string& tag, const Parameters&... parameters)
            {
                std::string message = string_algo::combineString(parameters...);
                getPal()->getLog()->debug(tag, message);
            }
            
            template<typename... Parameters>
            void v(const std::string& tag, const Parameters&... parameters)
            {
                std::string message = string_algo::combineString(parameters...);
                getPal()->getLog()->verbose(tag, message);
            }
            
            static std::shared_ptr<Logger> instance();
        
    };
}

#define KV(v)   #v ":", v, " "

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG_WARNING_F(tag, ...) core::Logger::instance()->w(tag, __FILENAME__, ":", __LINE__ , " ", __FUNCTION__,"() ", ##__VA_ARGS__)
#define LOG_ERROR_F(tag, ...) core::Logger::instance()->e(tag, __FILENAME__, ":", __LINE__ , " ",__FUNCTION__,"() ", ##__VA_ARGS__)
#define LOG_INFO_F(tag, ...) core::Logger::instance()->i(tag,  __FILENAME__, ":", __LINE__ , " ",__FUNCTION__,"() ", ##__VA_ARGS__)
#define LOG_DEBUG_F(tag, ...) core::Logger::instance()->d(tag,  __FILENAME__, ":", __LINE__ , " ",__FUNCTION__,"() ", ##__VA_ARGS__)
#define LOG_VERBOSE_F(tag, ...) core::Logger::instance()->v(tag,  __FILENAME__, ":", __LINE__ ," ",__FUNCTION__,"() ", ##__VA_ARGS__)
#define LOG_EXCEPTION_F(tag, ...) core::Logger::instance()->e(tag,  __FILENAME__, ":", __LINE__ , " ",__FUNCTION__,"() ", ##__VA_ARGS__)
