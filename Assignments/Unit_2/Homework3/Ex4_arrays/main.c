/*
 * main.c
 *
 *  Created on: Jun 28, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	int n, new, location, i;
	printf("Enter no of elements : ");
	fflush(stdout);
	scanf("%d", &n);
	int a[n+1];
	for(i = 0; i < n; i++)
	{
		fflush(stdin);
		scanf("%d", &a[i]);
	}

	printf("Enter the element to be inserted : ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &new);

	printf("Enter the location : ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &location);

	for(i = n - 1; i >= location - 1; i--)
	{
		a[i+1] = a[i];
	}

	a[location-1] = new;

	for(i = 0; i <= n; i++)
	{
		printf("%d ", a[i]);
		fflush(stdout);
	}
}
