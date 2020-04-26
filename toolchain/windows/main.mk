### Definitions ###################################################################################
ifndef ROOT_PATH
	$(error ROOT_PATH not set)
endif

ifndef PLATFORM
	PLATFORM = Windows
endif

ifndef DEBUG
	BUILD = Release
	OPT_LEVEL = 3
endif

ifdef DEBUG
	BUILD = Debug
	OPT_LEVEL = 0
endif

$(info ************ BUILD CONFIGURATIONS ************)
$(call PRINT_INFO, ROOT_PATH)
$(call PRINT_INFO, PLATFORM)
$(call PRINT_INFO, BUILD)
$(info **********************************************)

TOOLCHAIN_ID := linux
TOOLCHAIN_PATH := $(ROOT_PATH)/toolchain/$(TOOLCHAIN_ID)
TOOLCHAIN_SYSROOT_PATH := 

### Compiler Settings #############################################################################
CC := gcc
CXX := g++
AR := ar
SIZE := size

TOOLCHAIN_COMMON_FLAGS := -Wall -O$(OPT_LEVEL) -g3 --sysroot=$(TOOLCHAIN_SYSROOT_PATH)

CFLAGS += -std=c11 -Wpedantic -Wextra $(TOOLCHAIN_COMMON_FLAGS)
CXXFLAGS += -std=gnu++11 -Wpedantic -Wextra $(TOOLCHAIN_COMMON_FLAGS)
LDFLAGS += $(TOOLCHAIN_COMMON_FLAGS)

### Target Lib File ###############################################################################
TARGET := libtoolchain_$(TOOLCHAIN_ID).a

SOURCES :=