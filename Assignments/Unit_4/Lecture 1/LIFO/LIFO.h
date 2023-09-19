/*
 * LIFO.h
 *
 *  Created on: Sep 18, 2023
 *      Author: Mohanad
 */

#ifndef LIFO_H_
#define LIFO_H_

typedef struct
{
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buf_t;

typedef enum
{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_NULL,
	LIFO_EMPTY
}LIFO_status;

LIFO_status LIFO_init(LIFO_Buf_t* lifo, unsigned int* item, unsigned int length);
LIFO_status LIFO_get_item(LIFO_Buf_t* lifo, unsigned int *item);
LIFO_status LIFO_add_item(LIFO_Buf_t* lifo, unsigned int item);

#endif /* LIFO_H_ */
