ifndef ROOT_PATH
	$(error ROOT_PATH not set)
endif

ifndef PLATFORM
	PLATFORM = Windows
endif

ifndef DEBUG
	BUILD_TYPE = Release
	OPTIMIZATION_LEVEL = 3
endif

ifdef DEBUG
	BUILD_TYPE = Debug
	OPTIMIZATION_LEVEL = 0
endif

$(info ************ BUILD CONFIGURATIONS ************)
$(call PRINT_INFO, ROOT_PATH)
$(call PRINT_INFO, PLATFORM)
$(call PRINT_INFO, GENESIS_TOOLS_PATH)
$(call PRINT_INFO, BUILD_TYPE)
$(call PRINT_INFO, OPTIMIZATION_LEVEL)
$(info **********************************************)

TCHAIN_ID := windows-gcc
TCHAIN_PATH := $(ROOT_PATH)/tchain/$(TCHAIN_ID)

CC := gcc
CXX := g++
AR := ar
SIZE := size

APP_DEPLIBS += tchain_$(TCHAIN_ID)
INCDIRS += $(TCHAIN_PATH)/inc

TOOLCHAIN_COMMON_FLAGS := -Wall -O$(OPTIMIZATION_LEVEL) -g3

CFLAGS += -std=c11 -Wpedantic $(TOOLCHAIN_COMMON_FLAGS) -Wimplicit-fallthrough=2
CXXFLAGS += -std=gnu++11 -Wpedantic $(TOOLCHAIN_COMMON_FLAGS) -Wimplicit-fallthrough=2
LDFLAGS += $(TOOLCHAIN_COMMON_FLAGS)

TARGET := libtchain_$(TCHAIN_ID).a

SOURCES := \
	src/tchain.c
