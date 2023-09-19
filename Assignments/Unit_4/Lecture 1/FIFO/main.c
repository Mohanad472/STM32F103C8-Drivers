/*
 * main.c
 *
 *  Created on: Sep 18, 2023
 *      Author: Mohanad
 */

#include "stdio.h"
#include "FIFO.h"

ELEMENT_TYPE uart_buffer[BUFFER_WIDTH];

int main()
{
	FIFO_Buf_t FIFO_UART;
	if(FIFO_init(&FIFO_UART, uart_buffer, BUFFER_WIDTH) == FIFO_NO_ERROR)
	{
		printf("\n============== DONE ===============");
	}

	ELEMENT_TYPE i;
	for(i = 0; i < 7; i++)
	{
		if(FIFO_enqueue(&FIFO_UART, uart_buffer, i) == FIFO_NO_ERROR)
		{
			printf("\nItem enqueued successfully");
		}
		else
		{
			printf("\nError enqueue the item");
		}
	}

	FIFO_print(&FIFO_UART);

	ELEMENT_TYPE temp;
	FIFO_dequeue(&FIFO_UART, &temp);
	printf("\nItem Dequeued is %d", temp);

	FIFO_dequeue(&FIFO_UART, &temp);
	printf("\nItem Dequeued is %d", temp);

	FIFO_print(&FIFO_UART);
}
