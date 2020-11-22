#include <xc.h>
#include "states.h"
#include "pins.h"
#include "heater.h"
#include "interruptFlags.h"
#include "program.h"
#include "eeprom.h"

unsigned char const minKeyPressedForProgram = 3 * 2; // minimum number of half seconds key should be pressed
                                                     // to go to the programming mode

void mainReducer(State* state, unsigned char* intSync) {
  if ((*intSync) & INIT) {
    state -> halfSec = 0;
    state -> min = 0;
    state -> keyOffHalfSec = 0;
    state -> mode = HEATER_MODE;
    state -> heaterWorkTime = readByte(HEATER_WORK_TIME_ADDR);
    if (state -> heaterWorkTime > MAX_HEATER_WORK_TIME
      || state -> heaterWorkTime < INITIAL_HEATER_WORK_TIME)
      state -> heaterWorkTime = INITIAL_HEATER_WORK_TIME;
  }
  if ((*intSync) & TMR1_INT_SYNC) {
    state -> halfSec++;
    if (state -> halfSec == 120) {
      state -> min++;
      state -> halfSec = 0;
    }
    if (state -> min == 60) state -> min = 0;
    processHeaterTmrInterrupt(state -> min);
  }
  if (((*intSync) & PROGRAM_LED_INT_SYNC) && state -> mode == PROGRAM_MODE) {
    blink(state -> heaterWorkTime);
  }
  if ((*intSync) & KEY_INT_SYNC) {
    KeyState keyState = getKeyState();
    if (keyState == KEY_OFF) {
      state -> keyOffHalfSec = state -> halfSec;
    } else {
      unsigned char keyPressedTime =  state -> keyOffHalfSec > state -> halfSec
        ? state -> keyOffHalfSec - state -> halfSec : state -> halfSec - state -> keyOffHalfSec;
      // short key press
      if (keyPressedTime < minKeyPressedForProgram) {
        if (state -> mode == HEATER_MODE) toggleHeater();
        else {
          if (state -> heaterWorkTime >= MAX_HEATER_WORK_TIME)
            state -> heaterWorkTime = INITIAL_HEATER_WORK_TIME;
          state -> heaterWorkTime += HEATER_WORK_TIME_INC;
        }
      // long key press
      } else {
        turnOffHeater();
        if (state -> mode == HEATER_MODE) {
          state -> mode = PROGRAM_MODE;
          startBlinking();
        }
        else {
          writeByte(HEATER_WORK_TIME_ADDR, state -> heaterWorkTime);
          state -> mode = HEATER_MODE;
          stopBlinking();
        }
      }
    }
  }
  *intSync = 0;
}
