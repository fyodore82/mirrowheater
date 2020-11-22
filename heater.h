/* 
 * File:   heater.h
 * Author: fedor
 *
 * Created on 14 ?????? 2020 ?., 19:47
 */

#ifndef HEATER_H
#define	HEATER_H

#ifdef	__cplusplus
extern "C" {
#endif

// see heatTimer.c
#define MIN_IN_TIMER_ROLLOVERS 114U
#define MAX_HEATER_WORK_TIME 30     // Maximum time the heater works. In minutes,
#define INITIAL_HEATER_WORK_TIME 5  // Initial (minimum) heater work time. In minutes
#define HEATER_WORK_TIME_INC 5      // Number of minutes to increment heater work time
                                    // on each key press

void initHeatTimer();
void turnOnHeater ();
void turnOffHeater ();
void toggleHeater();
void processHeaterTmrInterrupt(unsigned char);


#ifdef	__cplusplus
}
#endif

#endif	/* HEATER_H */

