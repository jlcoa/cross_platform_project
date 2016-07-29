/*
 * Copyright (c) 2016 Steve Chen. All rights reserved.
 */

#pragma once

#include <mutex>

namespace core {
    
    class TaskId final {
    public:
        static int generateTaskId();
        
    private:
        static int s_taskId;
        static std::mutex s_mutex;
    };
    
}

