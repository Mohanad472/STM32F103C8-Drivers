/*
 * FIFO.h
 *
 *  Created on: Sep 18, 2023
 *      Author: Mohanad
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "Platform_Types.h"

#define ELEMENT_TYPE	uint8
#define BUFFER_WIDTH	5

typedef struct
{
	unsigned int length;
	unsigned int count;
	ELEMENT_TYPE* base;
	ELEMENT_TYPE* head;
	ELEMENT_TYPE* tail;
}FIFO_Buf_t;

typedef enum
{
	FIFO_NO_ERROR,
	FIFO_EMPTY,
	FIFO_FULL,
	FIFO_NULL
}FIFO_Status;

FIFO_Status FIFO_init(FIFO_Buf_t* fifo, ELEMENT_TYPE* buf, uint8 length);
FIFO_Status FIFO_enqueue(FIFO_Buf_t* fifo, ELEMENT_TYPE* buf, ELEMENT_TYPE item);
FIFO_Status FIFO_dequeue(FIFO_Buf_t* fifo, ELEMENT_TYPE* buf);
FIFO_Status FIFO_is_full();
void FIFO_print(FIFO_Buf_t* fifo);

#endif /* FIFO_H_ */
