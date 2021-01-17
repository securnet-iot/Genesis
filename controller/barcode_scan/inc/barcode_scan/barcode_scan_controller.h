#ifndef CONTROLLER_BARCODE_SCAN_H
#define CONTROLLER_BARCODE_SCAN_H

#include "hal/camera_interface.h"

namespace controller {

class BarcodeScanController {
 public:
  BarcodeScanController(::hal::CameraInterface camera);

 private:
  void DisplayVideo();

  ::hal::CameraInterface camera_;
};

}  // namespace controller

#endif