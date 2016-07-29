//
//  task_dispatcher.hpp
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#pragma once

#include <functional>
#include "../interface/i_task_dispatcher.hpp"

namespace core {
    
    void dispatchToUI(std::function<void()> task);
    
    void dispatchToCore(std::function<void()> task);
    
    void dispatchToBG(std::function<void()> task);
    
    void dispatchToDB(std::function<void()> task);
    
}