#ROOT_PATH = /home/pi/HariProjects/GitHub/Genesis/

INCDIR += $(DIR)/inc

SUBMAKEFILES := \
  ../../main.mk \
  $(ROOT_PATH)/toolchain/linux/main.mk \
  test1.mk
