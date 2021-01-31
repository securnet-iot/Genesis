#ifndef ENGINE_BARCODE_SCANNER_H
#define ENGINE_BARCODE_SCANNER_H

#include "hal/frame_interface.h"
#include "hal/sensor_interface.h"

namespace engine {

class BarcodeScanner {
 public:
  BarcodeScanner(
      ::hal::FrameInterface<VideoFrame> &frame,
      ::hal::SensorInterface<BarcodeInfo, VideoFrame> &barcode_scanner);

  ~BarcodeScanner();

  void ScanStart();

 private:
  ::hal::FrameInterface<VideoFrame> &frame_;
  ::hal::SensorInterface<BarcodeInfo, VideoFrame> &barcode_scanner_;
};

inline BarcodeScanner::~BarcodeScanner() {}

}  // namespace engine

#endif