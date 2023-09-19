/*
 * Linked_List.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Mohanad
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "stdio.h"

#define DPRINTF(...)		{fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

struct Sdata
{
	int ID;
	char name[100];
	float height;
};

struct Sstudent
{
	struct Sdata student;
	struct Sstudent* pNextStudent;
};

void AddStudent();
int Delete_student();
void view_students();
void delete_all();
int GetNth();
int find_length(struct Sstudent* pCurrentStudent);
int GetNth_node_from_end();
int find_middle();
void reverse_list();

#endif /* LINKED_LIST_H_ */
