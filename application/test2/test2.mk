APPLICATION := test1
APPLICATION_ID := $(APPLICATION)_app

TARGET := $(APPLICATION_ID).exe
TARGET_DIR := bin

TGT_DEPLIBS := toolchain_$(TOOLCHAIN_ID)

TGT_LDFLAGS := -L$(TARGET_DIR)
TGT_LDLIBS := $(addprefix -l,$(TGT_DEPLIBS))
TGT_PREREQS := $(addsuffix .a,$(addprefix lib,$(TGT_DEPLIBS)))
TGT_POSTCLEAN := rm -rf $(BUILD_DIR) $(TARGET_DIR)

SOURCES := \
  $(wildcard $(ROOT_PATH)/application/$(APPLICATION)/src/*.cpp)

SRC_INCDIRS :=