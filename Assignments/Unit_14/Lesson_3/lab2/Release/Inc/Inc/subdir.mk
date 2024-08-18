################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/Inc/stm32f103c8_EXTI.c \
../Inc/Inc/stm32f103c8_GPIO.c \
../Inc/Inc/stm32f103c8_I2C.c 

OBJS += \
./Inc/Inc/stm32f103c8_EXTI.o \
./Inc/Inc/stm32f103c8_GPIO.o \
./Inc/Inc/stm32f103c8_I2C.o 

C_DEPS += \
./Inc/Inc/stm32f103c8_EXTI.d \
./Inc/Inc/stm32f103c8_GPIO.d \
./Inc/Inc/stm32f103c8_I2C.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/Inc/%.o Inc/Inc/%.su Inc/Inc/%.cyclo: ../Inc/Inc/%.c Inc/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-Inc

clean-Inc-2f-Inc:
	-$(RM) ./Inc/Inc/stm32f103c8_EXTI.cyclo ./Inc/Inc/stm32f103c8_EXTI.d ./Inc/Inc/stm32f103c8_EXTI.o ./Inc/Inc/stm32f103c8_EXTI.su ./Inc/Inc/stm32f103c8_GPIO.cyclo ./Inc/Inc/stm32f103c8_GPIO.d ./Inc/Inc/stm32f103c8_GPIO.o ./Inc/Inc/stm32f103c8_GPIO.su ./Inc/Inc/stm32f103c8_I2C.cyclo ./Inc/Inc/stm32f103c8_I2C.d ./Inc/Inc/stm32f103c8_I2C.o ./Inc/Inc/stm32f103c8_I2C.su

.PHONY: clean-Inc-2f-Inc

