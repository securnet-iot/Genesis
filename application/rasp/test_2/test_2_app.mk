APP_ID := test_2_app

TGT_DEPLIBS = tchain_$(TCHAIN_ID)

TARGET := $(APP_ID).exe
TARGET_DIR := bin

TGT_DEFS := APP_NAME="\"$(APP_ID)\""
TGT_INCDIRS := ./inc

TGT_LDFLAGS := -L${TARGET_DIR} -Xlinker \
  -Map=$(TARGET_DIR)/$(TARGET).map -Wl,--gc-sections
TGT_LDLIBS  := $(addprefix -l,$(TGT_DEPLIBS))

TGT_POSTCLEAN := rm -rf $(TARGET_DIR) $(BUILD_DIR)

TGT_POSTMAKE := \
  $(OBJCPY) -O srec --gap-fill=0 $(TARGET_DIR)/$(APP_ID).exe $(TARGET_DIR)/$(APP_ID).mot; \
  $(OBJCPY) -O binary --gap-fill=0 $(TARGET_DIR)/$(APP_ID).exe $(TARGET_DIR)/$(APP_ID).bin; \
  $(SIZE) $(TARGET_DIR)/$(APP_ID).exe

TGT_PREREQS := $(addsuffix .a,$(addprefix lib,$(TGT_DEPLIBS)))

INCDIRS += \
  $(DIR)/inc

SOURCES := \
  $(wildcard ./src/*.cpp)
