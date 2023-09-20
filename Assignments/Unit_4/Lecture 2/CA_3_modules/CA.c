/*
 * CA.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Mohanad
 */

#include "CA.h"

int CA_distance = 0;
int CA_speed = 0;
int CA_threshold = 50;

enum
{
	CA_waiting,
	CA_driving
}CA_states_id;

void (*CA_state)();

void US_Set_distance(int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("US -----------distance = %d--------------> CA\n", CA_distance);
}

STATE_define(CA_waiting)
{
	// State name
	CA_states_id = CA_waiting;
	printf("CA_waiting State: distance = %d   Speed = %d\n", CA_distance, CA_speed);

	// State action
	CA_speed = 0;
	DC_motor(CA_speed);
}

STATE_define(CA_driving)
{
	// State name
	CA_states_id = CA_driving;
	printf("CA_driving State: distance = %d   Speed = %d\n", CA_distance, CA_speed);

	// State action
	CA_speed = 30;
	DC_motor(CA_speed);
}
