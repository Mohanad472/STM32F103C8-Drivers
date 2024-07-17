/*
 * student.c
 *
 *  Created on: Jul 15, 2024
 *      Author: Mohanad
 */

#include "fifo.h"

element_type st[width1];

FIFO_Buf_Status FIFO_init(FIFO_Buf_t *fifo, element_type *st, unsigned int length)
{
	if(fifo == 0 || st == 0)
	{
		return FIFO_null;
	}
	else
	{
		fifo->head = st;
		fifo->base = st;
		fifo->tail = st;
		fifo->length = length;
		fifo->count = 0;

		return FIFO_no_error;
	}
}

void add_student_file(FIFO_Buf_t *fifo)
{
	char line[100], ch, i, flag = 0;
	int roll_entered;
	element_type *temp = fifo->tail;
	FILE *fptr = fopen("student_info.txt", "r");
	if(fptr == 0)
	{
		printf("Not able to open the file\n");
	}
	else
	{
		while(fgets(line, 100, fptr))
		{
			temp = fifo->tail;
			flag = 0;
			char *token = strtok(line, " \n");
			roll_entered = atoi(token);
			flag = roll_number_found(fifo, roll_entered);
			if(flag == 1)
			{
				printf("[ERROR] Roll number %d is already taken\n", roll_entered);
				continue;
			}
			else
			{
				for(i = 0; i < 9; i++)
				{
					if(i == 0)
					{
						fifo->head->roll = atoi(token);
					}
					else if(i == 1)
					{
						strcpy(fifo->head->fname, token);
					}
					else if (i == 2)
					{
						strcpy(fifo->head->lname, token);
					}
					else if(i == 3)
					{
						fifo->head->GPA = strtof(token, 0);
					}
					else
					{
						fifo->head->cid[i-4] = atoi(token);
					}
					token = strtok(0, " \n");
				}
				if(fifo->head == fifo->base + fifo->length * sizeof(element_type))
				{
					fifo->head = fifo->base;
				}
				else
				{
					fifo->head++;
				}
				fifo->count++;
				printf("[INFO] Roll number %d saved successfully\n", roll_entered);
			}
		}	
	}
	printf("-----------------------------------\n");
	tot_s(fifo);
	fclose(fptr);
}

void add_student_manually(FIFO_Buf_t *fifo, element_type *st)
{
	int i, flag = 0, roll_entered;
	element_type *temp = fifo->tail;
	printf("Add the student details\n");
	printf("-----------------------\n");
	printf("Enter the roll number: ");
	scanf("%d", &roll_entered);
	fflush(stdin);
	flag = roll_number_found(fifo, roll_entered);
	if(flag == 0)
	{
		fifo->head->roll = roll_entered;
		printf("Enter the first name of the student: ");
		gets(fifo->head->fname);
		printf("Enter the last name of the student: ");
		gets(fifo->head->lname);
		printf("Enter the GPA you obtained: ");
		fflush(stdin);
		scanf("%f", &fifo->head->GPA);
		fflush(stdin);
		fflush(stdout);
		printf("Enter the course ID of each course\n");
		for(i = 0; i < 5; i++)
		{
			printf("Course %d ID: ", i+1);
			scanf("%d", &(fifo->head->cid[i]));
			fflush(stdin);
		};
		fifo->count++;
		if(fifo->head == fifo->base + fifo->length * sizeof(element_type))
		{
			fifo->head = fifo->base;
		}
		else
		{
			fifo->head++;
		}
		printf("[INFO] Student details is added successfully\n");
		printf("-----------------------------------\n");
		tot_s(fifo);
	}
	else
	{
		printf("[ERROR] Roll number %d is already taken\n", roll_entered);
	}
}

void find_rl(FIFO_Buf_t *fifo)
{
	element_type *temp = fifo->tail;
	int entered_rl, i, flag = 0;
	printf("Enter the roll number of the student: ");
	scanf("%d", &entered_rl);
	fflush(stdin);
	for(i = 0; i < fifo->count; i++)
	{
		if(entered_rl == temp->roll)
		{
			show_student_info(temp);
			flag = 1;
			break;
		}
		else
		{
			temp = temp_increment(fifo, temp);
		}
	}
	if(flag == 0)
	{
		printf("[ERROR] Roll Number %d not found\n", entered_rl);
	}
}

void find_fn(FIFO_Buf_t *fifo)
{
	element_type *temp = fifo->tail;
	char entered_fname[50];
	int i, flag = 0;
	printf("Enter the first name of the student: ");
	gets(entered_fname);
	fflush(stdin);
	for(i = 0; i < fifo->count; i++)
	{
		if(!stricmp(temp->fname, entered_fname))
		{
			show_student_info(temp);
			flag = 1;
			break;
		}
		else
		{
			temp = temp_increment(fifo, temp);
		}
	}
	if(!flag)
	{
		printf("[ERROR] First name %s not found\n", entered_fname);
	}
}

