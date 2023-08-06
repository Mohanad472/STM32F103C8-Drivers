/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include <stdint.h>
#include <stdlib.h>

typedef volatile unsigned int vuint32_t ;
//define addresses 
#define RCC_BASE	0x40021000
#define GPIOA_BASE	0x40010800
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE   + 0x18) 
#define GPIOA_CRH   *(volatile uint32_t *)(GPIOA_BASE + 0x04) 
#define GPIOA_ODR   *(volatile uint32_t *)(GPIOA_BASE + 0x0C) 
//bit field 
#define RCC_IOPAEN (1<<2)
#define GPIOA13    (1UL<<13)
typedef union {
	vuint32_t all_bits ; 
	struct {
		vuint32_t reserved :13 ; 
		vuint32_t p_13 :1 ;
	}pin;
}R_ODR_T;

#define R_ODR ((volatile R_ODR_T*)(GPIOA_BASE + 0x0C))
volatile unsigned char g_var[3] = {1,2,3}; // global initilaized variable to create .data section 
volatile unsigned char b_var[3];
volatile unsigned const char cons_var[3]={1,2,3}; // constant variable to creat .rodata section 

void* _sbrk(int incr)
{
	extern unsigned int _E_bss;
	static unsigned char* heap_ptr = NULL;
	unsigned char* prev_heap_ptr;
	extern unsigned int _heap_End;

	if(heap_ptr == NULL)
		heap_ptr = (unsigned char*)&_E_bss;

	prev_heap_ptr = heap_ptr;

	if((heap_ptr + incr) > ((unsigned char*)&_heap_End))
		return (void*) NULL;
	
	heap_ptr += incr;

	return (void*) prev_heap_ptr;
}

int main(void)
{
	int* p = (int*)malloc(4);
	free(p); 
	int i=0;
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;
	
	while(1)
	{
		(R_ODR->pin.p_13) = 1;
		for(i=0 ; i<5000 ; i++);
		(R_ODR->pin.p_13) = 0;
		for(i=0 ; i<5000 ; i++);	
	}
}
	//end of embedded c code 
	
