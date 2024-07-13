/*
 * PressureSensorDriver.c
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohanad
 */

#include "PressureSensorDriver.h"
#include <stdio.h>
#include <stdlib.h>

//States define
enum
{
	PS_reading,
	PS_waiting
}PS_state_id;

//State variables
int Psensor_pull_time = 100;
int Pval = 0;

void (*PS_state)();

void PS_init()
{
	//Pressure Sensor Driver initialization
	//printf("Pressure Sensor initialization\n");
}

STATE_define(PS_reading)
{
	//State name
	PS_state_id = PS_reading;


	//State action
	Pval = getPressureVal();
	//printf("Pressure Sensor Driver reading state --> Pval = %d\n", Pval);
	set_pressure_val(Pval);
	//setTimer(Psensor_pull_time);

	//Event check
	PS_state = STATE(PS_waiting);
}

STATE_define(PS_waiting)
{
	//State name
	PS_state_id = PS_waiting;


	//State action
	//timer begin
	//timer reset
	delay_ms(Psensor_pull_time);

	//Event check
	PS_state = STATE(PS_reading);

	//printf("Pressure Sensor Driver waiting state --> Pval = %d, delay = %d\n", Pval, Psensor_pull_time);
}

// Function to provide a delay in milliseconds
void delay_ms(int milliseconds) {
	// Assuming a 1 MHz clock frequency for illustration purposes
	// Adjust the loop count based on your actual clock frequency
	// This is a simple and blocking delay function
	// In a real application, you might want to use a timer for more accurate timing

	// Calculate the loop count needed for the specified delay
	int loop_count = milliseconds * 1000;

	// Perform the delay using a loop
	int i;
	for (i = 0; i < loop_count; i++) {
		// Do nothing
	}
}
