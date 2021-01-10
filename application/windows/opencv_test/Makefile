CC=g++

CFLAGS = -std=c++17 -W -p -g -Wall -pg -flto -fexceptions

SRCS = src/main.cpp
PROG = opencv_exe.exe

OPENCV := -I$(GENESIS_TOOLS_PATH)\msys64\mingw64\include\opencv4
OPENCV += -L$(GENESIS_TOOLS_PATH)\msys64\mingw64\lib
OPENCV += -lopencv_aruco
OPENCV += -lopencv_highgui
OPENCV += -lopencv_saliency
OPENCV += -lopencv_bgsegm
OPENCV += -lopencv_img_hash
OPENCV += -lopencv_shape
OPENCV += -lopencv_imgcodecs
OPENCV += -lopencv_stereo
OPENCV += -lopencv_calib3d
OPENCV += -lopencv_imgproc
OPENCV += -lopencv_stitching
OPENCV += -lopencv_ccalib
OPENCV += -lopencv_intensity_transform
OPENCV += -lopencv_structured_light
OPENCV += -lopencv_core
OPENCV += -lopencv_line_descriptor
OPENCV += -lopencv_superres
OPENCV += -lopencv_datasets
OPENCV += -lopencv_mcc
OPENCV += -lopencv_surface_matching
OPENCV += -lopencv_dnn_objdetect
OPENCV += -lopencv_ml
OPENCV += -lopencv_text
OPENCV += -lopencv_dnn_superres
OPENCV += -lopencv_objdetect
OPENCV += -lopencv_tracking
OPENCV += -lopencv_dnn
OPENCV += -lopencv_optflow
OPENCV += -lopencv_video
OPENCV += -lopencv_dpm
OPENCV += -lopencv_phase_unwrapping
OPENCV += -lopencv_videoio
OPENCV += -lopencv_face
OPENCV += -lopencv_photo
OPENCV += -lopencv_videostab
OPENCV += -lopencv_features2d
OPENCV += -lopencv_plot
OPENCV += -lopencv_xfeatures2d
OPENCV += -lopencv_flann
OPENCV += -lopencv_quality
OPENCV += -lopencv_ximgproc
OPENCV += -lopencv_fuzzy
OPENCV += -lopencv_rapid
OPENCV += -lopencv_xobjdetect
OPENCV += -lopencv_gapi
OPENCV += -lopencv_reg
OPENCV += -lopencv_xphoto
OPENCV += -lopencv_hfs
OPENCV += -lopencv_rgbd

.PHONY: all clean
$(PROG) : $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(OPENCV)

all: $(PROG)

clean:
	rm -f $(OBJS) $(PROG)