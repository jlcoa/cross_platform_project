/*
 * Copyright (c) 2015 Steve Chen. All rights reserved.
 */

#include "task_id.hpp"

namespace core {
    
    int TaskId::s_taskId = 0;
    std::mutex TaskId::s_mutex;
    
    int TaskId::generateTaskId() {
        int taskId;
        
        {
            std::lock_guard<std::mutex> lock(s_mutex);
            ++s_taskId;
            taskId = s_taskId;
        }
        
        return taskId;
    }
    
}
