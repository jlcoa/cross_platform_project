//
//  i_biz_service_factory.hpp
//  core
//
//  Created by Steve Chen on 1/30/16.
//
//

#pragma once

#include "stl.hpp"

#include "../interface/e_callback_result.hpp"
#include "../interface/r_action_result.hpp"

#include "../core/pal.hpp"

#include "../core/task_dispatcher.hpp"

#include "../dao/data_change_map.hpp"

namespace core {
    
    class IUnifiedFactory;
    
    
    template<class T>
    class CallbackResult {
        
    public:
        
        std::shared_ptr<core_gen::RActionResult> result;
        std::shared_ptr<T> value;
        
        std::function<void(std::shared_ptr<T> response)> callback;
        
        
        static std::shared_ptr<CallbackResult<T>> createCallbackResult(std::shared_ptr<core_gen::RActionResult> result, std::shared_ptr<T> value = nullptr) {
            
            auto cresult = std::make_shared<CallbackResult<T>>();
            
            cresult->result = result;
            cresult->value = value;
            
            return cresult;
        }
        
    };
    
    class IBizService {
        
    public:
        
        virtual ~IBizService() {};
    };
    
    
    class AbstractBizService {
    
    public:
        AbstractBizService(std::weak_ptr<IUnifiedFactory> unifiedFactory):m_unifiedFactory(unifiedFactory) {};
        
    protected:
        
        std::weak_ptr<IUnifiedFactory> m_unifiedFactory;
        
        template<class T>
        void addBizObserver(std::vector<std::weak_ptr<T>> &observers, std::weak_ptr<T> observer) {
            observers.push_back(observer);
        }
        
        template<class T>
        void removeBizObserver(std::vector<std::weak_ptr<T>> &observers, std::weak_ptr<T> observer) {
            typename std::vector<std::weak_ptr<T>>::iterator iter = observers.begin();
            for (; iter != observers.end(); iter ++) {
                if (iter->lock().get() == observer.lock().get()) {
                    break;
                }
            }
            if (iter != observers.end()) {
                observers.erase(iter);
            }
        }
        
        template<class T>
        void notifyObserver4Change(std::vector<std::weak_ptr<T>> &observers, std::function<void(std::shared_ptr<T> ot)> func) {
            
            std::vector<std::weak_ptr<T>> idleObservers = std::vector<std::weak_ptr<T>>();
            
            for (auto it = observers.begin(); it != observers.end(); ++it) {
                auto observer = (*it).lock();
                if (observer) {
                    func(observer);
                }
                else {
                    idleObservers.push_back(observer);
                }
            }
            
            if (!idleObservers.empty()) {
                for (auto iter = idleObservers.begin(); iter != idleObservers.end(); iter ++) {
                    removeBizObserver(observers, *iter);
                }
            }
        }
        
        void storeData(std::function<void(std::shared_ptr<DataChangeMap> changeMap)> func) {
            
            auto changeMap = std::make_shared<DataChangeMap>();
            func(changeMap);
            notifyDataChange(changeMap);
            
        }
        
        void notifyDataChange(std::shared_ptr<DataChangeMap> changeMap);
        
    };
    
    class IBizServiceFactory {
        
    public:
        
        virtual std::shared_ptr<IBizService> getService(const std::string& key) = 0;
        
        template<class T>
        std::shared_ptr<T> getService() {
            return std::dynamic_pointer_cast<T>(getService(typeid(T).name()));
        };
        
    };
    
}