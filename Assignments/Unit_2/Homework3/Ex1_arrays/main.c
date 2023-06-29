/*
 * main.c
 *
 *  Created on: Jun 28, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	float a[2][2], b[2][2], sum[2][2] = {{0,0},{0,0}};
	int i, j;

	printf("Enter the elements of 1st matrix\n");
	fflush(stdout);

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("Enter a%d%d	", i, j);
			fflush(stdout); fflush(stdin);
			scanf("%f", &a[i][j]);
		}
	}

	printf("Enter the elements of 2nd matrix\n");
	fflush(stdout);

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("Enter b%d%d	", i, j);
			fflush(stdout); fflush(stdin);
			scanf("%f", &b[i][j]);
		}
	}

	printf("Sum of matrix:\n");

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			sum[i][j] = a[i][j] + b[i][j];
			printf("%.1f\t", sum[i][j]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}
}
