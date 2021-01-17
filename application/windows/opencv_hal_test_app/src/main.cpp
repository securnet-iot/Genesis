#include <conio.h>
#include <stdio.h>

#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "opencv_windows/video_camera.h"
#include "tchain/types.h"

/* ------------------------------------------------------------------------ */
/*  Main entry point */
int main() {
  printf("Hello Hari\n");

  ::hal::WindowsVideoCamera video_cam{::hal::WindowsVideoCamera::Port::PORT_1};

  video_cam.ShowFrame(video_cam.GetFrame());

  while (1) {
    if (::cv::waitKey(30) >= 0) {
      break;
    }
  }

  printf("I am here [%d]\n", __LINE__);
}
