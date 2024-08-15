/*
 * I2C_Slave_EEPROM.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Mohanad
 */

#include "I2C_Slave_EEPROM.h"

void eeprom_Init(void)
{
	I2C_InitTypeDef I2C1CFG;
	I2C1CFG.I2C_ACK_Control = I2C_Ack_Enable;
	I2C1CFG.I2C_ClockSpeed = 100000;
	I2C1CFG.StretchMode = I2C_StretchMode_Enable;

	MCAL_I2C_GPIO_Set_Pins(I2C1);
	MCAL_I2C_Init(I2C1, &I2C1CFG);
}

unsigned char eeprom_write_Nbytes(unsigned int Memory_address, unsigned char* bytes, uint8_t Data_Length)
{
	int i = 0;
	uint8_t buffer[256];
	buffer[0] = (uint8_t)(Memory_address>>8);
	buffer[1] = (uint8_t)Memory_address;
	for(i = 2; i < (Data_Length+2); i++)
	{
		buffer[i] = bytes[i-2];
	}
	MCAL_I2C_MASTER_TX(I2C1, EEPROM_Slave_address, buffer, Data_Length+2, With_Stop, Start);
	return 0;
}

unsigned char eeprom_read_byte(unsigned int Memory_address, uint8_t *dataOut, uint8_t dataLen)
{
	uint8_t buffer[2];
	buffer[0] = (uint8_t)(Memory_address>>8);
	buffer[1] = (uint8_t)Memory_address;

	MCAL_I2C_MASTER_TX(I2C1, EEPROM_Slave_address, buffer, 2, Without_Stop, Start);
	MCAL_I2C_MASTER_RX(I2C1, EEPROM_Slave_address, dataOut, dataLen, With_Stop, repeated_start);
	return 0;
}
