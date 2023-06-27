/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	int n, fact = 1;
	int i;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d", &n);

	if(n >= 0)
	{
		for(i = 1; i <= n; i++)
		{
			fact *= i;
		}

		printf("Factorial = %d\r\n", fact);
	}
	else
	{
		printf("Error!!! Factorial of a negative number doesn't exist\r\n");
	}
}
