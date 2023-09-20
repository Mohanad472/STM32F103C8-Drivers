/*
 * DC.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Mohanad
 */

#include "DC.h"

int DC_speed = 0;

enum
{
	DC_idle,
	DC_busy
}DC_states_id;

void (*DC_state)();

void DC_motor(int s)
{
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("CA -----------speed = %d--------------> DC\n", DC_speed);
}

void DC_init()
{
	// DC_init
	printf("DC_init\n");
}

STATE_define(DC_idle)
{
	// State name
	DC_states_id = DC_idle;
	printf("DC_idle State: Speed = %d\n", DC_speed);
}

STATE_define(DC_busy)
{
	// State name
	DC_states_id = DC_busy;

	DC_state = STATE(DC_idle);

	printf("DC_driving State: Speed = %d\n", DC_speed);
}
