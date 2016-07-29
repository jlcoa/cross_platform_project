//
//  logger.cpp
//  core
//
//  Created by Steve Chen on 2/15/16.
//
//

#include "logger.hpp"

namespace core {
    
    std::shared_ptr<Logger> Logger::instance() {
        static std::shared_ptr<Logger> s_logger;
        static std::once_flag flag;
        std::call_once(flag, [] {
            s_logger = std::make_shared<Logger>();
        });
        return s_logger;
    }
    
}