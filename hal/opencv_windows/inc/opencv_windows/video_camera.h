#ifndef HAL_OPENCV_WINDOWS_VIDEO_CAMERA_H
#define HAL_OPENCV_WINDOWS_VIDEO_CAMERA_H

#include <opencv2/video.hpp>
#include <opencv2/videoio/videoio.hpp>

#include "etc/return_types.h"
#include "hal/frame_interface.h"

namespace hal {

class WindowsVideoCamera : public FrameInterface<VideoFrame> {
 public:
  enum class Port {
    PORT_0 = 0,
    PORT_1,
    PORT_2,
    PORT_3,
  };

  WindowsVideoCamera(const Port port);

  virtual ReturnResult<VideoFrame> GetFrame() override;
  virtual ReturnResult<void> ShowFrame(VideoFrame frame) override;
  virtual ReturnResult<bool> IsAvailable() override;
  virtual ReturnResult<void> SaveFrameAsJpg(::std::string file_path,
                                            ::std::string file_name,
                                            VideoFrame frame) override;

 private:
  ::cv::VideoCapture camera_;
  Port port_;
  VideoFrame frame_;
  bool is_camera_opened_;
};

}  // namespace hal

#endif /* HAL_OPENCV_WINDOWS_VIDEO_CAMERA_H */