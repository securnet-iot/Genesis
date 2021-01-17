#include "opencv_windows/video_camera.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>

namespace hal {

WindowsVideoCamera::WindowsVideoCamera(const Port port)
    : camera_{static_cast<uint8_t>(port)},
      port_{port},
      frame_{0},
      is_camera_opened_{false} {
  if (camera_.isOpened()) {
    is_camera_opened_ = true;
  }
}

WindowsVideoCameraFrame WindowsVideoCamera::GetFrame(void) {
  if (is_camera_opened_) {
    camera_ >> frame_;
  } else {
    printf("Camera Not Opened");
  }
  return frame_;
}

void WindowsVideoCamera::ShowFrame(WindowsVideoCameraFrame frame) {
  if (is_camera_opened_) {
    ::cv::imshow("Camera Frame", frame);
  } else {
    printf("Camera Not Opened");
  }
}

}  // namespace hal