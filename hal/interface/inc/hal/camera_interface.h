#ifndef HAL_CAMERA_INTERFACE_H
#define HAL_CAMERA_INTERFACE_H

namespace hal {

template <typename T>
class CameraInterface {
 public:
  using ParamType = T;

  virtual ~CameraInterface();

  virtual ParamType GetFrame() = 0;
  virtual void ShowFrame(ParamType frame) = 0;
};

template <typename T>
inline CameraInterface<T>::~CameraInterface() {}

}  // namespace hal

#endif /* HAL_CAMERA_INTERFACE_H */