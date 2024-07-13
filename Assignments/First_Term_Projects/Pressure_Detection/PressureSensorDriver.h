/*
 * PressureSensorDriver.h
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohanad
 */

#ifndef PRESSURESENSORDRIVER_H_
#define PRESSURESENSORDRIVER_H_

#include "state.h"
#include "stdio.h"
#include "stdlib.h"

STATE_define(PS_reading);
STATE_define(PS_waiting);
void PS_init();

//State pointer to function
extern void (*PS_state)();

#endif /* PRESSURESENSORDRIVER_H_ */
