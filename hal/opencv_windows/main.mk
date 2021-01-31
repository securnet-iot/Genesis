OPENCV_ID := opencv_windows
OPENCV_PATH := $(ROOT_PATH)/hal/$(OPENCV_ID)

APP_DEPLIBS += opencv_aruco \
								opencv_highgui opencv_saliency opencv_bgsegm opencv_img_hash \
								opencv_shape opencv_imgcodecs opencv_stereo opencv_calib3d opencv_imgproc \
								opencv_stitching opencv_ccalib opencv_intensity_transform opencv_structured_light \
								opencv_core opencv_line_descriptor opencv_superres opencv_datasets opencv_mcc \
								opencv_surface_matching opencv_dnn_objdetect opencv_ml opencv_text opencv_dnn_superres \
								opencv_objdetect opencv_tracking opencv_dnn opencv_optflow opencv_video opencv_dpm \
								opencv_phase_unwrapping opencv_videoio opencv_face opencv_photo opencv_videostab \
								opencv_features2d opencv_plot opencv_xfeatures2d opencv_flann opencv_quality \
								opencv_ximgproc opencv_fuzzy opencv_rapid opencv_xobjdetect opencv_gapi opencv_reg \
								opencv_xphoto opencv_hfs opencv_rgbd z zbar zstd zzip zzipfseeko zzipmmapped zzipwrap

APP_DEPLIBS_PATH += $(GENESIS_TOOLS_PATH)\msys64\mingw64\lib

INCDIRS += \
  $(GENESIS_TOOLS_PATH)/msys64/mingw64/include/opencv4 \
  $(GENESIS_TOOLS_PATH)/msys64/mingw64/include/zbar \
	$(ROOT_PATH)/etc/inc \
	$(ROOT_PATH)/hal/interface/inc \
  $(OPENCV_PATH)/inc

TARGET := lib$(OPENCV_ID).a

SOURCES := \
  $(wildcard $(OPENCV_PATH)/src/*.c) \
  $(wildcard $(OPENCV_PATH)/src/*.cpp)
