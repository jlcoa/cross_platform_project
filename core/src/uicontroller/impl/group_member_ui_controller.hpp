//
//  group_member_ui_controller.hpp
//  core
//
//  Created by Steve Chen on 2/28/16.
//
//

#pragma once

#include "../../interface/i_group_member_ui_controller.hpp"
#include "../../interface/i_contact_table_data_source.hpp"
#include "../../interface/i_group_member_view_model.hpp"
#include "../../interface/i_view_model_delegate.hpp"

#include "../i_ui_controller.hpp"

#include "../../dao/i_group_dao.hpp"

#include "../../service/i_contact_service.hpp"

#include "../../dao/abstract_table_data_source.hpp"
#include "contact_ui_controller.hpp"

namespace core {
    
    
    class GroupMemberUiController;
    
    class GroupMemberViewModel: public core_gen::IGroupMemberViewModel, public AbstractTableViewModel<core_gen::IContactTableDataSource> {
        
    public:
        
        GroupMemberViewModel(const std::shared_ptr<core_gen::IContactTableDataSource> & dataSource):AbstractTableViewModel(dataSource) {};
        
        void setDataSource(const std::shared_ptr<core_gen::IContactTableDataSource> & dataSource) override {
            AbstractTableViewModel::setDataSource(dataSource);
        };
        
        std::shared_ptr<core_gen::IContactTableDataSource> getDataSource() override {return AbstractTableViewModel::getDataSource();};
        
        void setGroup(const core_gen::RGroup & group) override {
            m_group = std::make_shared<core_gen::RGroup>(group);
        };
        
        core_gen::RGroup getGroup() override { return *m_group;}
        
    private:
        
        friend GroupMemberUiController;
        
        std::shared_ptr<core_gen::RGroup> m_group;
        
    };
    
    class GroupMemberUiController: public core_gen::IGroupMemberUiController, public AbstractUiController<core_gen::IGroupMemberViewModel, core_gen::IViewModelDelegate>, public IDataChangeListener, public ITableDataSourceDelegate<std::string, core_gen::RContact, IContactDao>, public std::enable_shared_from_this<GroupMemberUiController> {
        
    public:
        
        GroupMemberUiController(std::weak_ptr<IUnifiedFactory> unifiedFactory, const std::shared_ptr<core_gen::IViewModelDelegate> & delegate);
        
        std::shared_ptr<core_gen::IGroupMemberViewModel> getViewModel() override {
            return AbstractUiController::getViewModel();
        }
        
        void init() override;
        
        void onDataChanged(std::shared_ptr<AbstractTableDataSource<std::string, core_gen::RContact, IContactDao>> dataSource) override {
            m_delegate->onDataChanged();
        };
        
        void onDataChanged(const string& modelName, shared_ptr<ModelChangeTypeMap> changeMap);
        
        void loadData(const core_gen::RGroup & group) override;
        
        void addMembers(const std::vector<std::string> & memberIds, const std::shared_ptr<core_gen::IGroupCallback> & callback) override;
        
        void removeMembers(const std::vector<std::string> & memberIds, const std::shared_ptr<core_gen::IGroupCallback> & callback) override;
        
    private:
        
        std::shared_ptr<IContactService> m_contactService;
    };
    
}