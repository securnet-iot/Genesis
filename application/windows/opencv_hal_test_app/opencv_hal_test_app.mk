APP_ID := test_1_app

TGT_DEPLIBS = tchain_$(TCHAIN_ID) $(OPENCV_ID) $(ETC_ID) $(APP_DEPLIBS)
# controller_barcode_scan
TGT_DEPLIBS_PATH = bin $(APP_DEPLIBS_PATH)

TARGET := $(APP_ID).exe
TARGET_DIR := bin

TGT_DEFS := APP_NAME="\"$(APP_ID)\""
TGT_INCDIRS := ./inc

TGT_LDFLAGS := -L${TARGET_DIR} -Xlinker \
  -Map=$(TARGET_DIR)/$(TARGET).map -Wl,--gc-sections
TGT_LDLIBS  := $(addprefix -l,$(TGT_DEPLIBS))

TGT_POSTCLEAN := rm -rf $(TARGET_DIR) $(BUILD_DIR)

TGT_POSTMAKE := \
	$(SIZE) $(TARGET_DIR)/$(APP_ID).exe

# $(OBJCPY) -O srec --gap-fill=0 $(TARGET_DIR)/$(APP_ID).exe $(TARGET_DIR)/$(APP_ID).mot;
# $(OBJCPY) -O binary --gap-fill=0 $(TARGET_DIR)/$(APP_ID).exe $(TARGET_DIR)/$(APP_ID).bin;

TGT_PREREQS := $(addsuffix .a,$(addprefix lib,$(TGT_DEPLIBS)))

INCDIRS += \
	$(ROOT_PATH)/hal/opencv_windows/inc \
	$(DIR)/inc

SOURCES := \
	$(wildcard ./src/*.cpp)
