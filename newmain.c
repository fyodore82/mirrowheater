/*
 * File:   newmain.c
 * Author: fedor
 *
 * Created on 1 ?????? 2020 ?., 21:55
 */

#include <xc.h>
#include "config.h"
#include "pins.h"
#include "states.h"
#include "interruptFlags.h"
#include "heater.h"
#include "program.h"

unsigned char intSync = 0x0;

void interrupt tc_int(void) {
  if (PIR1bits.TMR1IF) {
    PIR1bits.TMR1IF = 0;
    TMR1L = 0xDB;
    TMR1H = 0xB;
    intSync |= TMR1_INT_SYNC;
  }
  if (INTCONbits.T0IF) {
    INTCONbits.T0IF = 0;
    TMR0 = TMR0_INITIAL;
    intSync |= PROGRAM_LED_INT_SYNC;
  }
  if (INTCONbits.GPIF) {
    INTCONbits.GPIF = 0;
    char n = KEY;
    intSync |= KEY_INT_SYNC;
  }
  if (PIR1bits.EEIF) {
    PIR1bits.EEIF = 0;
    intSync |= EEPROM_INT_SYNC;
  }
}

void main(void) {

  // init interrupts
  PIR1 = 0;
  PIE1 = 0b00000001; // TMR1IE = 1
  INTCON = 0b11101000; // GIE = 1, PIE = 1, T0IE = 1, GPIE = 1;
  OPTION_REG = 0b10000111; // TMR0 1:256 prescaler
  initPins();
  initHeatTimer();

  State state;
  intSync = INIT;
  mainReducer(&state, &intSync);

  while (1) {
    if (intSync != 0) {
      mainReducer(&state, &intSync);
    }
  }
  return;
}
