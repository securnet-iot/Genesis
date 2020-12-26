#ifndef HAL_SENSOR_INTERFACE_H
#define HAL_SENSOR_INTERFACE_H

namespace hal {

template <typename T>
class SensorInterface {
 public:
  using ParamType T;

  virtual SensorInterface();
  ~SensorInterface();

  virtual ParamType GetValue(void) = 0;
  virtual ParamType GetMaxValue(void) = 0;
  virtual ParamType GetMinValue(void) = 0;
  virtual void SetValue(const ParamType param) = 0;
};

template <typename T>
inline SensorInterface<T>::~SensorInterface() {}

}  // namespace hal

#endif /* HAL_SENSOR_INTERFACE_H */
