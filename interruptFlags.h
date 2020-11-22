/* 
 * File:   interruptFlags.h
 * Author: fedor
 *
 * Created on 14 ?????? 2020 ?., 10:55
 */

#ifndef INTERRUPTFLAGS_H
#define	INTERRUPTFLAGS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define INIT                  0b10000000
#define TMR1_INT_SYNC         0b00000001
#define PROGRAM_LED_INT_SYNC  0b00000010
#define KEY_INT_SYNC          0b00000100
#define EEPROM_INT_SYNC       0b00001000

#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPTFLAGS_H */

