/*
 * main.c
 *
 *  Created on: Sep 17, 2023
 *      Author: Mohanad
 */

#include "stdio.h"
#include "string.h"
#include "Linked_List.h"

extern struct Sstudent* gpFirstStudent;

int main()
{
	char temp_text[40];
	int ID;
	int nodes_count;

	while(1)
	{
		DPRINTF("\n================================");
		DPRINTF("\n\t Choose one of the following options:");
		DPRINTF("\n\t 1. Add Student ");
		DPRINTF("\n\t 2. Delete Student ");
		DPRINTF("\n\t 3. View Students ");
		DPRINTF("\n\t 4. Delete All");
		DPRINTF("\n\t 5. Get Nth index");
		DPRINTF("\n\t 6. Show number of students");
		DPRINTF("\n\t 7. Get Nth index from the end");
		DPRINTF("\n\t 8. Get middle node");
		DPRINTF("\n\t 9. Reverse the list of students");
		DPRINTF("\n Enter Option Number: ");

		gets(temp_text);
		DPRINTF("\n================================\n");
		switch(atoi(temp_text))
		{
		case 1:
			AddStudent();
			break;
		case 2:
			Delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			delete_all();
			break;
		case 5:
			ID = GetNth();
			break;
		case 6:
			nodes_count = find_length(gpFirstStudent);
			DPRINTF("\nNumber of students = %d", nodes_count);
			break;
		case 7:
			ID = GetNth_node_from_end();
			break;
		case 8:
			ID = find_middle();
			break;
		case 9:
			reverse_list();
			break;
		default:
			DPRINTF("\n wrong option");
			break;
		}
	}
}
