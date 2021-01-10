#ifndef HAL_OPENCV_WINDOWS_VIDEO_CAMERA_H
#define HAL_OPENCV_WINDOWS_VIDEO_CAMERA_H

#include <opencv2/videoio/videoio.hpp>

#include "hal/camera_interface.h"

namespace hal {

using WindowsVideoCameraFrame = ::cv::Mat;

class WindowsVideoCamera : public VideoInterface<WindowsVideoCameraFrame> {
 public:
  enum class Port {
    PORT_0 = 0,
    PORT_1,
    PORT_2,
    PORT_3,
  };

  VideoCameraSensor(const Port port);

  virtual ParamType GetFrame() override;
  virtual ParamType ShowFrame() override;

 private:
  ::cv::VideoCapture camera_;
  Port port_;
  bool is_camera_opened_;
};

}  // namespace hal

#endif /* OPENCV_WINDOWS_VIDEO_H */