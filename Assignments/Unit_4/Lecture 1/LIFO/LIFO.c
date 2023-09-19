/*
 * LIFO.c
 *
 *  Created on: Sep 18, 2023
 *      Author: Mohanad
 */

#include "LIFO.h"

LIFO_status LIFO_init(LIFO_Buf_t* lifo, unsigned int* item, unsigned int length)
{
	if(!item)
	{
		return LIFO_NULL;
	}

	lifo->base = item;
	lifo->head = item;
	lifo->count = 0;
	lifo->length = length;

	return LIFO_NO_ERROR;
}

LIFO_status LIFO_get_item(LIFO_Buf_t* lifo, unsigned int *item)
{
	if(lifo->count == 0)
	{
		return LIFO_EMPTY;
	}

	if(!lifo->base || !lifo->head)
	{
		return LIFO_NULL;
	}

	lifo->head--;
	*item = *(lifo->head);
	lifo->count--;

	return LIFO_NO_ERROR;

}

LIFO_status LIFO_add_item(LIFO_Buf_t* lifo, unsigned int item)
{
	if(lifo->count == lifo->length)
	{
		return LIFO_FULL;
	}

	if(!lifo->base || !lifo->head)
	{
		return LIFO_NULL;
	}

	*(lifo->head) = item;
	lifo->head++;
	lifo->count++;

	return LIFO_NO_ERROR;
}
