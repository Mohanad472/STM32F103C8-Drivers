/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	float x, y, z;
	printf("Enter three numbers: ");
	fflush(stdout);
	scanf("%f %f %f", &x, &y, &z);

	if(x > y)
	{
		if(x > z)
			printf("Largest number = %.2f\r\n", x);
		else
			printf("Largest number = %.2f\r\n", y);
	}
	else
	{
		if(y > z)
			printf("Largest number = %.2f\r\n", y);
		else
			printf("Largest number = %.2f\r\n", z);
	}
}
