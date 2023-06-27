/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	float a, b, temp;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f", &a);
	fflush(stdin);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f", &b);
	temp = a;
	a = b;
	b = temp;
	printf("After swapping, value of a = %.2f\r\n", a);
	printf("After swapping, value of b = %.1f\r\n", b);
}


