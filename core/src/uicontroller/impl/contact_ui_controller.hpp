//
//  contact_ui_controller.hpp
//  core
//
//  Created by Steve Chen on 2/21/16.
//
//

#pragma once

#include "../../interface/i_contact_ui_controller.hpp"
#include "../../interface/i_contact_table_data_source.hpp"
#include "../../interface/i_contact_view_model.hpp"
#include "../../interface/i_view_model_delegate.hpp"

#include "../i_ui_controller.hpp"

#include "../../dao/i_contact_dao.hpp"

#include "../../service/i_contact_service.hpp"

#include "../../dao/abstract_table_data_source.hpp"

namespace core {
    
    class ContactTableDataSource: public core_gen::IContactTableDataSource, public AbstractTableDataSource<std::string, core_gen::RContact, IContactDao> {
    
    public:
        ContactTableDataSource(std::shared_ptr<ObjectFetcher<core_gen::RContact, IContactDao>> objectFetcher, std::weak_ptr<ITableDataSourceDelegate<std::string, core_gen::RContact, IContactDao>> delegate): AbstractTableDataSource{objectFetcher, delegate} {};
        
        int32_t numberOfSections() override {
            return AbstractTableDataSource::numberOfSections();
        };
        
        int32_t numberOfRowsInSection(int32_t section) override {
            return AbstractTableDataSource::numberOfRowsInSection(section);
        };
        
        core_gen::RContact objectAt(int32_t section, int32_t row) override {
            return *AbstractTableDataSource::objectAt(section, row);
        };
        
    protected:
        std::string key4Model(std::shared_ptr<core_gen::RContact> model) override {
            return "";
        }
        
    private:
        
    };
    
    class ContactViewModel: public core_gen::IContactViewModel, public AbstractTableViewModel<core_gen::IContactTableDataSource> {
        
    public:
        
        ContactViewModel(const std::shared_ptr<ContactTableDataSource> & dataSource):AbstractTableViewModel(dataSource) {};
        
        void setDataSource(const std::shared_ptr<core_gen::IContactTableDataSource> & dataSource) override {
            AbstractTableViewModel::setDataSource(dataSource);
        };
        
        std::shared_ptr<core_gen::IContactTableDataSource> getDataSource() override {return AbstractTableViewModel::getDataSource();};
        
    private:
        
        
    };
    
    class ContactUiController: public core_gen::IContactUiController, public AbstractUiController<core_gen::IContactViewModel, core_gen::IViewModelDelegate>, public ITableDataSourceDelegate<std::string, core_gen::RContact, IContactDao>, public std::enable_shared_from_this<ContactUiController> {
    
    public:
        
        ContactUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate);
        
        std::shared_ptr<core_gen::IContactViewModel> getViewModel() override {
            return AbstractUiController::getViewModel();
        }
        
        void init() override;
        
        void onDataChanged(std::shared_ptr<AbstractTableDataSource<std::string, core_gen::RContact, IContactDao>> dataSource) override {
            m_delegate->onDataChanged();
        };
        
    private:
        
        std::shared_ptr<IContactService> m_contactService;
    };
    
}
