#include "opencv_windows/barcode_scanner.h"

#include <zbar.h>

#include <opencv2/opencv.hpp>

namespace hal {

WindowsBarcodeScanner::WindowsBarcodeScanner() : frame_{} {
  scanner_.set_config(::zbar::ZBAR_NONE, ::zbar::ZBAR_CFG_ENABLE, 1);
}

ReturnResult<BarcodeInfo> WindowsBarcodeScanner::GetValue(void) {
  // Convert image to grayscale
  VideoFrame img_gray;
  ::cv::cvtColor(frame_, img_gray, ::cv::COLOR_BGR2GRAY);

  // Wrap image data in a zbar image
  ::zbar::Image image(frame_.cols, frame_.rows, "Y800", (uchar *)img_gray.data,
                      frame_.cols * frame_.rows);

  // Scan the image for barcodes and QRCodes
  decoded_objects_.count = scanner_.scan(image);

  if (!decoded_objects_.count) {
    return -1;
  }

  if (decoded_objects_.count > WindowsBarcodeScanner::MAX_SCAN_CODES) {
    decoded_objects_.count = WindowsBarcodeScanner::MAX_SCAN_CODES;
  }

  // Clear return buffers
  for (int count = 0; count < WindowsBarcodeScanner::MAX_SCAN_CODES; count++) {
    decoded_objects_.type[count] = {};
    decoded_objects_.data[count] = {};
  }

  ::zbar::Image::SymbolIterator symbol = image.symbol_begin();

  for (int32_t count = 0; count < decoded_objects_.count; count++) {
    decoded_objects_.type[count] = symbol->get_type_name();
    decoded_objects_.data[count] = symbol->get_data();

    ++symbol;
  }

  return decoded_objects_;
}

ReturnResult<BarcodeInfo> WindowsBarcodeScanner::GetMaxValue(void) {
  return -1;
}

ReturnResult<BarcodeInfo> WindowsBarcodeScanner::GetMinValue(void) {
  return -1;
}

ReturnResult<void> WindowsBarcodeScanner::SetValue(const VideoFrame frame) {
  frame_ = frame;

  return 0;
}

}  // namespace hal