/*
 * main.c
 *
 *  Created on: Jul 13, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

struct Semployee
{
	char name[50];
	int ID;
};

int main()
{
	struct Semployee emp1 = {"Ahmed", 1000}, emp2 = {"Adel", 1001}, emp3 = {"Mohanad", 1002};
	struct Semployee (*p_arr[]) = {&emp1, &emp2, &emp3};
	struct Semployee *(*p)[3] = &p_arr;

//	printf("%s\n", (*p[0])->name);
//	printf("%d\n", (*p[0]) -> ID);
//	printf("%s\n", p_arr[1] -> name);
//	printf("%d\n", p_arr[1] -> ID);
//	printf("%s\n", p_arr[2] -> name);
//	printf("%d\n", p_arr[2] -> ID);

	int i;
	for(i = 0; i < 3; i++)
   {
		printf("Employee name : %s\n", (*(*p+i))->name);
		printf("Employee ID : %d\n\n", (*(*p+i))->ID);
	//	p++;
	}

	return 0;

//	int arr[] = {1, 2, 3};
//	int *p_arr[3] = {&arr[0], &arr[1], &arr[2]};
//	int *(*p)[3] = &p_arr;
//	printf("%d\n", (**(*p+1)));
//	printf("%d", arr[0]);
}
