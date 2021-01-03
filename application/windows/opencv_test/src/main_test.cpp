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

// #include <opencv2/opencv.hpp>
// using namespace cv;
// int main(int argc, char** argv) {
//   Mat image;
//   image = imread(argv[1], 1);
//   if (argc != 2 || !image.data) {
//     printf("No image data \n");
//     return -1;
//   }
//   namedWindow("Display Image", WINDOW_AUTOSIZE);
//   imshow("Display Image", image);
//   waitKey(0);
//   return 0;
// }

// #include <iostream>

// #include "opencv2/highgui/highgui.hpp"

// using namespace cv;
// using namespace std;

// int main(int argc, char** argv) {
//   printf("Hari-Printf\n\n");
//   cout << "Hari!" << endl;
//   Mat im;
 
//   // = imread(argc == 2 ? argv[1] : "lena.jpg", 1);
//   // if (im.empty()) {
//   //   cout << "Cannot open image!" << endl;
//   //   return -1;
//   // }

//   // imshow("image", im);
//   // waitKey(0);

//   return 0;
// }