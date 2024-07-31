#include "stdio.h"

#define RCC_base	0x40021000
#define RCC_CR		*(volatile unsigned int *)(RCC_base + 0x00)
#define RCC_CFGR	*(volatile unsigned int *)(RCC_base + 0x04)

void main()
{
	/*
		 Bits 1:0 SW: System clock switch
		 	Set and cleared by software to select SYSCLK source.
			Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
			failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
			System is enabled).

			00: HSI selected as system clock
			01: HSE selected as system clock
			10: PLL selected as system clock
			11: not allowed
	 */
	RCC_CFGR |= (0b00)<<0;

	/*
	 Bit 0 HSION: Internal high-speed clock enable
		Set and cleared by software.
		Set by hardware to force the internal 8 MHz RC oscillator ON when leaving Stop or Standby
		mode or in case of failure of the external 4-16 MHz oscillator used directly or indirectly as
		system clock. This bit cannot be reset if the internal 8 MHz RC is used directly or indirectly
		as system clock or is selected to become the system clock.

		0: internal 8 MHz RC oscillator OFF
		1: internal 8 MHz RC oscillator ON
	 */
	RCC_CR |= (1<<0);

	/*
	 Bit 1 HSIRDY: Internal high-speed clock ready flag
		Set by hardware to indicate that internal 8 MHz RC oscillator is stable. After the HSION bit is
		cleared, HSIRDY goes low after 6 internal 8 MHz RC oscillator clock cycles.

		0: internal 8 MHz RC oscillator not ready
		1: internal 8 MHz RC oscillator ready
	 */
	while(!(RCC_CR &= (1<<1)));

	/*
	 Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
		Set and cleared by software to control the division factor of the APB low-speed clock
		(PCLK1).
		Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.

		0xx: HCLK not divided
		100: HCLK divided by 2
		101: HCLK divided by 4
		110: HCLK divided by 8
		111: HCLK divided by 16
	 */
	RCC_CFGR |= (0b100)<<8;

	/*
	 Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
		Set and cleared by software to control the division factor of the APB high-speed clock
		(PCLK2).

		0xx: HCLK not divided
		100: HCLK divided by 2
		101: HCLK divided by 4
		110: HCLK divided by 8
		111: HCLK divided by 16
	 */
	RCC_CFGR |= (0b101)<<11;

	while(1)
	{

	}
}
