#ifndef HAL_CAMERA_INTERFACE_H
#define HAL_CAMERA_INTERFACE_H

namespace hal {

template <typename T>
class CameraInterface {
 public:
  using ParamType T;

  virtual CameraInterface();
  ~CameraInterface();

  virtual ParamType GetFrame() = 0;
  virtual ParamType ShowFrame() = 0;
};

template <typename T>
inline CameraInterface::~CameraInterface() {}

}  // namespace hal

#endif /* HAL_CAMERA_INTERFACE_H */