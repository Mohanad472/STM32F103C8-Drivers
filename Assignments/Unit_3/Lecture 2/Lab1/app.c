#include "uart.h"
unsigned char string_buffer[100] = "Learn-in-depth:<Mohanad>";
unsigned const char string_buffer2[100] = "hello";
void main(void)
{
	Uart_Send_string(string_buffer);
}