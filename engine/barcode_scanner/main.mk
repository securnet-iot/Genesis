ENGINE_BARCODE_SCANNER_PATH := $(PLATFORM_CFG_PATH)/engine/barcode
ENGINE_BARCODE_SCANNER_ID := barcode_scanner

INCDIRS += \
	$(ROOT_PATH)/hal/interface/inc \
  $(ENGINE_BARCODE_SCANNER_PATH)/inc 

TARGET := libengine_$(ENGINE_BARCODE_SCANNER_ID).a

SOURCES := \
  $(wildcard $(ENGINE_BARCODE_SCANNER_PATH)/src/*.cpp)
