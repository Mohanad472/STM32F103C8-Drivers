/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	char x;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c", &x);
	printf("ASCII value of %c is = %d", x, x);
}


