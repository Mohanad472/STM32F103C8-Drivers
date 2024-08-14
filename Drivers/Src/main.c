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



























//void clock_init()
//{
//	//Enable clock GPIOA
//	RCC_GPIOA_CLK_EN();
//	//Enable clock GPIOB
//	RCC_GPIOB_CLK_EN();
//}
//
//void GPIO_init()
//{
//	GPIO_PinConfig_t PinCfg;
//	//PA1 input HighZ Floating input (reset state)
//	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
//	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(GPIOA, &PinCfg);
//
//	//PB1 output push-pull mode
//	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
//	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
//	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
//	MCAL_GPIO_Init(GPIOB, &PinCfg);
//
//	//PA12 input HighZ Floating input (reset state)
//	PinCfg.GPIO_PinNumber = GPIO_PIN_12;
//	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
//	MCAL_GPIO_Init(GPIOA, &PinCfg);
//
//	//PB12 output push-pull mode
//	PinCfg.GPIO_PinNumber = GPIO_PIN_12;
//	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
//	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
//	MCAL_GPIO_Init(GPIOB, &PinCfg);
//}
//
//void wait_ms(uint32_t time)
//{
//	uint32_t i,j;
//	for(i = 0; i < time; i++)
//		for(j = 0; j < 255; j++);
//}
//
//int main()
//{
//	clock_init();
//	GPIO_init();
//
//	while(1)
//	{
//		//PA1 connected to external PUR
//		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
//		{
//			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
//			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0);	//Single pressing
//		}
//		//PA12 connected to external PUR
//		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12) == 0)
//		{
//			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);	//Multi pressing
//		}
//		wait_ms(100);
//	}
//}
