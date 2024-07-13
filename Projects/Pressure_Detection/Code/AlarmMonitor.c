/*
 * AlarmMonitor.c
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohanad
 */

#include "AlarmMonitor.h"

//States define
enum
{
	AM_alarmOFF,
	AM_alarmON,
	AM_waiting
}AM_state_id;

//State variables
int AM_Alarm_timer = 600;
int AM_Alarm_period = 600;

void (*AM_state)();

void HighPressure_detected()
{
	AM_state = STATE(AM_alarmON);
	//printf("Main Algo ------ High Pressure Detected ------ Alarm Monitor\n");
}

STATE_define(AM_alarmOFF)
{
	//State name
	AM_state_id = AM_alarmOFF;


	//printf("Alarm Monitor alarmOFF state\n");
}

STATE_define(AM_alarmON)
{
	//State name
	AM_state_id = AM_alarmON;

	//State action
	StartAlarm();
	//setTimer(AM_Alarm_period);

	//Event check
	AM_state = STATE(AM_waiting);

	//printf("Alarm Monitor alarmON state\n");
	//printf("Timer on 60 seconds\n");
}

STATE_define(AM_waiting)
{
	//State name
	AM_state_id = AM_waiting;


	//State action
	//timer begin
	//timer reset
	delay_ms(AM_Alarm_period);
	StopAlarm();

	//Event check
	AM_state = STATE(AM_alarmOFF);

	//printf("Alarm Monitor waiting state --> delay = %d\n", AM_Alarm_period);
}
