/*
 * main.c
 *
 *  Created on: Jul 15, 2024
 *      Author: Mohanad
 */

#include "student.h"

int choice;

int main()
{
	element_type st[width1];
	FIFO_Buf_t fifo;
	FIFO_init(&fifo, st, width1);

	printf("Welcome to the Student Management System\n");
	printf("Choose the task you want to perform\n");
	printf("1. Add the student details manually\n");
	printf("2. Add the student details from text file\n");
	printf("3. Find the student details by roll number\n");
	printf("4. Find the student details by first name\n");
	printf("5. Find the student details by course id\n");
	printf("6. Find the total number of students\n");
	printf("7. Delete the students details by roll number\n");
	printf("8. Update the students details by roll number\n");
	printf("9. Show all information\n");
	printf("10. To Exit\n");

	while(1)
	{
		printf("-----------------------------------\n");
		printf("Enter your choice to perform the task: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d", &choice);
		fflush(stdin);
		fflush(stdout);
		printf("-----------------------------------\n");
		switch(choice)
		{
		case 1:
			add_student_manually(&fifo, st);
			break;
		
		case 2:
			add_student_file(&fifo);
			break;

		case 3:
			find_rl(&fifo);
			break;

		case 4:
			find_fn(&fifo);
			break;

		case 5:
			find_c(&fifo);
			break;

		case 6:
			tot_s(&fifo);
			break;

		case 7:
			del_s(&fifo);
			break;

		case 8:
			up_s(&fifo);
			break;

		case 9:
			show_s(&fifo);
			break;

		case 10:
			exit(0);
			break;

		default:
			printf("Invalid choice\n");
			break;
		}
	}
}
