#include <xc.h>

void initEEPROM() {
  EECON1 = 0b00000100; // Enable EEPROM write
}

unsigned char readByte(unsigned char address) {
  EEADR = address;
  EECON1bits.RD = 1;
  return EEDATA;
}

void writeByte(unsigned char address, unsigned char data) {
  EEADR = address;
  EEDATA = data;
  
  unsigned char gie = INTCONbits.GIE;
  INTCONbits.GIE = 0;
  EECON2 = 0x55;
  EECON2 = 0xAA;
  EECON1bits.WR = 1;
  INTCONbits.GIE = gie;
}