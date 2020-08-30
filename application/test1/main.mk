#ROOT_PATH = ./../..
#ROOT_PATH = $(subst D:/,/D/,$(subst C:/,/C/,$(subst \,/,$(CURDIR))))/../..
ROOT_PATH = $(CURDIR)/../..

INCDIR += ./../inc

SUBMAKEFILES := \
  $(ROOT_PATH)/toolchain/windows/main.mk \
  test1.mk
