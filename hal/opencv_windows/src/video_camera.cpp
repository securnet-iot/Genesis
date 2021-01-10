#include "opencv_windows/video_camera.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>

namespace hal {

VideoCameraSensor::VideoCameraSensor(const VideoCameraPort port)
    : camera_{port}, port_{port}, is_camera_opened_{false} {
  if (camera_.isOpened()) {
    is_camera_opened_ = true;
  }
}

VideoCameraFrame VideoCameraSensor::GetFrame(void) {
  if (is_camera_opened_) {
    return camera_;
  } else {
    printf("Camera Not Opened");
  }
}

VideoCameraFrame VideoCameraSensor::ShowFrame(void) {
  if (is_camera_opened_) {
    ::cv::imshow("Camera Frame of Port - %d", port_);
  } else {
    printf("Camera Not Opened");
  }
}

}  // namespace hal