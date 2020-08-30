#ifndef HAL_ACTUATOR_INTERFACE_H
#define HAL_ACTUATOR_INTERFACE_H

namespace hal {

template <typename T>
class ActuatorInterface {
 public:
  using ParamType T;

  virtual ActuatorInterface();

  virtual ParamType GetValue(void) = 0;
  virtual ParamType GetMaxValue(void) = 0;
  virtual ParamType GetMinValue(void) = 0;
  virtual void SetValue(const ParamType param) = 0;
};

template <typename T>
inline ActuatorInterface<T>::~ActuatorInterface() {}

}  // namespace hal

#endif /* HAL_ACTUATOR_INTERFACE_H */
