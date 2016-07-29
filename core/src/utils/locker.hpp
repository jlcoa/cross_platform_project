//
//  locker.hpp
//  core
//
//  Created by Steve Chen on 6/23/15.
//
//

#pragma once

#include <mutex>
#include <memory>

#define SYNCHRONIZE_BLOCK_WITH(obj) auto lockBlockObject = obj->objectLockGuard()
#define SYNCHRONIZE_BLOCK() SYNCHRONIZE_BLOCK_WITH(_locker)

namespace core {
    
    class Locker {
        
    public:
        Locker();
        virtual ~Locker();
        
        virtual void lockObject() final;
        virtual void unlockObject() final;
        virtual std::shared_ptr<std::lock_guard<std::mutex>> objectLockGuard() final;
        
    private:
        std::shared_ptr<std::mutex> _mutex;
    };
    
}

