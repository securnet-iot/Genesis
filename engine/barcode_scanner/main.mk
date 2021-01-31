ENGINE_BARCODE_SCANNER_PATH := $(ROOT_PATH)/engine/barcode_scanner
ENGINE_BARCODE_SCANNER_ID := engine_barcode_scanner

INCDIRS += \
	$(ROOT_PATH)/etc/inc \
	$(ROOT_PATH)/hal/interface/inc \
  $(ENGINE_BARCODE_SCANNER_PATH)/inc 

TARGET := lib$(ENGINE_BARCODE_SCANNER_ID).a

SOURCES := \
  $(wildcard $(ENGINE_BARCODE_SCANNER_PATH)/src/*.cpp)
