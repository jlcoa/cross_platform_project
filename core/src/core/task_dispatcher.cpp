//
//  task_dispatcher.cpp
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#include "task_dispatcher.hpp"
#include "task_impl.hpp"
#include "task_id.hpp"

#include "../interface/i_task_dispatcher.hpp"

#include "../core/pal.hpp"

namespace core {
    
    void dispatchToUI(std::function<void()> task) {
        auto wtask = std::make_shared<TaskImpl>(task, TaskId::generateTaskId());
        getPal()->getTaskDispatcher()->dispatchToUI(wtask);
    }
    
    void dispatchToCore(std::function<void()> task) {
        auto wtask = std::make_shared<TaskImpl>(task, TaskId::generateTaskId());
        getPal()->getTaskDispatcher()->dispatchToCore(wtask);
    }
    
    void dispatchToDB(std::function<void()> task) {
        auto wtask = std::make_shared<TaskImpl>(task, TaskId::generateTaskId());
        getPal()->getTaskDispatcher()->dispatchToDB(wtask);
    }
    
    void dispatchToBG(std::function<void()> task) {
        auto wtask = std::make_shared<TaskImpl>(task, TaskId::generateTaskId());
        getPal()->getTaskDispatcher()->dispatchToBG(wtask);
    }
    
}