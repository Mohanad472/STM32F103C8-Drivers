################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c8_drivers/stm32f103c8_EXTI.c \
../stm32f103c8_drivers/stm32f103c8_GPIO.c \
../stm32f103c8_drivers/stm32f103c8_I2C.c 

OBJS += \
./stm32f103c8_drivers/stm32f103c8_EXTI.o \
./stm32f103c8_drivers/stm32f103c8_GPIO.o \
./stm32f103c8_drivers/stm32f103c8_I2C.o 

C_DEPS += \
./stm32f103c8_drivers/stm32f103c8_EXTI.d \
./stm32f103c8_drivers/stm32f103c8_GPIO.d \
./stm32f103c8_drivers/stm32f103c8_I2C.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c8_drivers/%.o stm32f103c8_drivers/%.su stm32f103c8_drivers/%.cyclo: ../stm32f103c8_drivers/%.c stm32f103c8_drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ks_diploma/Units/Unit 14/Lesson 5/unit14_lesson5_lab1/stm32f103c8_drivers/inc" -I"D:/ks_diploma/Units/Unit 14/Lesson 5/unit14_lesson5_lab1/HAL/includes" -I"D:/ks_diploma/Units/Unit 14/Lesson 5/unit14_lesson5_lab1/stm32f103c8_drivers/inc" -I"D:/ks_diploma/Units/Unit 14/Lesson 5/unit14_lesson5_lab1/stm32f103c8_drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-stm32f103c8_drivers

clean-stm32f103c8_drivers:
	-$(RM) ./stm32f103c8_drivers/stm32f103c8_EXTI.cyclo ./stm32f103c8_drivers/stm32f103c8_EXTI.d ./stm32f103c8_drivers/stm32f103c8_EXTI.o ./stm32f103c8_drivers/stm32f103c8_EXTI.su ./stm32f103c8_drivers/stm32f103c8_GPIO.cyclo ./stm32f103c8_drivers/stm32f103c8_GPIO.d ./stm32f103c8_drivers/stm32f103c8_GPIO.o ./stm32f103c8_drivers/stm32f103c8_GPIO.su ./stm32f103c8_drivers/stm32f103c8_I2C.cyclo ./stm32f103c8_drivers/stm32f103c8_I2C.d ./stm32f103c8_drivers/stm32f103c8_I2C.o ./stm32f103c8_drivers/stm32f103c8_I2C.su

.PHONY: clean-stm32f103c8_drivers