void find_c(FIFO_Buf_t *fifo)
{
	int entered_cid, i, j, flag = 0;
	printf("Enter the course ID: ");
	scanf("%d", &entered_cid);
	fflush(stdin);
	element_type *temp = fifo->tail;
	for(i = 0; i < fifo->count; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(temp->cid[j] == entered_cid)
			{
				printf("Student first name: %s\n", temp->fname);
				printf("Student last name: %s\n", temp->lname);
				printf("Student roll number: %d\n", temp->roll);
				printf("Student GPA: %.2f\n", temp->GPA);
				flag = 1;
			}
		}
		temp = temp_increment(fifo, temp);
	}
	if(!flag)
	{
		printf("[ERROR] Course id %d not found.\n", entered_cid);
	}
}

void tot_s(FIFO_Buf_t *fifo)
{
	printf("[INFO] The total number of students is %d\n", fifo->count);
	printf("[INFO] You can add up to %d students\n", width1);
	printf("[INFO] You can add %d more students\n", width1 - fifo->count);
}

void del_s(FIFO_Buf_t *fifo)
{
	int delete_rl, i, j, flag = 0;
	printf("Enter the roll number which you want to delete: ");
	scanf("%d", &delete_rl);
	fflush(stdin);
	element_type *temp = fifo->tail;
	for(i = 0; i < fifo->count; i++)
	{
		if(i == 0)
		{
			if(temp->roll == delete_rl)
			{
				fifo->tail->roll = 0;
				strcpy(fifo->tail->fname, "");
				strcpy(fifo->tail->lname, "");
				fifo->tail->GPA = 0.0;
				for(j = 0; j < 5; j++)
				{
					fifo->tail->cid[j] = 0;
				}
				if(fifo->tail == fifo->base + (fifo->length * sizeof(element_type)))
				{
					fifo->tail = fifo->base;
				}
				else
				{
					fifo->tail++;
				}
				flag = 1;
				fifo->count--;
			}
			else
			{
				temp = temp_increment(fifo, temp);
			}
		}
		else
		{
			if(temp->roll == delete_rl)
			{
				flag = 1;
				temp->roll = fifo->tail->roll;
				strcpy(temp->fname, fifo->tail->fname);
				strcpy(temp->lname, fifo->tail->lname);
				temp->GPA = fifo->tail->GPA;
				for(j = 0; j < 5; j++)
				{
					temp->cid[j] = fifo->tail->cid[j];
				};
				fifo->tail->roll = 0;
				strcpy(fifo->tail->fname, "");
				strcpy(fifo->tail->lname, "");
				fifo->tail->GPA = 0.0;
				for(j = 0; j < 5; j++)
				{
					fifo->tail->cid[j] = 0;
				}
				if(fifo->tail == fifo->base + (fifo->length * sizeof(element_type)))
				{
					fifo->tail = fifo->base;
				}
				else
				{
					fifo->tail++;
				}
				fifo->count--;
			}	
			else
			{
				temp = temp_increment(fifo, temp);
			}
		}
	}
	if(!flag)
	{
		printf("[ERROR] This roll number %d is not found\n", delete_rl);
	}
}

void up_s(FIFO_Buf_t *fifo)
{
	int entered_rl2, entered_choice, i, flag = 0;
	printf("Enter the roll number to update the entry: ");
	scanf("%d", &entered_rl2);
	fflush(stdin);
	element_type *temp = fifo->tail;
	flag = roll_number_found(fifo, entered_rl2);
	if(!flag)
	{
		printf("[ERROR] Roll number not found\n");
	}
	else
	{
		printf("1. first name\n");
		printf("2. last name\n");
		printf("3. roll no.\n");
		printf("4. GPA\n");
		printf("5. courses\n");
		scanf("%d", &entered_choice);
		fflush(stdin);
		switch(entered_choice)
		{
			case 1:
				printf("Enter the new first name: ");
				gets(temp->fname);
				fflush(stdin);
				break;	

			case 2:
				printf("Enter the new last name: ");
				gets(temp->lname);
				fflush(stdin);
				break;

			case 3:
				printf("Enter the new roll number: ");
				scanf("%d", &temp->roll);
				fflush(stdin);
				break;

			case 4:
				printf("Enter the new GPA: ");
				scanf("%f", &temp->GPA);
				fflush(stdin);
				break;

			case 5:
				for(i = 0; i < 5; i++)
				{
					printf("Course %d ID: ", i+1);
					scanf("%d", &(temp->cid[i]));
					fflush(stdin);
				};
				break;

			default:
				printf("Invalid choice\n");
				break;	
		}
	}
}

void show_s(FIFO_Buf_t *fifo)
{
	element_type *temp = fifo->tail;
	int i, j;
	for(i = 0; i < fifo->count; i++)
	{
		show_student_info(temp);
		temp = temp_increment(fifo, temp);
		printf("-----------------------------------\n");
	}
}


