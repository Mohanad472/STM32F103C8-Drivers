/*
 * CA.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Mohanad
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

extern void (*CA_state)();

STATE_define(CA_waiting);
STATE_define(CA_driving);

#endif /* CA_H_ */
