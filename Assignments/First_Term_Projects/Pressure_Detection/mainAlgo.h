/*
 * mainAlgo.h
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohanad
 */

#ifndef MAINALGO_H_
#define MAINALGO_H_

#include "state.h"
#include "stdio.h"
#include "stdlib.h"

STATE_define(MA_HighPressureDetect);

//State pointer to function
extern void (*MA_state)();

#endif /* MAINALGO_H_ */
