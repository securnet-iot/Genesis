INCDIRS += $(DIR)/inc

SUBMAKEFILES := \
	$(ROOT_PATH)/tchain/windows-gcc/main.mk \
	$(ROOT_PATH)/etc/main.mk \
	$(ROOT_PATH)/hal/opencv_windows/main.mk \
	opencv_hal_test_app.mk
