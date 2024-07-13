/*
 * AlarmActuatorDriver.h
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohanad
 */

#ifndef ALARMACTUATORDRIVER_H_
#define ALARMACTUATORDRIVER_H_

#include "state.h"
#include "stdio.h"
#include "stdlib.h"

STATE_define(AAD_waiting);
void AAD_init();

//State pointer to function
extern void (*AAD_state)();

#endif /* ALARMACTUATORDRIVER_H_ */
