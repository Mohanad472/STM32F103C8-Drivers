/*
 * AlarmMonitor.h
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohanad
 */

#ifndef ALARMMONITOR_H_
#define ALARMMONITOR_H_

#include "state.h"
#include "stdio.h"
#include "stdlib.h"

STATE_define(AM_alarmOFF);
STATE_define(AM_alarmON);
STATE_define(AM_waiting);

//State pointer to function
extern void (*AM_state)();

#endif /* ALARMMONITOR_H_ */
