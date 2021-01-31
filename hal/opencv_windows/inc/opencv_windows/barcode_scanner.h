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

class WindowsBarcodeScanner;

typedef struct {
  int32_t count;

  ::std::string type[10];  // WindowsBarcodeScanner::MAX_SCAN_CODES];
  ::std::string data[10];  // WindowsBarcodeScanner::MAX_SCAN_CODES];

} WindowsBarcode;

class WindowsBarcodeScanner
    : public SensorInterface<WindowsBarcode, WindowsVideoCameraFrame> {
 public:
  WindowsBarcodeScanner();

  virtual ReturnResult<WindowsBarcode> GetValue(void) override;
  virtual ReturnResult<WindowsBarcode> GetMaxValue(void) override;
  virtual ReturnResult<WindowsBarcode> GetMinValue(void) override;
  virtual ReturnResult<void> SetValue(
      const WindowsVideoCameraFrame param) override;

  const uint8_t MAX_SCAN_CODES = 10;

 private:
  WindowsVideoCameraFrame frame_;
  WindowsBarcode decoded_objects_;
  ::zbar::ImageScanner scanner_;
};

}  // namespace hal

#endif /* HAL_OPENCV_WINDOWS_BARCODE_SCANNER_H */