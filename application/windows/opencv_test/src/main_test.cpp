#include <iostream>
#include <opencv2/opencv.hpp>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/video.hpp"
#include "opencv2/videoio/videoio.hpp"

using namespace cv;

int main() {
  printf("Hari Kapparapu\n");
  printf("I am here\n");

  printf("I am here [%d]\n", __LINE__);
  VideoCapture cap(0);

  if (!cap.isOpened()) {
    printf("Can't open Camera\n");
    return -1;
  }

  for (;;) {
  Mat frame;
    cap >> frame;
    imshow("Wedcam Frame", frame);

    if (waitKey(30) >= 0) {
      break;
    }
  }

  printf("I am here [%d]\n", __LINE__);
}
