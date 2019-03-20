LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

# ========================================================
# Read Shared Memory Main Test 
# ========================================================
include $(CLEAR_VARS)
LOCAL_SRC_FILES:= read_binder_process.c
LOCAL_MODULE := read_binder_process
LOCAL_C_INCLUDES := $(COMMON_INCLUDES) $(KERNEL_INICLUDES)
LOCAL_SHARED_LIBRARIES:= $(COMMON_LIBS)
LOCAL_MODULE_PATH	:= $(LOCAL_PATH)/bin
LOCAL_MODULE_TAGS	:= optional
include $(BUILD_EXECUTABLE)

# ========================================================
# Write Shared Memory Main Test 
# ========================================================
include $(CLEAR_VARS)
LOCAL_SRC_FILES:= write_binder_process.c
LOCAL_MODULE := write_binder_process
LOCAL_C_INCLUDES := $(COMMON_INCLUDES) $(KERNEL_INICLUDES)
LOCAL_SHARED_LIBRARIES:= $(COMMON_LIBS)
LOCAL_MODULE_PATH	:= $(LOCAL_PATH)/bin
LOCAL_MODULE_TAGS	:= optional
include $(BUILD_EXECUTABLE)

