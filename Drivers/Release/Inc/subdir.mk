################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/stm32f103c8_EXTI.c \
../Inc/stm32f103c8_GPIO.c \
../Inc/stm32f103c8_I2C.c 

OBJS += \
./Inc/stm32f103c8_EXTI.o \
./Inc/stm32f103c8_GPIO.o \
./Inc/stm32f103c8_I2C.o 

C_DEPS += \
./Inc/stm32f103c8_EXTI.d \
./Inc/stm32f103c8_GPIO.d \
./Inc/stm32f103c8_I2C.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su Inc/%.cyclo: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/stm32f103c8_EXTI.cyclo ./Inc/stm32f103c8_EXTI.d ./Inc/stm32f103c8_EXTI.o ./Inc/stm32f103c8_EXTI.su ./Inc/stm32f103c8_GPIO.cyclo ./Inc/stm32f103c8_GPIO.d ./Inc/stm32f103c8_GPIO.o ./Inc/stm32f103c8_GPIO.su ./Inc/stm32f103c8_I2C.cyclo ./Inc/stm32f103c8_I2C.d ./Inc/stm32f103c8_I2C.o ./Inc/stm32f103c8_I2C.su

.PHONY: clean-Inc

