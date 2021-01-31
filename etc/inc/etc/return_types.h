#ifndef ETC_RETURN_INFO_H
#define ETC_RETURN_INFO_H

#include <iostream>
#include <opencv2/videoio/videoio.hpp>

using VideoFrame = cv::Mat;

typedef struct {
  int32_t count;

  ::std::string type[10];  // WindowsBarcodeScanner::MAX_SCAN_CODES];
  ::std::string data[10];  // WindowsBarcodeScanner::MAX_SCAN_CODES];

} BarcodeInfo;

#endif /* ETC_RETURN_INFO_H */
