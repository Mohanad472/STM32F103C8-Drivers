/*
 * main.c
 *
 *  Created on: Jul 2, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

int factorial(int num);

void main()
{
	int a;
	printf("Enter a positive integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &a);
	printf("Factorial of %d = %d", a, factorial(a));
}

int factorial(int num)
{
	if(num > 1)
	{
		return (num * factorial(num-1));
	}
	else
	{
		return 1;
	}
}
