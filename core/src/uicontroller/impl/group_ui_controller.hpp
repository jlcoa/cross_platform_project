//
//  group_ui_controller.hpp
//  core
//
//  Created by Steve Chen on 2/21/16.
//
//
#pragma once

#include "../../interface/i_group_ui_controller.hpp"
#include "../../interface/i_group_table_data_source.hpp"
#include "../../interface/i_group_view_model.hpp"
#include "../../interface/i_view_model_delegate.hpp"

#include "../i_ui_controller.hpp"

#include "../../dao/i_group_dao.hpp"

#include "../../service/i_contact_service.hpp"

#include "../../dao/abstract_table_data_source.hpp"

namespace core {
    
    class GroupTableDataSource: public core_gen::IGroupTableDataSource, public AbstractTableDataSource<std::string, core_gen::RGroup, IGroupDao> {
        
    public:
        GroupTableDataSource(std::shared_ptr<ObjectFetcher<core_gen::RGroup, IGroupDao>> objectFetcher, std::weak_ptr<ITableDataSourceDelegate<std::string, core_gen::RGroup, IGroupDao>> delegate): AbstractTableDataSource{objectFetcher, delegate} {};
        
        int32_t numberOfSections() override {
            return AbstractTableDataSource::numberOfSections();
        };
        
        int32_t numberOfRowsInSection(int32_t section) override {
            return AbstractTableDataSource::numberOfRowsInSection(section);
        };
        
        core_gen::RGroup objectAt(int32_t section, int32_t row) override {
            return *AbstractTableDataSource::objectAt(section, row);
        };
        
    protected:
        
        std::string key4Model(std::shared_ptr<core_gen::RGroup> model) override {
            return "";
        }
        
    private:
        
    };
    
    
    class GroupViewModel: public core_gen::IGroupViewModel, public AbstractTableViewModel<core_gen::IGroupTableDataSource> {
        
    public:
        
        GroupViewModel(const std::shared_ptr<GroupTableDataSource> & dataSource):AbstractTableViewModel(dataSource) {};
        
        void setDataSource(const std::shared_ptr<core_gen::IGroupTableDataSource> & dataSource) override {
            AbstractTableViewModel::setDataSource(dataSource);
        };
        
        std::shared_ptr<core_gen::IGroupTableDataSource> getDataSource() override {return AbstractTableViewModel::getDataSource();};
        
    private:
        
        
    };
    
    class GroupUiController: public core_gen::IGroupUiController, public AbstractUiController<core_gen::IGroupViewModel, core_gen::IViewModelDelegate>, public ITableDataSourceDelegate<std::string, core_gen::RGroup, IGroupDao>, public std::enable_shared_from_this<GroupUiController> {
        
    public:
        
        GroupUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate);
        
        std::shared_ptr<core_gen::IGroupViewModel> getViewModel() override {
            return AbstractUiController::getViewModel();
        }
        
        void init() override;
        
        void onDataChanged(std::shared_ptr<AbstractTableDataSource<std::string, core_gen::RGroup, IGroupDao>> dataSource) override {
            m_delegate->onDataChanged();
        };
        
    private:
        
        std::shared_ptr<IContactService> m_contactService;
    };
    
}