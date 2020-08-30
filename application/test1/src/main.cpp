#include <iostream>
#include "helloworld.h"

int main(void) {
  std::cout << "Welcome to my World!\n\n";
  std::cout << "Rajesh is in this world!\n\n";
  std::cout << "corona also is here!\n\n";
  std::cout << "Working through Pandemic!\n\n";
  int i = 0;
  for (uint32_t temp = 0; temp < 100; temp++) {
  }

  HelloWorld helloworld;

  while (1) {
    helloworld.SetValue(1);
    sleep(1000);
    helloworld.SetValue(0);
    sleep(1000);
  }
}
