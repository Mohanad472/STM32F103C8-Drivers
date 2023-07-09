/*
 * main.c
 *
 *  Created on: Jul 9, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

typedef struct Sstudent
{
	char m_roll;
	char m_name[50];
	char m_marks;
}Sstudent;

Sstudent read_info(char roll)
{
	Sstudent x;
	x.m_roll = roll;
	printf("\nFor roll number %d\n", x.m_roll);
	printf("Enter name: ");
	fflush(stdout); fflush(stdin);
	fgets(x.m_name, 50, stdin);
	printf("Enter marks: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &x.m_marks);

	return x;
}

void display_info(Sstudent student)
{
	printf("Information for roll number %d:\n", student.m_roll);
	printf("Name: %sMarks: %d\n\n", student.m_name, student.m_marks);
}

void main()
{
	Sstudent student[10];
	int i;
	printf("Enter information of students: \n");
	for(i = 0; i < 10; i++)
	{
		student[i] = read_info(i+1);
	};
	printf("\nDisplaying information of students: \n\n");
	for(i = 0; i < 10; i++)
	{
		display_info(student[i]);
	};
}
