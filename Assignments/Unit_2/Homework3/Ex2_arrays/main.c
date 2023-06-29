/*
 * main.c
 *
 *  Created on: Jun 28, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	int n, i;
	printf("Enter the number of data: ");
	fflush(stdout);
	scanf("%d", &n);
	float values[n], sum = 0.0;

	for(i = 0; i < n; i++)
	{
		printf("%d. Enter number: ", i+1);
		fflush(stdout), fflush(stdin);
		scanf("%f", &values[i]);
		sum+= values[i];
	}

	printf("Average = %.2f", sum/n);
}
