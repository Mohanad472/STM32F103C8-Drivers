/*
 * main.c
 *
 *  Created on: Jun 28, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	int n, i, search;
	printf("Enter no of elements : ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &n);
	int arr[n];

	for(i = 0; i < n; i++)
	{
		fflush(stdin);
		scanf("%d", &arr[i]);
	}

	printf("Enter the elements to be searched : ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &search);

	for(i = 0; i < n; i++)
	{
		if(arr[i] == search)
		{
			printf("Number found at the location = %d", i+1);
			break;
		}
	}
}
