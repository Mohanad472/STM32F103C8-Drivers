/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	int x;
	printf("Enter an integer you want to check: ");
	fflush(stdout);
	scanf("%d", &x);
	float y = x;
	if(x/2 < y/2)
	{
		printf("%d is an odd number\r\n", x);
	}
	else
	{
		printf("%d is an even number\r\n", x);
	}
}
