ROOT_PATH = ./../..

INCDIR += $(DIR)/inc

SUBMAKEFILES := \
  ../../main.mk \
  $(ROOT_PATH)/toolchain/linux/main.mk \
  test1.mk
