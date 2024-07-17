#include "fifo.h"

char roll_number_found(FIFO_Buf_t *fifo, int roll_entered)
{
	int i;
	element_type *temp = fifo->tail;
	for(i = 0; i < fifo->count; i++)
	{
		if(temp->roll == roll_entered)
		{
			return 1;
		}
		else
		{
			if(temp == fifo->base + (fifo->length * sizeof(element_type)))
			{
				temp = fifo->base;
			}
			else
			{
				temp++;
			}
		}
	}
	return 0;
}

void show_student_info(element_type *temp)
{
	int j;
	printf("Student first name: %s\n", temp->fname);
	printf("Student last name: %s\n", temp->lname);
	printf("Student roll number: %d\n", temp->roll);
	printf("Student GPA: %.2f\n", temp->GPA);
	for(j = 0; j < 5; j++)
	{
		printf("The course ID is: %d\n", temp->cid[j]);
	};
}

element_type* temp_increment(FIFO_Buf_t *fifo, element_type *temp)
{
	if(temp == (fifo->base) + (fifo->length) * sizeof(element_type))
	{
		temp = (fifo->base);
	}
	else
	{
		temp++;
	}
	return temp;
}