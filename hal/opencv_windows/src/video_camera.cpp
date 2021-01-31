#include "opencv_windows/video_camera.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>

namespace hal {

using namespace cv;

WindowsVideoCamera::WindowsVideoCamera(const Port port)
    : camera_{static_cast<uint8_t>(port)},
      port_{port},
      frame_{0},
      is_camera_opened_{false} {
  if (camera_.isOpened()) {
    is_camera_opened_ = true;
  }
}

ReturnResult<VideoFrame> WindowsVideoCamera::GetFrame(void) {
  if (is_camera_opened_) {
    camera_.read(frame_);
  } else {
    return -1;
  }
  return frame_;
}

ReturnResult<void> WindowsVideoCamera::ShowFrame(VideoFrame frame) {
  if (is_camera_opened_) {
    imshow("Camera Frame", frame);
    return {};
  } else {
    return -1;
  }
}

ReturnResult<bool> WindowsVideoCamera::IsAvailable() {
  return is_camera_opened_;
}

ReturnResult<void> WindowsVideoCamera::SaveFrameAsJpg(::std::string file_path,
                                                      ::std::string file_name,
                                                      VideoFrame frame) {
  ::std::string file_path_name = file_path + "/" + file_name + ".jpg";
  printf(file_path_name.c_str());
  if (imwrite(file_path_name, frame)) {
    return {};
  } else {
    return -1;
  }
}

}  // namespace hal