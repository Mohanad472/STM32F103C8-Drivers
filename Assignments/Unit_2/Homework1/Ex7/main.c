/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	int x, y;
	printf("Enter variable x: ");
	fflush(stdout);
	scanf("%d", &x);
	fflush(stdin);
	printf("Enter variable y: ");
	fflush(stdout);
	scanf("%d", &y);

	x = x + y;
	y = x - y;
	x = x - y;
	printf("After swapping\r\n");
	printf("x = %d \r\ny = %d \r\n", x, y);
}
