/*
 * main.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Mohanad
 */

#include "CA.h"

void setup()
{
	CA_state = STATE(CA_waiting);
}

int main()
{
	setup();
	int i;

	while(1)
	{
		CA_state();
		for(i = 0; i < 1000; i++);
	}
}
