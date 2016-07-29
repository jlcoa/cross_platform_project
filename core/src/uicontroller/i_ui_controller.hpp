//
//  i_ui_controller.hpp
//  core
//
//  Created by Steve Chen on 2/16/16.
//
//

#pragma once

#include "stl.hpp"
#include "../dao/object_fetcher.hpp"

namespace core {
    
//    template<class Model, class DAO>
//    class AbstractTableDataSource {
//    
//    public:
//
//        AbstractTableDataSource(std::shared_ptr<ObjectFetcher<Model, DAO>> objectFetcher): m_objectFetcher(objectFetcher){};
//        
//        int32_t count() {
//            return m_objectFetcher->count();
//        };
//        
//        std::shared_ptr<Model> objectAt(int32_t index) {
//            return m_objectFetcher->objectAt(index);
//        }
//        
//        std::shared_ptr<ObjectFetcher<Model, DAO>> getFetcher() {
//            return m_objectFetcher;
//        }
//        
//    private:
//        std::shared_ptr<ObjectFetcher<Model, DAO>> m_objectFetcher;
//    };
    
    class IViewModelChangeDelegate {
        
    public:
        virtual void onInforChanged() = 0;
        
    };
    
    class IViewModel {
        
    public:
        
        virtual ~IViewModel(){};
        
    };
    
    class AbstractViewModel {
        
    public:
        
        AbstractViewModel(std::shared_ptr<IViewModelChangeDelegate> delegate = nullptr):m_loading(false), m_delegate(delegate) {};
        
        bool isLoading() {return m_loading;};
        
        void setLoading(bool loading) {m_loading = loading;}
        
        
    protected:
        
        void notificateInforChange() {
            
            auto delegate = m_delegate.lock();
            if (delegate) {
                delegate->onInforChanged();
            }
            
        };
        
    protected:
        
        bool m_loading;
        
        std::weak_ptr<IViewModelChangeDelegate> m_delegate;
        
    };
    
    
    template<class DataSource>
    class AbstractTableViewModel: public AbstractViewModel {
        
    public:
        
        AbstractTableViewModel(const std::shared_ptr<DataSource> & dataSource): m_dataSource(dataSource){}
        
        void setDataSource(const std::shared_ptr<DataSource> & dataSource) {m_dataSource = dataSource;};
        
        std::shared_ptr<DataSource> getDataSource() {return m_dataSource;};
        
    protected:
        
        std::shared_ptr<DataSource> m_dataSource;
        
    };

    
    class IUiController {
    
    public:
        virtual ~IUiController() {};
        
    };
    
    class IUnifiedFactory;
    
    template<class VM, class VMDelegate>
    class AbstractUiController: public IUiController {
        
    public:
        AbstractUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, std::shared_ptr<VMDelegate> delegate):m_unifiedFactory(unifiedFactory), m_delegate(delegate) {};
        
        std::shared_ptr<VMDelegate> getDelegate() {return m_delegate;};
        
        void setViewModel(std::shared_ptr<VM> vm) {m_viewModel = vm;};
        
        std::shared_ptr<VM> getViewModel () {return m_viewModel;};
        
        virtual void init() {};
        
    protected:
        std::weak_ptr<IUnifiedFactory> m_unifiedFactory;
        
        std::shared_ptr<VM> m_viewModel;
        std::shared_ptr<VMDelegate> m_delegate;
    };
    
}