/*
 * mainAlgo.c
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohanad
 */

#include "mainAlgo.h"

//States define
enum
{
	MA_HighPressureDetect,
}MA_state_id;

//State variables
int MA_threshold = 20;
int MA_Pval = 0;

void (*MA_state)();

void set_pressure_val(int Pval)
{
	//printf("Pressure Sensor Driver ------ Set Pressure Value ------ Main Algo\n");

	MA_Pval = Pval;
	if(MA_Pval > MA_threshold)
		HighPressure_detected();
	MA_state = STATE(MA_HighPressureDetect);
}

STATE_define(MA_HighPressureDetect)
{
	//State name
	MA_state_id = MA_HighPressureDetect;

	//printf("MainAlgo High Pressure Detect state --> Pval = %d\n", MA_Pval);
}
