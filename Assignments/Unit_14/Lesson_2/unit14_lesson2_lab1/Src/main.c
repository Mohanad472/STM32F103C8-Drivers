#include "stm32f103x8.h"
#include "stm32f103c8_GPIO.h"
#include "stm32f103c8_EXTI.h"

uint8_t IRQ_Flag = 0;

void EXTI9_IRQ_fun(void)
{
	IRQ_Flag = 1;
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
