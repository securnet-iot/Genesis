INCDIRS += $(DIR)/inc

SUBMAKEFILES := \
	$(ROOT_PATH)/tchain/windows-gcc/main.mk \
	$(ROOT_PATH)/etc/main.mk \
	$(ROOT_PATH)/hal/opencv_windows/main.mk \
	$(ROOT_PATH)/engine/barcode_scanner/main.mk \
	scanner_app.mk
