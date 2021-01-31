#ifndef HAL_SENSOR_INTERFACE_H
#define HAL_SENSOR_INTERFACE_H

#include "etc/return_result.h"
#include "etc/return_types.h"

namespace hal {

template <typename T, typename U>
class SensorInterface {
 public:
  using ParamType = T;
  using SetValueType = U;

  ~SensorInterface();

  virtual ReturnResult<ParamType> GetValue(void) = 0;
  virtual ReturnResult<ParamType> GetMaxValue(void) = 0;
  virtual ReturnResult<ParamType> GetMinValue(void) = 0;
  virtual ReturnResult<void> SetValue(const SetValueType param) = 0;
};

template <typename T, typename U>
inline SensorInterface<T, U>::~SensorInterface() {}

}  // namespace hal

#endif /* HAL_SENSOR_INTERFACE_H */
