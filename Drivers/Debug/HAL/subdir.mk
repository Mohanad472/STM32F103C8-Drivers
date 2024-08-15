################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/I2C_Slave_EEPROM.c 

OBJS += \
./HAL/I2C_Slave_EEPROM.o 

C_DEPS += \
./HAL/I2C_Slave_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o HAL/%.su HAL/%.cyclo: ../HAL/%.c HAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/ks_diploma/Units/Unit 7/Lesson 3/Drivers/HAL/includes" -I"D:/ks_diploma/Units/Unit 7/Lesson 3/Drivers/HAL/includes" -I"D:/ks_diploma/Units/Unit 7/Lesson 3/Drivers/Src" -I"D:/ks_diploma/Units/Unit 7/Lesson 3/Drivers/stm32f103c8_drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL

clean-HAL:
	-$(RM) ./HAL/I2C_Slave_EEPROM.cyclo ./HAL/I2C_Slave_EEPROM.d ./HAL/I2C_Slave_EEPROM.o ./HAL/I2C_Slave_EEPROM.su

.PHONY: clean-HAL

