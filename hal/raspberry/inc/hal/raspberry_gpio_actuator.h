#ifndef HAL_RASPBERRY_GPIO_ACTUATOR_H
#define HAL_RASPBERRY_GPIO_ACTUATOR_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "hal/actuator_interface.h"
#include "hal/raspberry_gpio.h"

namespace hal {

class GpioActiveHighActuator : ActuatorInterface<bool> {
 public:
  GpioActiveHighActuator(uint8_t pin);

  virtual bool GetValue(void) override;

  virtual bool GetMaxValue(void) override;

  virtual bool GetMinValue(void) override;

  virtual void SetValue(const bool param) override;

 private:
  void WriteToFile(const char *absoluteFileName, const char *contents);
  void Config(const uint8_t pin);
  void Deinit(const uint8_t pin);
  void Write(const uint8_t pin, const bool state);

  const uint8_t MaxPinCount = 100;  // TODO: Update with correct value

  uint8_t pin_;
  bool state_;
};

}  // namespace hal

#endif /* HAL_RASPBERRY_GPIO_ACTUATOR_H */
