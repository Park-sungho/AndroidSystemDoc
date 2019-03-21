LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

# ========================================================
# Read Shared Memory Main Test 
# ========================================================
LOCAL_SRC_FILES:= read_binder_process.c
LOCAL_MODULE := read_binder_process
LOCAL_SHARED_LIBRARIES := \
    liblog \
    libcutils

LOCAL_MODULE_PATH   := $(LOCAL_PATH)/bin
LOCAL_MODULE_TAGS   := optional
include $(BUILD_EXECUTABLE)

# ========================================================
# Write Shared Memory Main Test 
# ========================================================
include $(CLEAR_VARS)
LOCAL_SRC_FILES:= write_binder_process.c
LOCAL_MODULE := write_binder_process
LOCAL_SHARED_LIBRARIES := \
    liblog \
    libcutils

LOCAL_MODULE_PATH   := $(LOCAL_PATH)/bin
LOCAL_MODULE_TAGS   := optional
include $(BUILD_EXECUTABLE)
