#ifndef APP_BARCODE_SCANNER_ENGINE_H
#define APP_BARCODE_SCANNER_ENGINE_H

#include "barcode_scanner/barcode_scanner.h"
#include "opencv_windows/barcode_decoder.h"
#include "opencv_windows/video_camera.h"

class BarcodeScannerEngine {
 public:
  BarcodeScannerEngine();
  ~BarcodeScannerEngine();

 private:
  ::hal::WindowsVideoCamera video_cam_;
  ::hal::WindowsBarcodeDecoder barcode_decoder_;
  ::engine::BarcodeScanner scanner_engine_;
};

#endif