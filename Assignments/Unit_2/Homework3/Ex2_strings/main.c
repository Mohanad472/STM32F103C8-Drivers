/*
 * main.c
 *
 *  Created on: Jun 29, 2023
 *      Author: Mohanad
 */

#include <stdio.h>
#include <string.h>

void main()
{
	char c[1000];
	int i, count = 0;
	printf("Enter a string: ");
	fflush(stdout); fflush(stdin);
	gets(c);

	for( i = 0; c[i] != 0; i++)
	{
		count++;
	}

	printf("\nLength of string: %d", count);
}
