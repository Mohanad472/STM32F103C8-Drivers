#include "stm32f103x8.h"
#include "stm32f103c8_GPIO.h"

void clock_init()
{
	//Enable clock GPIOA
	RCC_GPIOA_CLK_EN();
	//Enable clock GPIOB
	RCC_GPIOB_CLK_EN();
}

void GPIO_init()
{
	GPIO_PinConfig_t PinCfg;
	//PA1 input HighZ Floating input (reset state)
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	//PB1 output push-pull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	//PA12 input HighZ Floating input (reset state)
	PinCfg.GPIO_PinNumber = GPIO_PIN_12;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	//PB12 output push-pull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_12;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);
}

void wait_ms(uint32_t time)
{
	uint32_t i,j;
	for(i = 0; i < time; i++)
		for(j = 0; j < 255; j++);
}

int main()
{
	clock_init();
	GPIO_init();

	while(1)
	{
		//PA1 connected to external PUR
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0);	//Single pressing
		}
		//PA12 connected to external PUR
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12) == 0)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);	//Multi pressing
		}
		wait_ms(100);
	}
}
