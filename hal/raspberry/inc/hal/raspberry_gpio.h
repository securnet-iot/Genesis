#ifndef HAL_RASPBERRY_GPIO_H
#define HAL_RASPBERRY_GPIO_H

namespace hal {

enum class GpioPort { PORT_A, PORT_B, PORT_C, PORT_D };

enum Gpio {
  A00 = PortPinCombine(PORT_A, 0),
  A01 = PortPinCombine(PORT_A, 1),
  A02 = PortPinCombine(PORT_A, 2),
  A03 = PortPinCombine(PORT_A, 3),
  A04 = PortPinCombine(PORT_A, 4),
  A05 = PortPinCombine(PORT_A, 5),
  A06 = PortPinCombine(PORT_A, 6),
  A07 = PortPinCombine(PORT_A, 7),
};

enum GpioDir { OUTPUT, INPUT, UNDEFINED };
enum GpioPull { PULLUP, PULLDOWN, NOPULL };

struct GpioConfig {
  GpioPort port;
  uint8_t pin;
  GpioDir direction;
  GpioPull pull;
  bool default_state;
};

void GpioInit(void);

}  // namespace hal

#endif /* HAL_RASPBERRY_GPIO_ACTUATOR_H */
