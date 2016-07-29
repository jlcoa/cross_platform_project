#pragma once
#include "../../interface/e_future_status.hpp"
#include "../../interface/r_future_error.hpp"
#include "../../interface/r_network_response.hpp"

#include <mutex>
#include <condition_variable>
#include <future>

namespace core {
    
    using namespace core_gen;
    
    template<typename Type>
    class Future {
    public:
        
        Future() : readyFlag(false)
        {
        }
        
        std::shared_ptr<Type> getValue() {
            waitFor(0);
            return value;
        }
        
        std::shared_ptr<RFutureError> getError() {
            waitFor(0);
            return error;
        }
        
        std::shared_ptr<RNetworkResponse> getData() {
            waitFor(0);
            return data;
        }
        
        bool waitFor(int64_t milliseconds) {
            std::unique_lock<std::mutex> ul(readyFlagMutex);
            if (readyFlag)
                return true;
            if (0 == milliseconds) {
                condition.wait(ul, [this] { return readyFlag; });
                return true;
            } else
                return condition.wait_for(ul, std::chrono::milliseconds(milliseconds), [this] { return readyFlag; });
        }
        bool waitFor_wrt(int64_t milliseconds) {
            if (0 == milliseconds) {
                return waitFor(milliseconds);
            }
            else {
                auto fut = std::async(std::launch::async, [this, milliseconds] {
                    return waitFor(milliseconds);
                });
                return fut.get();
            }
        }
        EFutureStatus getStatus() {
            std::lock_guard<std::mutex> lock(readyFlagMutex);
            if (false == readyFlag)
                return EFutureStatus::EXECUTING;
            else if (nullptr != value)
                return EFutureStatus::COMPLETE;
            else
                return EFutureStatus::FAILED;
        }
        
        void setResult(std::shared_ptr<Type> value, std::shared_ptr<RFutureError> error, std::shared_ptr<RNetworkResponse> data) {
            this->value = value;
            this->error = error;
            this->data = data;
            notifyReady();
        }
        
    private:
        void notifyReady() {
            {
                std::lock_guard<std::mutex> lock(readyFlagMutex);
                readyFlag = true;
            }
            condition.notify_all();
        }
        
    private:
        std::shared_ptr<Type> value;
        std::shared_ptr<RFutureError> error;
        std::shared_ptr<RNetworkResponse> data;
        
        bool readyFlag;
        std::mutex readyFlagMutex;
        std::condition_variable condition;
    };
    
}
