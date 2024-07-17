/*
 * student.h
 *
 *  Created on: Jul 15, 2024
 *      Author: Mohanad
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct
{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[10];
}sinfo;

//User configuration
//Select the element type
#define element_type	sinfo

//Create buffer
#define width1	50
extern element_type st[width1];

//FIFO data types
typedef struct
{
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_Buf_Status;

//APIs
FIFO_Buf_Status FIFO_init(FIFO_Buf_t *fifo, element_type *st, unsigned int length);
void add_student_file();
void add_student_manually(FIFO_Buf_t *fifo, element_type *st);
void find_rl(FIFO_Buf_t *fifo);
void find_fn(FIFO_Buf_t *fifo);
void find_c(FIFO_Buf_t *fifo);
void tot_s(FIFO_Buf_t *fifo);
void del_s(FIFO_Buf_t *fifo);
void up_s(FIFO_Buf_t *fifo);
void show_s(FIFO_Buf_t *fifo);

#endif /* STUDENT_H_ */
