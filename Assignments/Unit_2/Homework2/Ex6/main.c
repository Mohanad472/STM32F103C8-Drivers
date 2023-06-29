/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	int n, sum = 0, i;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
	{
		sum += i;
	}

	printf("%d\r\n", sum);
}
