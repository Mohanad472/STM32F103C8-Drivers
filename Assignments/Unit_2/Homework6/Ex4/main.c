/*
 * main.c
 *
 *  Created on: Jul 13, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

int main()
{
	int arr[15], size, i, *p;
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &size);
	printf("Input %d number of elements in the array : \n", size);
	for(i = 0; i < size; i++)
	{
		printf("element - %d : ", i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d", &arr[i]);
	};

	p = &arr[size-1];
	printf("\nThe elements of array in reverse order are : \n");

	for(i = size; i > 0; i--)
	{
		printf("element - %d : %d\n", i, *p);
		p--;
	}
	return 0;
}
