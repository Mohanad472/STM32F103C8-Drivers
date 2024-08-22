/*
 * I2C_Slave_EEPROM.h
 *
 *  Created on: Dec 10, 2023
 *      Author: Mohanad
 */

#ifndef HAL_I2C_EEPROM_I2C_SLAVE_EEPROM_H_
#define HAL_I2C_EEPROM_I2C_SLAVE_EEPROM_H_

#include "stm32f103c8_I2C.h"

#define EEPROM_Slave_address		0x2A
//#define EEPROM_Slave_address		0x48

void eeprom_Init(void);
unsigned char eeprom_write_Nbytes(unsigned int Memory_address, unsigned char* bytes, uint8_t Data_Length);
unsigned char eeprom_read_byte(unsigned int address, uint8_t *dataOut, uint8_t dataLen);

#endif /* HAL_I2C_EEPROM_I2C_SLAVE_EEPROM_H_ */
