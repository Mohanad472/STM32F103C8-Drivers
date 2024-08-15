#include "stm32f103x8.h"
#include "stm32f103c8_GPIO.h"
#include "stm32f103c8_EXTI.h"
#include "I2C_Slave_EEPROM.h"

int main()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	//Test case 1
	unsigned char ch1[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7};
	unsigned char ch2[7] = {0};

	eeprom_Init();
	eeprom_write_Nbytes(0xAF,ch1,7);
	eeprom_read_byte(0xAF, ch2, 7);

	//Test case 2
	ch1[0] = 0xA;
	ch1[1] = 0xB;
	ch1[2] = 0xC;
	ch1[3] = 0xD;

	eeprom_write_Nbytes(0xFFF,ch1,4);
	eeprom_read_byte(0xFFF, ch2, 4);

	while(1)
	{

	}
}

