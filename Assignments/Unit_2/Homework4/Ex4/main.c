/*
 * main.c
 *
 *  Created on: Jul 2, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

int power(int base, int p);

void main()
{
	int a, b;
	printf("Enter base number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &a);
	printf("Enter power number(positive integer): ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &b);
	printf("%d^%d = %d", a, b, power(a, b));
}

int power(int base, int p)
{
	if(p == 1)
		return base;
	if(p == 0)
		return 1;

	return base * power(base, p-1);
}

