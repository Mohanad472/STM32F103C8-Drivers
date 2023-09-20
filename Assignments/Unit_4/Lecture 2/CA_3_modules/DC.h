/*
 * DC.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Mohanad
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"

extern void (*DC_state)();

STATE_define(DC_idle);
STATE_define(DC_busy);
void DC_motor(int s);
void DC_init();

#endif /* DC_H_ */
