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
	char x[100], y;
	int i, count = 0;
	printf("Enter a string: ");
	fflush(stdout); fflush(stdin);
	gets(x);
	printf("\nEnter a character to find frequency: ");
	fflush(stdout); fflush(stdin);
	scanf("%c", &y);
	if(y >= 'a' && y <= 'z')
	{
		strlwr(x);
	}
	if(y >= 'A' && y <= 'Z')
	{
		strupr(x);
	}


	for(i = 0; i < strlen(x); i++)
	{
		if(x[i] == y)
		{
			count++;
		}
	}

	printf("\nFrequency of %c = %d\n", y, count);
}
