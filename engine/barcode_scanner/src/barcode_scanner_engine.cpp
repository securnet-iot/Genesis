#include "barcode_scan/barcode_scanner_engine.h"

namespace engine {

BarcodeScannerEngine::BarcodeScannerEngine(
    ::hal::CameraInterface<VideoFrame> &frame,
    ::hal::SensorInterface<BarcodeInfo, VideoFrame> &barcode_scanner)
    : frame_{frame}, barcode_scanner_{barcode_scanner} {}

void BarcodeScannerEngine::ScanStart() {
  while (1) {
    ReturnResult<VideoFrame> frame_return{frame_.GetFrame()};

    if (frame_return.IsValid()) {
      frame_.ShowFrame(frame_return.Value());

      barcode_scanner_.SetValue(frame_return.Value());
      ReturnResult<BarcodeInfo> info_exepcted{barcode_scanner_.GetValue()};

      if (info_exepcted.IsValid()) {
        ::std::cout << ::std::endl
                    << "****** Scanned Info ******" << ::std::endl;
        for (int count = 0; count < info_exepcted.Value().count; count++) {
          ::std::cout << ::std::to_string(count) + ":  "
                      << "Type: " << info_exepcted.Value().type[count]
                      << "        "
                      << "Data: " << info_exepcted.Value().data[count]
                      << ::std::endl;
        }

        frame_.SaveFrameAsJpg("bin", "ScannedImage", frame_return.Value());
      }

      usleep(200000);
    }

    if (::cv::waitKey(30) >= 0) {
      break;
    }
  }
}

}  // namespace engine