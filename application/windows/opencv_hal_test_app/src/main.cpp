#include <iostream>

#include "barcode_scanner/barcode_scanner_engine.h"
#include "opencv_windows/barcode_scanner.h"
#include "opencv_windows/video_camera.h"
#include "tchain/types.h"

/* ------------------------------------------------------------------------ */
/*  Main entry point */
int main() {
  printf("~~~~ App Start ...\n");

  ::hal::WindowsVideoCamera video_cam = {
      ::hal::WindowsVideoCamera::Port::PORT_1};
  ::hal::WindowsBarcodeScanner barcode_scanner = {};
  ::engine::BarcodeScannerEngine scanner_engine = {video_cam, barcode_scanner};

  scanner_engine.ScanStart();

  printf("~~~~ Closed ...\n");
}
