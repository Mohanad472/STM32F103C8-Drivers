#include "stm32f103x8.h"
#include "stm32f103c8_GPIO.h"
#include "stm32f103c8_EXTI.h"

void EXTI9_IRQ_fun(void)
{
	MCAL_GPIO_TogglePin(GPIOA, 0);
}

int main()
{
	//Enable clock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	GPIO_PinConfig_t GPIO_cfg;
	GPIO_cfg.GPIO_PinNumber = GPIO_PIN_0;
	GPIO_cfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_cfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &GPIO_cfg);

	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9;
	EXTI_CFG.Trigger_Case = EXTI_Trigger_Rising;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_Enable;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_IRQ_fun;
	MCAL_EXTI_GPIO_Init(&EXTI_CFG);

	while(1)
	{

	}
}