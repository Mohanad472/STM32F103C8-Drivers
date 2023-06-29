/*
 * main.c
 *
 *  Created on: Jun 28, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	int rows, cols, i, j;
	printf("Enter rows and columns of matrix: ");
	fflush(stdout);
	scanf("%d %d", &rows, &cols);
	int a[rows][cols], t[cols][rows];
	printf("Enter elements of matrix:\n");
	fflush(stdout);

	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			printf("Enter elements a%d%d: ", i, j);
			fflush(stdout); fflush(stdin);
			scanf("%d", &a[i][j]);
		}
	}

	printf("Enter Matrix:\n");
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			printf("%d  ", a[i][j]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}

	printf("Transpose of Matrix:\n");
	for(i = 0; i < cols; i++)
	{
		for(j = 0; j < rows; j++)
		{
			t[i][j] = a[j][i];
		}
	}

	for(i = 0; i < cols; i++)
	{
		for(j = 0; j < rows; j++)
		{
			printf("%d  ", t[i][j]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}
}
