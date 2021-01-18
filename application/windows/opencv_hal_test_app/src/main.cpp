#include <conio.h>
#include <stdio.h>

#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "opencv_windows/barcode_scanner.h"
#include "opencv_windows/video_camera.h"
#include "tchain/types.h"

/* ------------------------------------------------------------------------ */
/*  Main entry point */
int main() {
  printf("Hello Hari\n");

  ::hal::WindowsVideoCamera video_cam{::hal::WindowsVideoCamera::Port::PORT_1};
  ::hal::WindowsBarcodeScanner barcode_scanner{};

  while (1) {
    ReturnResult<::hal::WindowsVideoCameraFrame> frame_return{
        video_cam.GetFrame()};
    if (frame_return.IsValid()) {
      video_cam.ShowFrame(frame_return.Value());
      // video_cam.SaveFrameAsJpg("bin", "Hari", frame_return.Value());

      barcode_scanner.SetValue(frame_return.Value());
      barcode_scanner.GetValue();
    }

    if (::cv::waitKey(30) >= 0) {
      break;
    }
  }

  printf("I am here [%d]\n", __LINE__);
}
