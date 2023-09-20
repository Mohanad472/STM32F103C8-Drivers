/*
 * US.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Mohanad
 */

#include "US.h"

int US_distance = 0;

enum
{
	US_busy
}US_states_id;

void (*US_state)();

int US_Get_distance_random(int l, int r, int count);

void US_init()
{
	// US_init()
	printf("US_init\n");
}

STATE_define(US_busy)
{
	// State name
	US_states_id = US_busy;

	// Event check
	US_distance = US_Get_distance_random(45, 55, 100);

	US_state = STATE(US_busy);
	printf("US_busy State: distance = %d\n", US_distance);
	US_Set_distance(US_distance);
}

int US_Get_distance_random(int l, int r, int count)		// US_distance random generator
{
	// this will generate random number in range l and r (low and range)
	int i;
	for(i = 0; i < count; i++)
	{
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
}
