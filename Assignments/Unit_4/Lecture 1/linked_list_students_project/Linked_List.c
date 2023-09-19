/*
 * Linked_List.c
 *
 *  Created on: Sep 19, 2023
 *      Author: Mohanad
 */

#include "stdlib.h"
#include "conio.h"
#include "Linked_List.h"

struct Sstudent* gpFirstStudent = NULL;

void AddStudent()
{
	struct Sstudent* pNewStudent;
	struct Sstudent* pLastStudent;
	char temp_value[40];
	// first node create
	if(gpFirstStudent == NULL)
	{
		pNewStudent = (struct Sstudent*)malloc(sizeof(struct Sstudent));
		gpFirstStudent = pNewStudent;
	}
	// there are existing nodes
	else
	{
		// begin from the first node
		pLastStudent = gpFirstStudent;
		// navigate until reaching the last node
		while(pLastStudent->pNextStudent)
		{
			pLastStudent = pLastStudent->pNextStudent;
		};
		//create new node
		pNewStudent = (struct Sstudent*)malloc(sizeof(struct Sstudent));
		pLastStudent->pNextStudent = pNewStudent;
	}

	// assign the values
	DPRINTF("\nEnter the ID: ");
	gets(temp_value);
	pNewStudent->student.ID = atoi(temp_value);

	DPRINTF("Enter student's full name: ");
	gets(pNewStudent->student.name);

	DPRINTF("Enter the height: ");
	gets(temp_value);
	pNewStudent->student.height = atof(temp_value);

	// pointer to next node is NULL since it's the last node
	pNewStudent->pNextStudent = NULL;
}

int Delete_student()
{
	char temp_text[40];
	unsigned int selected_id;
	DPRINTF("Enter the student's ID to be deleted: ");
	gets(temp_text);
	selected_id = atoi(temp_text);

	// Enter if the list has at least one student
	if(gpFirstStudent)
	{
		struct Sstudent* pPreviousStudent = NULL;
		struct Sstudent* pSelectedStudent = gpFirstStudent;
		while(pSelectedStudent)
		{
			// if the ID is found
			if(selected_id == pSelectedStudent->student.ID)
			{
				// if the found student is the first one
				if(pSelectedStudent == gpFirstStudent)
				{
					gpFirstStudent = pSelectedStudent->pNextStudent;
				}
				// if the found student is not the first one
				else
				{
					pPreviousStudent->pNextStudent = pSelectedStudent->pNextStudent;
				}
				free(pSelectedStudent);
				return 1;
			}
			// if the ID is not found
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->pNextStudent;
		}
	}

	DPRINTF("\nThe student is not found.");
	return 0;
}

void view_students()
{
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	unsigned int count = 0;
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\nEmpty List.");
	}
	else
	{
		while(pCurrentStudent)
		{
			DPRINTF("\nStudent record %d", count+1);
			DPRINTF("\n\tID : %d", pCurrentStudent->student.ID);
			DPRINTF("\n\tName : %s", pCurrentStudent->student.name);
			DPRINTF("\n\tHeight : %f", pCurrentStudent->student.height);
			count++;
			pCurrentStudent = pCurrentStudent->pNextStudent;
		}
	}
}

void delete_all()
{

	struct Sstudent* pCurrentStudent = gpFirstStudent;
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\nEmpty List.");
	}
	else
	{
		struct Sstudent* pTempStudent = pCurrentStudent;
		pCurrentStudent = pCurrentStudent->pNextStudent;
		free(pTempStudent);
	}
	gpFirstStudent = NULL;
};

int GetNth()
{
	unsigned int count = 0;
	char temp_text[40];
	unsigned int index;
	DPRINTF("\nEnter the index: ");
	fgets(temp_text, 40, stdin);
	index = atoi(temp_text);

	struct Sstudent* pTempStudent = gpFirstStudent;

	if(gpFirstStudent == NULL)
	{
		DPRINTF("\nEmpty List.");
		return 0;
	}
	else
	{
		while(count != index)
		{
			if(pTempStudent->pNextStudent == NULL)
			{
				DPRINTF("\nIndex isn't found");
				return 0;
			}
			else
			{
				pTempStudent = pTempStudent->pNextStudent;
				count++;
			}
		}
		DPRINTF("\nStudent record %d", count+1);
		DPRINTF("\n\tID : %d", pTempStudent->student.ID);
		DPRINTF("\n\tName : %s", pTempStudent->student.name);
		DPRINTF("\n\tHeight : %f", pTempStudent->student.height);
	}
	return pTempStudent->student.ID;
}

int find_length(struct Sstudent* pCurrentStudent)
{
	if(pCurrentStudent == NULL)
	{
		return 0;
	}
	else
	{
		pCurrentStudent = pCurrentStudent->pNextStudent;
		return 1 + find_length(pCurrentStudent);
	}
}

int GetNth_node_from_end()
{
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\nEmpty List.");
		return 0;
	}
	else
	{
		struct Sstudent* pmain = gpFirstStudent;
		struct Sstudent* pref = gpFirstStudent;
		char temp_text[40];
		int index, i;

		DPRINTF("Enter the index: ");
		fgets(temp_text, 40, stdin);
		index = atoi(temp_text);

		if(index == 0)
		{
			printf("\nIndex should be 1 or greater");
			return 0;
		}

		for(i = 0; i < index; i++)
		{
			if(pref == NULL)
			{
				DPRINTF("\nEntered index is too large");
				return 0;
			}
			pref = pref->pNextStudent;
		}

		while(pref != NULL)
		{
			pmain = pmain->pNextStudent;
			pref = pref->pNextStudent;
		}

		DPRINTF("\n\tID : %d", pmain->student.ID);
		DPRINTF("\n\tName : %s", pmain->student.name);
		DPRINTF("\n\tHeight : %f", pmain->student.height);

		return pmain->student.ID;
	}
}

int find_middle()
{
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\nEmpty List.");
		return 0;
	}
	else
	{
		int count = 0;
		struct Sstudent* pFast = gpFirstStudent;
		struct Sstudent* pSlow = gpFirstStudent;

		while(pFast->pNextStudent != 0)
		{
			pSlow = pSlow->pNextStudent;
			count++;
			pFast = pFast->pNextStudent;
			if(pFast->pNextStudent == NULL)
			{
				break;
			}
			else
			{
				pFast = pFast->pNextStudent;
			}
		}

		DPRINTF("\nStudent record %d", count+1);
		DPRINTF("\n\tID : %d", pSlow->student.ID);
		DPRINTF("\n\tName : %s", pSlow->student.name);
		DPRINTF("\n\tHeight : %f", pSlow->student.height);

		return pSlow->student.ID;
	}
}

void reverse_list()
{
	if(gpFirstStudent == NULL)
		{
			DPRINTF("\nEmpty List.");
		}
	else
	{
		struct Sstudent* temp1 = NULL;
		struct Sstudent* temp2 = NULL;

		while(gpFirstStudent != NULL)
		{
			temp2 = gpFirstStudent->pNextStudent;
			gpFirstStudent->pNextStudent = temp1;
			temp1 = gpFirstStudent;
			gpFirstStudent = temp2;
		}
		gpFirstStudent = temp1;
	}

}
