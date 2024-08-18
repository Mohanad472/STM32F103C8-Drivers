#include "stm32f103x8.h"
#include "stm32f103c8_GPIO.h"
#include "stm32f103c8_EXTI.h"

uint8_t IRQ_Flag = 0;
int VAL1 = 3;
int VAL2 = 7;
int VAL3 = 0;
int control_val = 0;
int ipsr_val = 0;

void EXTI9_IRQ_fun(void)
{
	IRQ_Flag = 1;

	__asm("MRS %[out1], IPSR"
				:[out1] "=r" (ipsr_val)
				:);
}

int main()
{
	//Enable clock
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9;
	EXTI_CFG.Trigger_Case = EXTI_Trigger_Rising;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_Enable;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_IRQ_fun;
	MCAL_EXTI_GPIO_Init(&EXTI_CFG);

	IRQ_Flag = 1;

	/*
	 * LAB 1
	 */
	__asm("nop \n\t nop \n\t nop");


	/*
	 * LAB 2
	 */
	//mov VAL1, 0xff
	//Make the assembly see the variable VAL1

	//	__asm("mov %0, #0xff"		//__asm("pattern")
	//		   : "=r" (VAL1));		//output parameters :"specifier" (variable)
	//=r means use general purpose register
	//= means write only


	/*
	 * LAB 3
	 */
	//mov 0xff, VAL1
	//	__asm("mov R0, %0"
	//			:					//output parameters
	//			:"r" (VAL1));		//Input parameters
	//r without = means read and write


	/*
	 * LAB 4
	 */
	//add VAL3, VAL1, VAL2
	//	__asm("add %0, %1, %2"
	//			:"=r" (VAL3) 		//Output parameters
	//			:"r" (VAL1),		//Input parameters
	//			 "r" (VAL2));


	/*
	 * LAB 5
	 */
//	__asm("add %[out0], %[in0], %[in1]"
//			:[out0] "=r" (VAL3) 		//Output parameters
//			:[in0] "r" (VAL1),		//Input parameters
//			 [in1] "r" (VAL2)
//			: "r2");				//reserved registers, "r3" means don't use r3
									//The compiler will use the reserved registers if it's the only one available


	/*
	 * LAB6
	 */
	__asm("MRS %[out0], CONTROL"
			:[out0] "=r" (control_val)
			:);

	while(1)
	{
		if(IRQ_Flag)
		{
			IRQ_Flag = 0;
		}
		else
		{

		}
	}
}
