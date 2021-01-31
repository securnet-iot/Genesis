#ifndef HAL_OPENCV_WINDOWS_VIDEO_CAMERA_H
#define HAL_OPENCV_WINDOWS_VIDEO_CAMERA_H

// #include <opencv2/highgui/highgui.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio/videoio.hpp>

#include "hal/frame_interface.h"

namespace hal {

using WindowsVideoCameraFrame = cv::Mat;

class WindowsVideoCamera : public FrameInterface<WindowsVideoCameraFrame> {
 public:
  enum class Port {
    PORT_0 = 0,
    PORT_1,
    PORT_2,
    PORT_3,
  };

  WindowsVideoCamera(const Port port);

  virtual ReturnResult<WindowsVideoCameraFrame> GetFrame() override;
  virtual ReturnResult<void> ShowFrame(WindowsVideoCameraFrame frame) override;
  virtual ReturnResult<bool> IsAvailable() override;
  virtual ReturnResult<void> SaveFrameAsJpg(
      ::std::string file_path, ::std::string file_name,
      WindowsVideoCameraFrame frame) override;

 private:
  ::cv::VideoCapture camera_;
  Port port_;
  WindowsVideoCameraFrame frame_;
  bool is_camera_opened_;
};

}  // namespace hal

#endif /* HAL_OPENCV_WINDOWS_VIDEO_CAMERA_H */