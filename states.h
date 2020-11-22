/* 
 * File:   states.h
 * Author: fedor
 *
 * Created on 14 ?????? 2020 ?., 10:31
 */

#ifndef STATES_H
#define	STATES_H

#ifdef	__cplusplus
extern "C" {
#endif
    
typedef enum {
    PROGRAM_MODE,
    HEATER_MODE
} Mode;

typedef struct {
  unsigned char halfSec; // number of a half of a second (0,5 sec)
  unsigned char min;
  unsigned char keyOffHalfSec; // half of a second when key was pressed
  unsigned char heaterWorkTime; // In minutes
  Mode mode;
} State;

void mainReducer(State*, unsigned char*);

#ifdef	__cplusplus
}
#endif

#endif	/* STATES_H */

