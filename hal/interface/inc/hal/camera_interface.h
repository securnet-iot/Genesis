#ifndef HAL_CAMERA_INTERFACE_H
#define HAL_CAMERA_INTERFACE_H

#include "etc/return_result.h"

namespace hal {

template <typename T>
class CameraInterface {
 public:
  using Frame = T;

  virtual ~CameraInterface();

  virtual ReturnResult<Frame> GetFrame() = 0;
  virtual ReturnResult<void> ShowFrame(Frame frame) = 0;
  virtual ReturnResult<bool> IsAvailable() = 0;
  virtual ReturnResult<void> SaveFrameAsJpg(::std::string file_path,
                                            ::std::string file_name,
                                            Frame frame);
};

template <typename T>
inline CameraInterface<T>::~CameraInterface() {}

}  // namespace hal

#endif /* HAL_CAMERA_INTERFACE_H */