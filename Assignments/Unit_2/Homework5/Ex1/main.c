/*
 * main.c
 *
 *  Created on: Jul 9, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

struct Sstudents{
	char m_name[50];
	int m_roll;
	float m_marks;
} s;

struct Sstudents read_info()
{
	struct Sstudents x;
	printf("Enter information of students: \n\n");
	printf("Enter name: ");
	fflush(stdout); fflush(stdin);
	fgets(x.m_name, 50, stdin);
	printf("Enter roll number: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &x.m_roll);
	printf("Enter marks: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &x.m_marks);

	return x;
}

void display_info(struct Sstudents x)
{
	printf("\nDisplaying information\n\nName: %sRoll: %d\nMarks: %.2f\n", x.m_name, x.m_roll, x.m_marks);
}

void main()
{
	s = read_info();
	display_info(s);
}
