#ifndef ENGINE_BARCODE_SCANNER_H
#define ENGINE_BARCODE_SCANNER_H

#include "hal/frame_interface.h"
#include "hal/sensor_interface.h"

namespace engine {

class BarcodeScannerEngine {
 public:
  BarcodeScannerEngine(
      ::hal::FrameInterface<VideoFrame> &frame,
      ::hal::SensorInterface<BarcodeInfo, VideoFrame> &barcode_scanner);

 private:
  void ScanStart();

  ::hal::FrameInterface<VideoFrame> &frame_;
  ::hal::SensorInterface<BarcodeInfo, VideoFrame> &barcode_scanner_;
};

}  // namespace engine

#endif