#include "uart.h"

unsigned char string_buffer[100] = "learn-in-depth:Mohanad";
unsigned char const string_buffer2[100] = "learn-in-depth:Mohanad";
unsigned char const string_buffer3[100] = "learn-in-depth:Mohanad";
unsigned char const string_buffer4[100] = "learn-in-depth:Mohanad";

void main(void)
{
	Uart_Send_String(string_buffer);
}