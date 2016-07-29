//
//  data_change_map.hpp
//  core
//
//  Created by Steve Chen on 2/29/16.
//
//

#pragma once

#include "stl.hpp"
#include "../model/model.hpp"
#include <unordered_map>

namespace core {
    
    typedef enum {
        Inserted,
        Updated,
        Deleted,
        Moved,
    } EModelChangeType;
    
    typedef std::vector<std::shared_ptr<core_gen::Model>> ModelVector;
    typedef std::unordered_map<EModelChangeType, std::shared_ptr<ModelVector>> ModelChangeTypeMap;
    typedef std::unordered_map<std::string, std::shared_ptr<ModelChangeTypeMap>> ModelChangeMap;
    
    class DataChangeMap {
        
    public:
        
        template<class T>
        void addModelChanged(std::shared_ptr<T> model, EModelChangeType changeType) {
            
            if (m_modelChangeMap == nullptr)
            {
                m_modelChangeMap = std::make_shared<ModelChangeMap>();
                
            }
            
            auto modelName = typeid(T).name();
            
            typename ModelChangeMap::const_iterator changeTypeMapIterator = m_modelChangeMap->find(modelName);
            
            if (changeTypeMapIterator == m_modelChangeMap->end())
            {
                
                std::shared_ptr<core_gen::Model> m = model;
                
                ModelVector modelVector;
                modelVector.push_back(m);
                
                ModelChangeTypeMap modelChangeTypeMap;
                modelChangeTypeMap.insert({changeType, std::make_shared<ModelVector>(modelVector)});
                
                m_modelChangeMap->insert({modelName, std::make_shared<ModelChangeTypeMap>(modelChangeTypeMap)});
                
            }
            else
            {
                std::shared_ptr<ModelChangeTypeMap> changeTypeMap = changeTypeMapIterator->second;
                typename ModelChangeTypeMap::const_iterator gotChangeTypeMap = changeTypeMap->find(changeType);
                
                if (gotChangeTypeMap == changeTypeMapIterator->second->end())
                {
                    ModelVector modelVector;
                    modelVector.push_back(model);
                    
                    changeTypeMap->insert({changeType, std::make_shared<ModelVector>(modelVector)});
                }
                else
                {
                    std::shared_ptr<ModelVector> modelVector = gotChangeTypeMap->second;
                    modelVector->push_back(model);
                }
            }
        }
        
        auto getModelMap() {
            return m_modelChangeMap;
        };
        
        template<class T>
        std::shared_ptr<ModelChangeTypeMap> modelChangeTypeMap() {
            return (*m_modelChangeMap)[typeid(T).name()];
        }
        
    private:
         std::shared_ptr<ModelChangeMap> m_modelChangeMap;
        
    };
    
}