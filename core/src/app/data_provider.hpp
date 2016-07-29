//
//  data_provider.hpp
//  core
//
//  Created by Steve Chen on 2/21/16.
//
//

#pragma once

#include "../interface/i_data_provider.hpp"
#include "../app/unified_factory.hpp"
#include "../service/i_data_change_notification_service.hpp"

namespace core {
    
    class IUnifiedFactory;
    
    class DataProvider: public core_gen::IDataProvider, public IDataChangeListener, public std::enable_shared_from_this<DataProvider> {
    
    public:
        
        DataProvider(std::weak_ptr<IUnifiedFactory> unifedFactroy): m_unifedFactroy(unifedFactroy), m_inited(false) {
            
        };
        
        bool hasContact(const std::string & id) override;
        
        bool hasGroup(const std::string & id) override;
        
        core_gen::RContact getContact(const std::string & id) override;
        
        core_gen::RGroup getGroup(const std::string & id) override;
        
        void onDataChanged(const string& modelName, shared_ptr<ModelChangeTypeMap> changeMap) override;
        
        void setDelegate(const std::shared_ptr<core_gen::IDataChangeDelegate> & delegate) override;
        
    private:
        void makesureInited();
        
    private:
        std::weak_ptr<IUnifiedFactory> m_unifedFactroy;
        bool m_inited;
        
        std::set<std::string> unKnownContactIdSet;
        std::set<std::string> unKnownGroupIdSet;
        
        std::shared_ptr<core_gen::IDataChangeDelegate> m_delegate;
        
    };
    
}
