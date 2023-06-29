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
	char c[1000], temp;
	int i;
	printf("Enter the string : ");
	fflush(stdout); fflush(stdin);
	scanf("%s", c);

	for( i = 0; i < strlen(c)/2; i++)
	{
		temp = c[i];
		c[i] = c[(strlen(c) - 1) - i];
		c[(strlen(c) - 1) - i] = temp;
	}

	printf("Reverse string is : %s", c);
}
