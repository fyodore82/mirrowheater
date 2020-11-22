/* 
 * File:   pins.h
 * Author: fedor
 *
 * Created on 8 ?????? 2020 ?., 20:18
 */

#ifndef PINS_H
#define	PINS_H

#ifdef	__cplusplus
extern "C" {
#endif

//extern unsigned char const key;
//extern unsigned char const led;
//extern unsigned char const relay;

#define KEY GP5
#define LED GP4
#define HEATER GP2
    
#define CHECK_TIMES 3
    
typedef enum { KEY_ON, KEY_OFF } KeyState;
    
void initPins(void);
KeyState getKeyState();
   
#ifdef	__cplusplus
}
#endif

#endif	/* PINS_H */

