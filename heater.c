#include <xc.h>
#include "heater.h"
#include "config.h"
#include "pins.h"
//#include "states.h"

unsigned int timeElapsed = 0;  // in timer rollovers, which is 0,524288 sec
                               // 1 min = 114,44 rollowers, or 114 for simlicity

void initHeatTimer() {
  // Init Tmr1
  T1CON = 0b00110000; // 1:8 prescaler
                      // 1 timer rollover is (8/4000000) * 65536 = 0,524288 sec
}

void turnOnHeater () {
  LED = 1;
  HEATER = 1;
  timeElapsed = 0;
  T1CONbits.TMR1ON = 1;
}

void turnOffHeater () {
  T1CONbits.TMR1ON = 0;
  LED = 0;
  HEATER = 0;
}

void toggleHeater() {
  if (HEATER == 1) turnOffHeater();
  else turnOnHeater();
}

void processHeaterTmrInterrupt(unsigned char targetTimeMin) {
  if (HEATER == 1) {
    timeElapsed++;
    unsigned int target = (unsigned int)targetTimeMin * MIN_IN_TIMER_ROLLOVERS;
    if (timeElapsed >= target)
      turnOffHeater();
  }
}
