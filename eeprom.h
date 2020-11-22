/* 
 * File:   eeprom.h
 * Author: fedor
 *
 * Created on 22 ?????? 2020 ?., 19:00
 */

#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif

#define HEATER_WORK_TIME_ADDR 0x10
void initEEPROM();
unsigned char readByte(unsigned char address);
void writeByte(unsigned char address, unsigned char data);

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

