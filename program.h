/* 
 * File:   program.h
 * Author: fedor
 *
 * Created on 15 ?????? 2020 ?., 21:22
 */

#ifndef PROGRAM_H
#define	PROGRAM_H

#ifdef	__cplusplus
extern "C" {
#endif

#define TMR0_INITIAL 0x3D   // With this initial value Tmr0 will expire in 0,05 sec
#define BLINK_ON_PERIOD 4   // Number of 50ms intervals when LED will be ON. 4 = 200 ms
#define BLINK_OFF_PERIOD 20 - 4 // Number of 50ms intervals when LED will be OFF. 20 - 4 = 15 = 800 ms
#define BLINK_OFF_BTWN_PACKS 40 // Number of 50ms intervals to wait after showing heater delay. 40 = 2sec
void startBlinking();
void stopBlinking();
void blink(unsigned char);

#ifdef	__cplusplus
}
#endif

#endif	/* PROGRAM_H */

