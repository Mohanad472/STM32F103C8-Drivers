/*
 * main.c
 *
 *  Created on: Jul 9, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

struct Sdistance
{
	int m_feet;
	float m_inch;
}d1, d2, sum;

void main()
{
	printf("Enter information for 1st distance\nEnter feet: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &d1.m_feet);
	printf("Enter inch: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &d1.m_inch);
	printf("\nEnter information for 2st distance\nEnter feet: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &d2.m_feet);
	printf("Enter inch: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &d2.m_inch);

	sum.m_feet = d1.m_feet + d2.m_feet;
	sum.m_inch = d1.m_inch + d2.m_inch;
	if(sum.m_inch >= 12)
	{
		sum.m_feet++;
		sum.m_inch -= 12;
	}

	printf("\nSum of distances = %d' - %.1f\"", sum.m_feet, sum.m_inch);
}
