/*
 * main.c
 *
 *  Created on: Jul 9, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

struct Scomplex
{
	float m_real;
	float m_img;
}c1, c2, sum;

struct Scomplex read(struct Scomplex x)
{
	printf("Enter real and imaginary respectively: ");
	fflush(stdout); fflush(stdin);
	scanf("%f%f", &x.m_real, &x.m_img);
	return x;
}

struct Scomplex add(struct Scomplex a, struct Scomplex b)
{
	struct Scomplex result;
	result.m_real = a.m_real + b.m_real;
	result.m_img = a.m_img + b.m_img;
	return result;
}

void main()
{
	printf("For 1st complex number\n");
	c1 = read(c1);
	printf("\nFor 2st complex number\n");
	c2 = read(c2);
	sum = add(c1, c2);
	printf("Sum = %.1f+%.1fi", sum.m_real, sum.m_img);
}
