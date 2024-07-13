/*
 * AlarmActuatorDriver.c
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohanad
 */

#include "AlarmActuatorDriver.h"
#include "stdio.h"
#include "stdlib.h"

//States define
enum
{
	AAD_waiting,
}AAD_state_id;

void (*AAD_state)();

void StartAlarm()
{
	//printf("Alarm Monitor ------ Start Alarm ------ Alarm Actuator Driver\n");
	Set_Alarm_actuator(1);
	AAD_state = STATE(AAD_waiting);
}

void StopAlarm()
{
	//printf("Alarm Monitor ------ Stop Alarm ------ Alarm Actuator Driver\n");
	Set_Alarm_actuator(0);
	AAD_state = STATE(AAD_waiting);
}

void AAD_init()
{
	//Alarm Actuator Driver initialization
	//printf("Alarm Actuator Driver initialization\n");
}

STATE_define(AAD_waiting)
{
	//State name
	AAD_state_id = AAD_waiting;


	//printf("Alarm Actuator Driver waiting state\n");
}
