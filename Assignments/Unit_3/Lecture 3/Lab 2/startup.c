//Eng.Mohanad
#include <stdint.h>

void Reset_Handler();
void Default_Handler()
{
	Reset_Handler();
}
void NMI_Handler()  __attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler()  __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler()  __attribute__((weak, alias("Default_Handler")));
void Bus_Handler()  __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler()  __attribute__((weak, alias("Default_Handler")));

extern uint32_t _stack_top;

uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t)	&_stack_top,			
	(uint32_t)	&Reset_Handler,				
	(uint32_t)	&NMI_Handler,		
	(uint32_t)	&H_Fault_Handler,		
	(uint32_t)	&MM_Fault_Handler,		
	(uint32_t)	&Bus_Handler,		
	(uint32_t)	&Usage_Fault_Handler,
};

extern uint32_t _E_text;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_bss;
extern uint32_t _E_bss;

void Reset_Handler()
{
	// Copy .data from flash to sram
	uint32_t DATA_size = (uint8_t *)&_E_DATA - (uint8_t *)&_S_DATA;
	uint8_t *P_src = (uint8_t *)&_E_text;
	uint8_t *P_dst = (uint8_t *)&_S_DATA;
	int i;
	for(i = 0; i < DATA_size; i++)
	{
		*((uint8_t *)P_dst++) = *((uint8_t *)P_src++);
	}

	// Create .bss in sram
	uint32_t bss_size = (uint8_t *)&_E_bss - (uint8_t *)&(_S_bss);
	P_dst = (uint8_t *)&_S_bss;
	for(i = 0; i < DATA_size; i++)
	{
		*((uint8_t *)P_dst++) = (uint8_t)0;
	}
	main();
}