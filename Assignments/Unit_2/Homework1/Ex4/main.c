/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	float x, y;
	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%f %f", &x, &y);
	printf("Product: %f", x*y);
}


