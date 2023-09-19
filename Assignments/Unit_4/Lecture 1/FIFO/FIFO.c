/*
 * FIFO.c
 *
 *  Created on: Sep 18, 2023
 *      Author: Mohanad
 */

#include "FIFO.h"
#include "stdlib.h"

FIFO_Status FIFO_init(FIFO_Buf_t* fifo, ELEMENT_TYPE* buf, uint8 length)
{
	if(!buf)
	{
		return FIFO_NULL;
	}

	fifo->length = length;
	fifo->count = 0;
	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;

	return FIFO_NO_ERROR;
}

FIFO_Status FIFO_enqueue(FIFO_Buf_t* fifo, ELEMENT_TYPE* buf, ELEMENT_TYPE item)
{
	if(!fifo->head || !fifo->base || !fifo->tail)
	{
		return FIFO_NULL;
	}

	if(FIFO_is_full(fifo) == FIFO_FULL)
	{
		return FIFO_FULL;
	}

	*(fifo->head) = item;
	fifo->count++;

	if(fifo->head == (fifo->base + (fifo->length * sizeof(ELEMENT_TYPE))))
	{
		fifo->head = fifo->base;
	}
	else
	{
		fifo->head++;
	}

	return FIFO_NO_ERROR;
}

FIFO_Status FIFO_dequeue(FIFO_Buf_t* fifo, ELEMENT_TYPE* item)
{
	if(!fifo->head || !fifo->base || !fifo->tail)
	{
		return FIFO_NULL;
	}

	*item = *(fifo->tail);
	fifo->count--;

	if(fifo->tail == (fifo->base + (fifo->length * sizeof(ELEMENT_TYPE))))
	{
		fifo->tail = fifo->base;
	}
	else
	{
		fifo->tail++;
	}

	return FIFO_NO_ERROR;
}

FIFO_Status FIFO_is_full(FIFO_Buf_t* fifo)
{
	if(!fifo->head || !fifo->base || !fifo->tail)
	{
		return FIFO_NULL;
	};

	if(fifo->count == fifo->length)
	{
		return FIFO_FULL;
	};

	return FIFO_NO_ERROR;
}

void FIFO_print(FIFO_Buf_t* fifo)
{
	if(fifo->count == 0)
	{
		printf("\nFIFO is empty.");
	}
	else
	{
		ELEMENT_TYPE* temp = fifo->tail;
		printf("\n=============== FIFO print ===============\n");
		uint8 i;
		for(i = 0; i < fifo->count; i++)
		{
			printf("\t %X \n", *temp);
			temp++;
		}
		printf("==========================================\n");
	}
}
