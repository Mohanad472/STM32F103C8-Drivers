################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/stm32f103c8_GPIO.c 

OBJS += \
./Inc/stm32f103c8_GPIO.o 

C_DEPS += \
./Inc/stm32f103c8_GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su Inc/%.cyclo: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/ks_diploma/Units/Unit 7/Lesson 3/Drivers/stm32f103c8_drivers" -I"D:/ks_diploma/Units/Unit 7/Lesson 3/Drivers/HAL/includes" -I"D:/ks_diploma/Units/Unit 7/Lesson 3/Drivers/stm32f103c8_drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/stm32f103c8_GPIO.cyclo ./Inc/stm32f103c8_GPIO.d ./Inc/stm32f103c8_GPIO.o ./Inc/stm32f103c8_GPIO.su

.PHONY: clean-Inc

