#ifndef HAL_OPENCV_WINDOWS_BARCODE_SCANNER_H
#define HAL_OPENCV_WINDOWS_BARCODE_SCANNER_H

#include <zbar.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio/videoio.hpp>

#include "hal/sensor_interface.h"
#include "opencv_windows/video_camera.h"

namespace hal {

class WindowsBarcodeScanner : public SensorInterface<BarcodeInfo, VideoFrame> {
 public:
  WindowsBarcodeScanner();

  virtual ReturnResult<BarcodeInfo> GetValue(void) override;
  virtual ReturnResult<BarcodeInfo> GetMaxValue(void) override;
  virtual ReturnResult<BarcodeInfo> GetMinValue(void) override;
  virtual ReturnResult<void> SetValue(const VideoFrame param) override;

  const uint8_t MAX_SCAN_CODES = 10;

 private:
  VideoFrame frame_;
  BarcodeInfo decoded_objects_;
  ::zbar::ImageScanner scanner_;
};

}  // namespace hal

#endif /* HAL_OPENCV_WINDOWS_BARCODE_SCANNER_H */