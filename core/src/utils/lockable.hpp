//
//  locable.hpp
//  core
//
//  Created by Steve Chen on 5/25/15.
//
//

#pragma once

#include "locker.hpp"

namespace core {
    
    class Lockable {
    
    protected:
        
        Lockable(): _locker(std::make_shared<Locker>()) {};
        
        virtual ~Lockable() {};
        
        std::shared_ptr<Locker> _locker;
    };
    
}

