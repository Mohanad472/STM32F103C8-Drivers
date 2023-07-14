/*
 * main.c
 *
 *  Created on: Jul 13, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	char a[27];
	char *p = a;
	int i;

	for(i = 0; i < 26; i++)
	{
		*(p+i) = 'A' + i;
	}

	printf("The Alphabets are:\n");
	for(i = 0; i < 26; i++)
	{
		printf("%c ", p[i]);
	}
}
