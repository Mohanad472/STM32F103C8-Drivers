/*
 * main.c
 *
 *  Created on: Sep 18, 2023
 *      Author: Mohanad
 */

#include "stdio.h"
#include "LIFO.h"

unsigned int buffer1[5];

int main()
{
	LIFO_Buf_t uart_lifo;
	LIFO_init(&uart_lifo, buffer1, 5);
	unsigned int i, temp;
	for(i = 0; i < 7; i++)
	{
		if(LIFO_add_item(&uart_lifo, i) == LIFO_NO_ERROR)
		{
			printf("Item added successfully\n");
		}
		else
		{
			printf("Error\n");
		}
	}
	for(i = 0; i < 7; i++)
	{
		if(LIFO_get_item(&uart_lifo, &temp) == LIFO_NO_ERROR)
		{
			printf("Item get: %d\n", temp);
		}
		else
		{
			printf("Error\n");
		}
	}
}
