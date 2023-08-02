//Startup.c
//Eng.Mohanad

#include <stdint.h>

void Reset_Handler();
void Default_Handler()
{
	Reset_Handler();
}
void NMI_Handler() __attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler() __attribute__((weak, alias("Default_Handler")));
void MM_fault_Handler() __attribute__((weak, alias("Default_Handler")));
void Bus_Handler() __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler() __attribute__((weak, alias("Default_Handler")));

static unsigned int Stack_top[256];

void (*vectors[])() __attribute__((section(".vectors"))) = {			// Stored in .data
	(void (*)()) ((unsigned long *)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler,
	&MM_fault_Handler,
	&Bus_Handler,
	&Usage_Fault_Handler,
};

extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler()
{
	// copy data from flash to ram
	unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;	// to calculate size in bytes
	unsigned char *P_src = (unsigned char*)&_E_text;
	unsigned char *P_dst = (unsigned char*)&_S_DATA;
	int i;
	for(i = 0; i < DATA_size; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char *)P_src++);	// move data byte by byte
	} 

	// create .bss section in ram
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss;
	for(i = 0; i < bss_size; i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;	
	}

	main();
};