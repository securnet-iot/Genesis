#include "barcode_scanner_engine.h"

BarcodeScannerEngine::BarcodeScannerEngine()
    : video_cam_{::hal::WindowsVideoCamera::Port::PORT_1},
      barcode_decoder_{},
      scanner_engine_{video_cam_, barcode_decoder_} {}

BarcodeScannerEngine ::~BarcodeScannerEngine() {}
