#include "hal/raspberry_gpio_actuator.h"

GpioActiveHighActuator::GpioActiveHighActuator(uint8_t pin)
    : pin_{pin}, state_{false} {}

void GpioActiveHighActuator::WriteToFile(const char *absoluteFileName,
                                         const char *contents) {
  int fd = open(absoluteFileName, O_WRONLY);

  if (-1 == fd) {
    fprintf(stderr, "Couldn't open %s for writing!\n", absoluteFileName);
    exit(1);
  }

  int contentsLength = strlen(contents);

  if (write(fd, contents, contentsLength) != contentsLength) {
    fprintf(stderr, "Failed to write entire value %s to %s!\n", contents,
            absoluteFileName);
    close(fd);
    exit(1);
  }

  close(fd);
}

void GpioActiveHighActuator::Config(const uint8_t pin) {
  WriteToFile("/sys/class/gpio/export", pin);

  char buf[33];
  struct stat statBuf;
  int pinExported = -1;

  sprintf(buf, "/sys/class/gpio/gpio%s/direction", pin);

  // May have to briefly wait for OS to make symlink!
  while (pinExported != 0) {
    sleep(1);
    pinExported = stat(buf, &statBuf);
  }

  WriteToFile(buf, "out");
}

void GpioActiveHighActuator::Deinit(const uint8_t pin) {
  WriteToFile("/sys/class/gpio/unexport", pin);
}

void GpioActiveHighActuator::Write(const uint8_t pin, const bool state) {
  char buf[29];
  sprintf(buf, "/sys/class/gpio/gpio%s/value", pin);
  WriteToFile(buf, state);
}

bool GpioActiveHighActuator::GetValue(void) { return state_; }

bool GpioActiveHighActuator::GetMaxValue(void) { return 1; }

bool GpioActiveHighActuator::GetMinValue(void) { return 0; }

void GpioActiveHighActuator::SetValue(const bool param) { Write(pin_, param); }
