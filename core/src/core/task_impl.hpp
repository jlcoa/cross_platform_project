/*
 * Copyright (c) 2015 Steve Chen. All rights reserved.
 */

#pragma once

#include "../interface/i_task.hpp"
#include <functional>

namespace core {
    
    class TaskImpl final : public core_gen::ITask {
    public:
        TaskImpl(std::function<void()> taskFunc, int taskId);
        
        void execute() override;
        int getId() override;
        
    private:
        std::function<void()> _fn;
        int _taskId;
    };
    
}
