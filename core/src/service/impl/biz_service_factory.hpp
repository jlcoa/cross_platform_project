//
//  biz_service_factory.hpp
//  core
//
//  Created by Steve Chen on 2/13/16.
//
//

#pragma once
#include "../i_biz_service_factory.hpp"

namespace core {
    
    class BizServiceFactory: public IBizServiceFactory, public std::enable_shared_from_this<BizServiceFactory> {
        
    public:
        BizServiceFactory(std::weak_ptr<IUnifiedFactory> unifiedFactory):m_unifiedFactory{unifiedFactory}, m_serviceMap{} {};
        
        std::shared_ptr<IBizService> getService(const std::string& key) override;
        
        static shared_ptr<IBizServiceFactory> createBizServiceFactory(std::shared_ptr<IUnifiedFactory> unifiedFactory);
        
    private:
        
        template<class Inter, class Impl>
        void registerService() {
            auto service = std::make_shared<Impl>(m_unifiedFactory);
            m_serviceMap.insert(std::make_pair(typeid(Inter).name(), service));
        };
        
        template<class Inter>
        void unregisterService() {
            m_serviceMap.erase(typeid(Inter).name());
        };
        
        std::weak_ptr<IUnifiedFactory> m_unifiedFactory;
        
        std::map<std::string, shared_ptr<IBizService>> m_serviceMap;
    };
    
}
