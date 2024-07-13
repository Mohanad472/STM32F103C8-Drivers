/*
 * state.h
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohanad
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>
#include "driver.h"

#define STATE_define(_statFUN_)	void ST_##_statFUN_()
#define STATE(_statFUN_)	ST_##_statFUN_

void set_pressure_val(int Pval);
void HighPressure_detected();
void StartAlarm();
void StopAlarm();
void delay_ms(int milliseconds);

#endif /* STATE_H_ */
