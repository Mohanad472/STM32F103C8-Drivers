/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mohanad
 */

#include <stdio.h>

void main()
{
	char c;
	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c", &c);

	switch(c)
	{
	case 'a':
	case 'A':
	{
		printf("%c is a vowel\r\n", c);
	}
	break;

	case 'e':
	case 'E':
	{
		printf("%c is a vowel\r\n", c);
	}
	break;

	case 'i':
	case 'I':
	{
		printf("%c is a vowel\r\n", c);
	}
	break;

	case 'o':
	case 'O':
	{
		printf("%c is a vowel\r\n", c);
	}
	break;

	case 'u':
	case 'U':
	{
		printf("%c is a vowel\r\n", c);
	}
	break;

	default:
	{
		printf("%c is a consonant\r\n", c);
	}
	}
}
