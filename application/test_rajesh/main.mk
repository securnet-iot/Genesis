ROOT_PATH = ./../..

INCDIR += $(DIR)/inc

SUBMAKEFILES := \
  $(ROOT_PATH)/toolchain/raspbian/main.mk \
  test_rajesh.mk
