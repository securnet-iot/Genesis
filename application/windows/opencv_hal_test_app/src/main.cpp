#include <conio.h>
#include <stdio.h>
#include <unistd.h>

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
    ReturnResult<VideoFrame> frame_return{video_cam.GetFrame()};

    if (frame_return.IsValid()) {
      video_cam.ShowFrame(frame_return.Value());

      barcode_scanner.SetValue(frame_return.Value());
      ReturnResult<BarcodeInfo> info_exepcted{barcode_scanner.GetValue()};

      if (info_exepcted.IsValid()) {
        ::std::cout << ::std::endl
                    << "****** Scanned Info ******" << ::std::endl;
        for (int count = 0; count < info_exepcted.Value().count; count++) {
          ::std::cout << ::std::to_string(count) + ":  "
                      << "Type: " << info_exepcted.Value().type[count]
                      << "        "
                      << "Data: " << info_exepcted.Value().data[count]
                      << ::std::endl;
        }

        video_cam.SaveFrameAsJpg("bin", "ScannedImage", frame_return.Value());
      }

      usleep(200000);
    }

    if (::cv::waitKey(30) >= 0) {
      break;
    }
  }

  printf("I am here [%d]\n", __LINE__);
}
