#ifndef HAL_CAMERA_INTERFACE_H
#define HAL_CAMERA_INTERFACE_H

#include "etc/return_result.h"

namespace hal {

template <typename T>
class CameraInterface {
 public:
  using ParamType = T;

  virtual ~CameraInterface();

  virtual ReturnResult<ParamType> GetFrame() = 0;
  virtual void ShowFrame(ParamType frame) = 0;
  // virtual bool IsAvailable() = 0;
};

template <typename T>
inline CameraInterface<T>::~CameraInterface() {}

}  // namespace hal

#endif /* HAL_CAMERA_INTERFACE_H */