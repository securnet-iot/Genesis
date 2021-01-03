CC = /D/Misc/GenesisTools/mingw-w64-hk-posix/mingw32/bin/g++.exe
CFLAGS = -g -Wall

SRCS = src/main_test.cpp
PROG = opencv_exe.exe

OPENCV := -I"D:\Misc\GenesisTools\opencv_lib\include"
OPENCV += -L"D:\Misc\GenesisTools\opencv_lib\x64\mingw\lib"
OPENCV += -lopencv_aruco451
OPENCV += -lopencv_highgui451
OPENCV += -lopencv_saliency451
OPENCV += -lopencv_bgsegm451
OPENCV += -lopencv_img_hash451
OPENCV += -lopencv_shape451
OPENCV += -lopencv_bioinspired451
OPENCV += -lopencv_imgcodecs451
OPENCV += -lopencv_stereo451
OPENCV += -lopencv_calib3d451
OPENCV += -lopencv_imgproc451
OPENCV += -lopencv_stitching451
OPENCV += -lopencv_ccalib451
OPENCV += -lopencv_intensity_transform451
OPENCV += -lopencv_structured_light451
OPENCV += -lopencv_core451
OPENCV += -lopencv_line_descriptor451
OPENCV += -lopencv_superres451
OPENCV += -lopencv_datasets451
OPENCV += -lopencv_mcc451
OPENCV += -lopencv_surface_matching451
OPENCV += -lopencv_dnn_objdetect451
OPENCV += -lopencv_ml451
OPENCV += -lopencv_text451
OPENCV += -lopencv_dnn_superres451
OPENCV += -lopencv_objdetect451
OPENCV += -lopencv_tracking451
OPENCV += -lopencv_dnn451
OPENCV += -lopencv_optflow451
OPENCV += -lopencv_video451
OPENCV += -lopencv_dpm451
OPENCV += -lopencv_phase_unwrapping451
OPENCV += -lopencv_videoio451
OPENCV += -lopencv_face451
OPENCV += -lopencv_photo451
OPENCV += -lopencv_videostab451
OPENCV += -lopencv_features2d451
OPENCV += -lopencv_plot451
OPENCV += -lopencv_xfeatures2d451
OPENCV += -lopencv_flann451
OPENCV += -lopencv_quality451
OPENCV += -lopencv_ximgproc451
OPENCV += -lopencv_fuzzy451
OPENCV += -lopencv_rapid451
OPENCV += -lopencv_xobjdetect451
OPENCV += -lopencv_gapi451
OPENCV += -lopencv_reg451
OPENCV += -lopencv_xphoto451
OPENCV += -lopencv_hfs451
OPENCV += -lopencv_rgbd451
# OPENCV += -lopencv_videoio_ffmpeg451
OPENCV += -lm -lpthread
# -lz
#  -flto

$(PROG) : $(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(OPENCV)


# g++ "-ID:\\Misc\\GenesisTools\\opencv_lib\\include" -O0 -g3 -Wall -c -fmessage-length=0 -o HK_Test_3.o "..\\HK_Test_3.cpp" 
# g++ "-LD:\\Misc\\GenesisTools\\opencv_lib\\x64\\mingw\\lib" -o HK_Test_3.exe HK_Test_3.o -lopencv_aruco451 -lopencv_bgsegm451 -lopencv_bioinspired451 -lopencv_calib3d451 -lopencv_ccalib451 -lopencv_core451 -lopencv_datasets451 -lopencv_dnn_objdetect451 -lopencv_dnn_superres451 -lopencv_dnn451 -lopencv_dpm451 -lopencv_face451 -lopencv_features2d451 -lopencv_flann451 -lopencv_fuzzy451 -lopencv_gapi451 -lopencv_hfs451 -lopencv_highgui451 -lopencv_imgcodecs451 -lopencv_imgproc451 -lopencv_videoio451 
