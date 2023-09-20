/*
 * US.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Mohanad
 */

#ifndef US_H_
#define US_H_

#include "state.h"

extern void (*US_state)();

STATE_define(US_busy);
void US_init();

#endif /* US_H_ */
