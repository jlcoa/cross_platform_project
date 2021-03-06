# This file is generated by gyp; do not edit.

include $(CLEAR_VARS)

LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := libcore_gyp
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_TARGET_ARCH := $(TARGET_$(GYP_VAR_PREFIX)ARCH)
LOCAL_SDK_VERSION := 19
gyp_intermediate_dir := $(call local-intermediates-dir,,$(GYP_VAR_PREFIX))
gyp_shared_intermediate_dir := $(call intermediates-dir-for,GYP,shared,,,$(GYP_VAR_PREFIX))

# Make sure our deps are built first.
GYP_TARGET_DEPENDENCIES :=

GYP_GENERATED_OUTPUTS :=

# Make sure our deps and generated files are built first.
LOCAL_ADDITIONAL_DEPENDENCIES := $(GYP_TARGET_DEPENDENCIES) $(GYP_GENERATED_OUTPUTS)

LOCAL_GENERATED_SOURCES :=

GYP_COPIED_SOURCE_ORIGIN_DIRS :=

LOCAL_SRC_FILES := \
	src/api.cpp \
	src/event_loop.cpp \
	src/http.cpp \
	src/semaphore.cpp \
	src/app/data_provider.cpp \
	src/app/setting.cpp \
	src/app/unified_factory.cpp \
	src/app/xplatform_application.cpp \
	src/core/logger.cpp \
	src/core/pal.cpp \
	src/core/task_dispatcher.cpp \
	src/core/task_id.cpp \
	src/core/task_impl.cpp \
	src/dao/abstract_table_data_source.cpp \
	src/dao/data_change_map.cpp \
	src/dao/i_contact_dao.cpp \
	src/dao/i_dao_factory.cpp \
	src/dao/i_group_dao.cpp \
	src/dao/i_group_member_dao.cpp \
	src/dao/object_fetcher.cpp \
	src/dao/impl/contact_dao.cpp \
	src/dao/impl/dao_factory.cpp \
	src/dao/impl/group_dao.cpp \
	src/dao/impl/group_member_dao.cpp \
	src/db/sqlite_store.cpp \
	src/github/client.cpp \
	src/interface/r_account.cpp \
	src/interface/r_account_response.cpp \
	src/interface/r_avatar_domain.cpp \
	src/interface/r_avatar_info.cpp \
	src/interface/r_contact.cpp \
	src/interface/r_contact_response.cpp \
	src/interface/r_group.cpp \
	src/interface/r_group_member.cpp \
	src/interface/r_group_response.cpp \
	src/interface/r_group_update_response.cpp \
	src/interface/r_upload_token.cpp \
	src/model/account.cpp \
	src/model/model.cpp \
	src/network/api_helper.cpp \
	src/network/http_client.cpp \
	src/network/common/type_parser.cpp \
	src/service/i_account_service.cpp \
	src/service/i_biz_service_factory.cpp \
	src/service/i_contact_service.cpp \
	src/service/i_data_change_notification_service.cpp \
	src/service/impl/account_service.cpp \
	src/service/impl/biz_service_factory.cpp \
	src/service/impl/contact_service.cpp \
	src/service/impl/data_change_notification_service.cpp \
	src/sqlite/backup.cpp \
	src/sqlite/cursor.cpp \
	src/sqlite/db.cpp \
	src/sqlite/stmt.cpp \
	src/sqlite/transaction.cpp \
	src/sqlite/value.cpp \
	src/sqlite_query/observable_db.cpp \
	src/sqlite_query/query_diff.cpp \
	src/sqlite_query/query_monitor.cpp \
	src/ui_interface/user_list_vm.cpp \
	src/uicontroller/i_ui_controller.cpp \
	src/uicontroller/ui_controller_factory.cpp \
	src/uicontroller/impl/contact_ui_controller.cpp \
	src/uicontroller/impl/group_create_ui_controller.cpp \
	src/uicontroller/impl/group_detail_ui_controller.cpp \
	src/uicontroller/impl/group_member_ui_controller.cpp \
	src/uicontroller/impl/group_ui_controller.cpp \
	src/uicontroller/impl/group_update_ui_controller.cpp \
	src/uicontroller/impl/lifecyle_ui_controller.cpp \
	src/uicontroller/impl/login_ui_controller.cpp \
	src/uicontroller/impl/profile_ui_controller.cpp \
	src/uicontroller/impl/signup_ui_controller.cpp \
	src/utils/locker.cpp \
	src/utils/utils.cpp \
	src/utils/base64/Base64.cpp \
	src/utils/base64/Base64Encoding.cpp \
	src/utils/base64/Base64FamilyEncoder.cpp \
	src/utils/base64/Base64urlEncoding.cpp \
	src/utils/sha/sha1.cpp \
	src/utils/storage/key_value_storage.cpp


# Flags passed to both C and C++ files.
MY_CFLAGS_Debug := \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-fvisibility=hidden \
	-g \
	-O0

MY_DEFS_Debug := \
	'-DDEBUG'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Debug := \
	$(LOCAL_PATH)/include \
	$(LOCAL_PATH)/deps \
	$(LOCAL_PATH)/deps/sqlite3


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Debug := \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-fvisibility=hidden \
	-std=c++1y \
	-fexceptions \
	-frtti


# Flags passed to both C and C++ files.
MY_CFLAGS_Release := \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-fvisibility=hidden \
	-Os \
	-fomit-frame-pointer \
	-fdata-sections \
	-ffunction-sections

MY_DEFS_Release := \
	'-DNDEBUG'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Release := \
	$(LOCAL_PATH)/include \
	$(LOCAL_PATH)/deps \
	$(LOCAL_PATH)/deps/sqlite3


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Release := \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-fvisibility=hidden \
	-std=c++1y \
	-fexceptions \
	-frtti


LOCAL_CFLAGS := $(MY_CFLAGS_$(GYP_CONFIGURATION)) $(MY_DEFS_$(GYP_CONFIGURATION))
LOCAL_C_INCLUDES := $(GYP_COPIED_SOURCE_ORIGIN_DIRS) $(LOCAL_C_INCLUDES_$(GYP_CONFIGURATION))
LOCAL_CPPFLAGS := $(LOCAL_CPPFLAGS_$(GYP_CONFIGURATION))
LOCAL_ASFLAGS := $(LOCAL_CFLAGS)
### Rules for final target.
# Add target alias to "gyp_all_modules" target.
.PHONY: gyp_all_modules
gyp_all_modules: libcore_gyp

# Alias gyp target name.
.PHONY: libcore
libcore: libcore_gyp

include $(BUILD_STATIC_LIBRARY)
