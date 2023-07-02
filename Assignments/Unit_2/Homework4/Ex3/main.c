/*
 * main.c
 *
 *  Created on: Jul 2, 2023
 *      Author: Mohanad
 */

#include <stdio.h>
#include <string.h>

void reverse();

void main()
{
	printf("Enter a sentence: ");
	fflush(stdout);
	reverse();
}

void reverse()
{
	char c;
	scanf("%c", &c);
	if(c != '\n')
	{
		reverse();
	}
	printf("%c", c);
}

