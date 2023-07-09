/*
 * main.c
 *
 *  Created on: Jul 9, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

#define PI 3.14159265359
#define area(r) PI*r*r

void main()
{
	float radius;
	printf("Enter the radius: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &radius);
	printf("Area = %.2f", area(radius));
}
