#include "stm32f103x8.h"
#include "stm32f103c8_GPIO.h"
#include "stm32f103c8_EXTI.h"

extern int _estack;

#define TaskA_Stack_Size	100		//100 bytes
#define TaskB_Stack_Size	100		//100 bytes

#define OS_SET_PSP(add)				__asm volatile("mov r0, %0 \n\t msr PSP, r0" : : "r" (add))
#define OS_SWITCH_SP_TO_PSP			__asm volatile("mrs r0, CONTROL \n\t mov r1, #0x02 \n\t orr r0, r0, r1 \n\t msr CONTROL, r0")
#define OS_SWITCH_SP_TO_MSP			__asm volatile("mrs r0, CONTROL \n\t mov r1, #0x05 \n\t and r0, r0, r1 \n\t msr CONTROL, r0")
#define OS_Generate_Exception		__asm volatile("SVC #0x03")

//Main stack
unsigned int _S_MSP = &_estack;
unsigned int _E_MSP;

//Process stack task A
unsigned int _S_PSP_TA;
unsigned int _E_PSP_TA;

//Process stack task B
unsigned int _S_PSP_TB;
unsigned int _E_PSP_TB;

void HardFault_Handler()
{

}

void BusFault_Handler()
{

}

void UsageFault_Handler()
{

}

uint8_t TaskA_Flag, TaskB_Flag, IRQ_Flag = 0;

enum CPUAccessLevel
{
	privileged,
	unprivileged
};

void Switch_CPU_Access_Level(enum CPUAccessLevel level)
{
	switch(level)
	{
	case privileged:
		//clear bit 0 in CONTROL register
		__asm("mrs r3, CONTROL \n\t"
				"lsr r3, r3, #0x1 \n\t"
				"lsl r3, r3, #0x1 \n\t"
				"msr CONTROL, r3");
		break;
	case unprivileged:
		//set bit 0 in CONTROL register
		__asm("mrs r3, CONTROL \n\t"
				"orr r3, r3, #0x1 \n\t"
				"msr CONTROL, r3");
		break;
	}
}

void EXTI9_IRQ_fun(void)
{
	if(IRQ_Flag == 0)
	{
		TaskA_Flag = 1;
		IRQ_Flag = 1;
	}
	else if(IRQ_Flag == 1)
	{
		TaskB_Flag = 1;
		IRQ_Flag = 0;
	}
}

void SVC_Handler(void)
{
	Switch_CPU_Access_Level(privileged);
}

int TaskA(int a, int b, int c)
{
	return a + b + c;
}

int TaskB(int a, int b, int c, int d)
{
	return a + b + c;
}

void MainOs()
{
	//Main stack
	_E_MSP = _S_MSP - 512;

	//Task A
	_S_PSP_TA = _E_MSP - 8;
	_E_PSP_TA = _S_PSP_TA - 100;

	//Task B
	_S_PSP_TB = _E_PSP_TA - 8;
	_E_PSP_TB = _S_PSP_TB - 100;

	while(1)
	{
		__asm("nop");
		if(TaskA_Flag == 1)
		{
			//Set PSP register = _S_PSP_TA
			OS_SET_PSP(_S_PSP_TA);
			//SP --> PSP
			OS_SWITCH_SP_TO_PSP;
			//switch from privileged to unprivileged
			Switch_CPU_Access_Level(unprivileged);

			TaskA_Flag = TaskA(1,  2,  3);
			//switch from unprivileged to privileged
			OS_Generate_Exception;
			//SP --> MSP
			OS_SWITCH_SP_TO_MSP;
		}
		else if(TaskB_Flag == 1)
		{
			//Set PSP register = _S_PSP_TA
			OS_SET_PSP(_S_PSP_TB);
			//SP --> PSP
			OS_SWITCH_SP_TO_PSP;
			//switch from privileged to unprivileged
			Switch_CPU_Access_Level(unprivileged);

			TaskB_Flag = TaskB(1,  2,  3, 4);
			//switch from unprivileged to privileged
			OS_Generate_Exception;
			//SP --> MSP
			OS_SWITCH_SP_TO_MSP;
		}
	}
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

	MainOs();

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
