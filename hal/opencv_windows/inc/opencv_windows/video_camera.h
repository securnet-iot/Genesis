#ifndef HAL_OPENCV_WINDOWS_VIDEO_CAMERA_H
#define HAL_OPENCV_WINDOWS_VIDEO_CAMERA_H

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio/videoio.hpp>

#include "hal/camera_interface.h"

namespace hal {

using WindowsVideoCameraFrame = cv::Mat;

class WindowsVideoCamera : public CameraInterface<WindowsVideoCameraFrame> {
 public:
  enum class Port {
    PORT_0 = 0,
    PORT_1,
    PORT_2,
    PORT_3,
  };

  WindowsVideoCamera(const Port port);

  virtual WindowsVideoCameraFrame GetFrame() override;
  virtual void ShowFrame(WindowsVideoCameraFrame frame) override;

 private:
  ::cv::VideoCapture camera_;
  Port port_;
  WindowsVideoCameraFrame frame_;
  bool is_camera_opened_;
};

}  // namespace hal

#endif /* OPENCV_WINDOWS_VIDEO_H */