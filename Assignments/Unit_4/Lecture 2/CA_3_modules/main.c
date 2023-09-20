/*
 * main.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Mohanad
 */

#include "CA.h"
#include "DC.h"
#include "US.h"

void setup()
{
	DC_init();
	US_init();
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

int main()
{
	setup();
	int i;

	while(1)
	{
		US_state();
		CA_state();
		DC_state();
		for(i = 0; i < 1000; i++);
	}
}
