### EXPORTABLE DEFINITIONS - AVAILABLE TO DEPENDENT MAKEFILES #################
ILL_MEC_PATH := $(PLATFORM_CFG_PATH)/mechanism/ill_mec

MECHANISM_ID := ill_mec

### TARGET AND TARGET OPTIONS #################################################
TARGET := libmechanism_$(MECHANISM_ID).a

### SOURCES AND SOURCES OPTIONS ###############################################
SOURCES := $(wildcard $(ILL_MEC_PATH)/src/*.cpp) \
  $(wildcard $(ILL_MEC_PATH)/src/evaluator/*.cpp)

### GLOBAL SETTINGS APPLICABLE TO ALL TARGETS #################################
INCDIRS := ${INCDIRS} \
  $(ILL_MEC_PATH)/inc