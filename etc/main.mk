ETC_PATH := $(ROOT_PATH)/etc
ETC_ID := etc

APP_DEPLIBS += $(ETC_ID)

INCDIRS += \
  $(ETC_PATH)/inc

TARGET := lib$(ETC_ID).a

SOURCES := \
  $(wildcard $(ETC_PATH)/src/*.c) \
  $(wildcard $(ETC_PATH)/src/*.cpp)
