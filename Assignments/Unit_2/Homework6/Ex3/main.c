/*
 * main.c
 *
 *  Created on: Jul 13, 2023
 *      Author: Mohanad
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char x[50], *p;
	printf("Input a string : ");
	fflush(stdout); fflush(stdin);
	fgets(x, 50, stdin);
	p = x;
	printf("Reverse of the string is : ");
	fflush(stdout);
	int i;
	for(i = strlen(x) - 2; i >= 0; i--)
	{
		printf("%c", *(p + i));
	}

	return 0;
}
