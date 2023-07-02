/*
 * main.c
 *
 *  Created on: Jul 2, 2023
 *      Author: Mohanad
 */
#include <stdio.h>

void print_prime(int a, int b);

void main()
{
	int x, y;
	printf("Enter two numbers(intervals): ");
	fflush(stdout); fflush(stdin);
	scanf("%d %d", &x, &y);
	print_prime(x, y);
}

void print_prime(int a, int b)
{
	int i, j;
	char flag;				// flag is set when the number is not prime

	printf("Prime numbers between %d and %d are: ", a, b);

	for(i = a+1; i < b; i++)		// loop that checks every element from a to b
	{
		flag = 0;
		for(j = 2; j < i/2; j++)
		{
			if(i%j == 0)		// then it's not prime
			{
				flag = 1;
			}
		}
		if(!flag)
		{
			printf("%d ", i);
		}
	}
}
