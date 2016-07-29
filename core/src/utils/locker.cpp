//
//  locker.cpp
//  core
//
//  Created by Steve Chen on 6/23/15.
//
//

#include "locker.hpp"

namespace core {
    
    Locker::Locker() {
        _mutex = std::make_shared<std::mutex>();
    }
    
    Locker::~Locker() {
    }
    
    void Locker::lockObject() {
        _mutex->lock();
    }
    
    void Locker::unlockObject() {
        _mutex->unlock();
    }
    
    std::shared_ptr<std::lock_guard<std::mutex>> Locker::objectLockGuard() {
        return std::make_shared<std::lock_guard<std::mutex>>(*_mutex);
    }
    
}
