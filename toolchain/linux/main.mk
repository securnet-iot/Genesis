### Definitions ###################################################################################
ifndef ROOT_PATH
	$(error ROOT_PATH not set)
endif

ifndef PLATFORM
	PLATFORM = Linux
endif

ifndef DEBUG
	BUILD = Release
	OPT_FLAG = -Og
endif

ifdef DEBUG
	BUILD = Debug
	OPT_FLAG = -O0
endif

$(call PRINT_INFO, ROOT_PATH)
$(call PRINT_INFO, PLATFORM)
$(call PRINT_INFO, BUILD)
$(call PRINT_INFO, OPT_FLAG)

TOOLCHAIN_ID := linux
TOOLCHAIN_PATH := $(ROOT_PATH)/toolchain/$(TOOLCHAIN_ID)
$(call PRINT_INFO, TOOLCHAIN_PATH) #%% Debugging purpose only

### Compiler Settings #############################################################################
CC := gcc
CXX := g++
AR := ar
SIZE := size

CFLAGS += -std=c11 -Wall -Wpedantic -Wextra $(OPT_FLAG) -g3
CXXFLAGS += -std=gnu++11 -Wall -Wpedantic -Wextra $(OPT_FLAG) -g3
LDFLAGS += -Wall $(OPT_FLAG) -g3

### Target Lib File ###############################################################################
TARGET := libtoolchain_$(TOOLCHAIN_ID).a

SOURCES :=