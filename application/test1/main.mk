ROOT_PATH = ./../../

INCDIR += $(DIR)/inc

SUBMAKEFILES := \
  $(ROOT_PATH)/toolchain/linux/main.mk \
  test1.mk
