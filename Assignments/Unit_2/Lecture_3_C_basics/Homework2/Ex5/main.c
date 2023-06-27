/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	char c;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c", &c);

	if((c > 64 && c < 91) || (c > 140 && c < 173))
	{
		printf("%c is an alphabet\r\n", c);
	}
	else
	{
		printf("%c is not an alphabet\r\n", c);
	}
}
