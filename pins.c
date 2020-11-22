#include <xc.h>
#include "pins.h"
#include "config.h"
#include "heater.h"

void initPins(void) {
  GPIO = 0x0;
  ANSEL = 0x0; // All digital
  CMCON = 0b00000111; // Comparator OFF
  TRISIO = 0b00100000; // GP5 (KEY) is only input
  WPU = 0x0;
  IOC = 0b00100000;
}

// button is ON when not pushed

KeyState getKeyState() {
  unsigned char checkTimes = CHECK_TIMES;
  unsigned char keyChecks = 0;
  while (checkTimes--) {
    if (KEY == 0) keyChecks++;
    else keyChecks--;
    __delay_ms(3);
  }

  return keyChecks == CHECK_TIMES ? KEY_OFF : KEY_ON;
}
