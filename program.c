#include <xc.h>
#include "program.h"
#include "pins.h"
#include "heater.h"

unsigned char tmr0ElapsedCount = 0;
unsigned char blkinkedTimes = 0;

void startBlinking() {
  tmr0ElapsedCount = 0;
  blkinkedTimes = 0;
  TMR0 = TMR0_INITIAL;
}

void stopBlinking() {
  LED = 0;
}

void blink(unsigned char numberToBlink) {
  tmr0ElapsedCount++;
  if (LED == 1) {
    if (tmr0ElapsedCount == BLINK_ON_PERIOD) {
      LED = 0;
      tmr0ElapsedCount = 0;
    }
  } else {
    if (tmr0ElapsedCount ==
      (blkinkedTimes >= numberToBlink ? BLINK_OFF_BTWN_PACKS : BLINK_OFF_PERIOD)) {
      LED = 1;
      tmr0ElapsedCount = 0;
      if (blkinkedTimes >= numberToBlink) blkinkedTimes = 0;
      blkinkedTimes += HEATER_WORK_TIME_INC;
    }
  }
}