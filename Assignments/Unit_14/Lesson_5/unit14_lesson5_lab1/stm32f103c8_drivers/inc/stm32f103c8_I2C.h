/*
 * I2C_Interface.h
 *
 *  Created on: Dec 10, 2023
 *      Author: Mohanad
 */

#ifndef INC_STM32F103C8_I2C_H_
#define INC_STM32F103C8_I2C_H_

#include "stm32f103x8.h"

#define I2C_EVENT_MASTER_BYTE_TRANSMITTING		((uint32_t)0x00070080) /* TRA, BUSY, MSL, TXE flags */

typedef enum
{
	I2C_EV_STOP,
	I2C_ERROR_AF,
	I2C_EV_ADDR_Matched,
	I2C_EV_DATA_REQ,			//The APP layer should send the data (I2C_Slave_Send_Data) in this state
	I2C_EV_DATA_RCV				//The APP layer should read the data (I2C_Slave_Receive_Data) in this state
}Slave_State;

struct S_I2C_Slave_Device_Address
{
	uint16_t Enable_Dual_ADD;	//1-Enable	0-Disable
	uint16_t Primary_slave_address;
	uint16_t Secondary_slave_address;
	uint16_t I2C_Addressing_Slave_mode; //@I2C_Addressing_Slave_
};

typedef struct
{
	uint32_t I2C_ClockSpeed;							/* Specifies the clock frequency
														This parameter must be set to @I2C_SCLK_ */

	uint16_t StretchMode;								//@I2C_StretchMode_

	uint16_t I2C_Mode;									/* Specifies the I2C mode.
														This parameter can be a value of @I2C_mode */

	struct S_I2C_Slave_Device_Address	I2C_Slave_Device_Address;

	uint16_t I2C_ACK_Control;							/* Enables or disables the acknowledgement
														This parameter can be a value of @I2C_Ack */

	uint16_t General_Call_Address_Detection;			//@I2C_ENGC

	void(* P_Slave_Event_CallBack)(Slave_State state);  //Set the C Function() which will be called

}I2C_InitTypeDef;

typedef enum
{
	With_Stop,
	Without_Stop
}Stop_Condition;

typedef enum
{
	Start,
	repeated_start
}Repeated_Start;

typedef enum {DISABLE = 0, ENABLE = 1} FunctionalState;
typedef enum {RESET = 0, SET = 1} FlagStatus;
typedef enum {I2C_Direction_Transmitter = 0, I2C_Direction_Receiver = 1} I2C_Direction;
typedef enum
{
	I2C_FLAG_BUSY = 0,
	EV5,
	EV6,
	EV7,
	EV8,
	EV8_1,
	MASTER_BYTE_TRANSMITTING = ((uint32_t)0x00070080),  /* TRA, BUSY, MSL, TXE flags */
}Status;

// * ====================================================================
//Reference Macros
// * ====================================================================

//@I2C_SCLK_
//>> Standard Speed (up to 100 khz)
//>> Fast Speed (up to 400 khz)
//>> to configure clock before enabling the peripheral
//---I2C_CR2.FREQ[5:0]: Peripheral clock frequency
//>> Configure the clock control registers
//-T_high = CCR * TPCLK1
//-SM or FM (Standard mode or Fast mode)
//>> Configure the rise time registers I2C_TRISE

#define I2C_SCLK_SM_50k				(500000U)
#define I2C_SCLK_SM_100k			(100000U)
#define I2C_SCLK_FM_200k			(200000U)	// Fast Mode is not supported yet
#define I2C_SCLK_FM_400k			(400000U)	// Fast Mode is not supported yet
// we can put many values



//@I2C_StretchMode_
//I2C_CR1
//Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
//0 : Clock stretching enabled
//1 : Clock stretching disabled
#define I2C_StretchMode_Enable		(0x00000000U)
#define I2C_StretchMode_Disable		I2C_CR1_NOSTRETCH



//@I2C_mode
//I2C_CR1
//Bit 1 SMBUS: SMBus mode
//0 : I2C mode
//1 : SMBus mode
#define I2C_mode_I2C				0
#define I2C_mode_SMBus				I2C_CR1_SMBUS



//@I2C_Addressing_Slave_
//I2C_OAR1.ADDMODE
//Bit 15 ADDMODE Addressing mode (slave mode)
//0 : 7-bit slave address (10-bit address not acknowledged
//1 : 10-bit slave address (7-bit address not acknowledged)
#define I2C_Addressing_Slave_mode_7Bit			0x00000000U
#define I2C_Addressing_Slave_mode_10Bit			(uint16_t)(1<<15)



//@I2C_Ack
//I2C_CR1
//0 : No acknowledge returned
//1 : Acknowledge returned after a byte is received (matched address or data)
#define I2C_Ack_Enable			(I2C_CR1_ACK)
#define I2C_Ack_Disable			((uint16_t)0x0000)



//@ref I2C_ENGC
//I2C_CR1
//Bit 6 ENGC: General call enable
//0: General call disabled. Address 00h is NACKed.
//1: General call enabled. Address 00h is ACKed
#define I2C_ENGC_Enable                   I2C_CR1_ENGC
#define I2C_ENGC_Disable                  0x00000000U

void MCAL_I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct);
void MCAL_I2C_DInit(I2C_TypeDef* I2Cx);
void MCAL_I2C_GPIO_Set_Pins(I2C_TypeDef* I2Cx);

//Master Polling Mechanism
void MCAL_I2C_MASTER_TX(I2C_TypeDef* I2Cx, uint16_t devAddr, uint8_t *dataOut, uint32_t dataLen, Stop_Condition Stop, Repeated_Start start);
void MCAL_I2C_MASTER_RX(I2C_TypeDef* I2Cx, uint16_t devAddr, uint8_t *dataOut, uint32_t dataLen, Stop_Condition Stop, Repeated_Start start);

//Slave interrupt mechanism

//Generic APIs
void I2C_GenerateSTART(I2C_TypeDef *I2Cx, FunctionalState NewState, Repeated_Start start);
FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, Status flag);
void I2C_SendAddress(I2C_TypeDef* I2Cx, uint16_t Address, I2C_Direction Direction);
void I2C_GenerateSTOP(I2C_TypeDef *I2Cx, FunctionalState NewState);
void I2C_ACKnowledgeConfig(I2C_TypeDef* I2Cx, FunctionalState NewState);
void delay_ms(uint32_t milliseconds);
void MCAL_I2C_RESET();

#endif /* INC_STM32F103C8_I2C_H_ */
