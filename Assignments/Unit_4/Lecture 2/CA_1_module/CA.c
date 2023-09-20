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

int CA_Get_distance_random(int l, int r, int count);

STATE_define(CA_waiting)
{
	// State name
	CA_states_id = CA_waiting;

	// State action
	CA_speed = 0;

	// Event check
	CA_distance = CA_Get_distance_random(45, 55, 100);
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));

	printf("CA_waiting State: distance = %d   Speed = %d\n", CA_distance, CA_speed);
}

STATE_define(CA_driving)
{
	// State name
	CA_states_id = CA_driving;

	// State action
	CA_speed = 30;

	// Event check
	CA_distance = CA_Get_distance_random(45, 55, 100);
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));

	printf("CA_driving State: distance = %d   Speed = %d\n", CA_distance, CA_speed);
}

int CA_Get_distance_random(int l, int r, int count)		// CA_distance random generator
{
	// this will generate random number in range l and r (low and range)
	int i;
	for(i = 0; i < count; i++)
	{
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
}
