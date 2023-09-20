/*
 * state.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Mohanad
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

#define STATE_define(_state_FUN_)	void ST_##_state_FUN_()
#define STATE(_state_FUN_)			ST_##_state_FUN_

#endif /* STATE_H_ */
