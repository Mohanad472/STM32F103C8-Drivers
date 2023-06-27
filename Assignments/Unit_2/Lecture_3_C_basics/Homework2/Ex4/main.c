/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	float x;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%f", &x);

	if(x == 0)
	{
		printf("You entered zero.\r\n");
	}
	else if(x > 0)
	{
		printf("%.2f is positive.\r\n", x);
	}
	else
	{
		printf("%.2f is negative.\r\n", x);
	}
}
