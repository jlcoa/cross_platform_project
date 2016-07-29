/*
 * Copyright (c) 2015 Steve Chen. All rights reserved.
 */

#include "task_impl.hpp"

namespace core{
    
    TaskImpl::TaskImpl(std::function<void()> taskFunc, int taskId)
    : _fn {std::move(taskFunc)}, _taskId {taskId} {
    }
    
    void TaskImpl::execute() {
        _fn();
    }
    
    int TaskImpl::getId() {
        return _taskId;
    }
    
}
