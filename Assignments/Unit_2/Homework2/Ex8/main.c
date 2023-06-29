/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	char operator;
	float x, y;
	printf("Enter operator either  or - or * or divide: ");
	fflush(stdout);
	scanf("%c", &operator);
	fflush(stdin);
	printf("Enter two operands: ");
	fflush(stdout);
	scanf("%f %f", &x, &y);

	switch(operator)
	{
	case '+':
	{
		printf("%.1f %c %.1f = %.1f\r\n", x, operator, y, x+y);
	}
	break;

	case '-':
	{
		printf("%.1f %c %.1f = %.1f\r\n", x, operator, y, x-y);
	}
	break;

	case '*':
	{
		printf("%.1f %c %.1f = %.1f\r\n", x, operator, y, x*y);
	}
	break;

	case '/':
	{
		printf("%.1f %c %.1f = %.1f\r\n", x, operator, y, x/y);
	}
	break;

	default:
	{
		printf("Incorrect value of operand!\r\n");
	}
	break;
	}
}
