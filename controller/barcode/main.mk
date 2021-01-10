### EXPORTABLE DEFINITIONS - AVAILABLE TO DEPENDENT MAKEFILES #################
BARCODE_CONTROLLER_PATH := $(PLATFORM_CFG_PATH)/controller/barcode

CONTROLLER_ID := barcode_scan

### TARGET AND TARGET OPTIONS #################################################
# TARGET := libcontroller_$(CONTROLLER_ID).a

### SOURCES AND SOURCES OPTIONS ###############################################
SOURCES := \
  $(wildcard $(BARCODE_CONTROLLER_PATH)/src/*.cpp)

### GLOBAL SETTINGS APPLICABLE TO ALL TARGETS #################################
INCDIRS += \
  $(BARCODE_CONTROLLER_PATH)/inc \
  $(GENESIS_TOOLS_PATH)/opencv_win/build/install/include