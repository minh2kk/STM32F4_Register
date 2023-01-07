################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Src/gpio.c \
../Libraries/Src/rcc.c \
../Libraries/Src/systick.c 

OBJS += \
./Libraries/Src/gpio.o \
./Libraries/Src/rcc.o \
./Libraries/Src/systick.o 

C_DEPS += \
./Libraries/Src/gpio.d \
./Libraries/Src/rcc.d \
./Libraries/Src/systick.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Src/gpio.o: E:/Learn_Embedded/STM32F4_Register/STM32CUBEIDE/Libraries/Src/gpio.c Libraries/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VETx -c -I../Inc -I"E:/Learn_Embedded/STM32F4_Register/STM32CUBEIDE/Libraries/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Libraries/Src/rcc.o: E:/Learn_Embedded/STM32F4_Register/STM32CUBEIDE/Libraries/Src/rcc.c Libraries/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VETx -c -I../Inc -I"E:/Learn_Embedded/STM32F4_Register/STM32CUBEIDE/Libraries/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Libraries/Src/systick.o: E:/Learn_Embedded/STM32F4_Register/STM32CUBEIDE/Libraries/Src/systick.c Libraries/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VETx -c -I../Inc -I"E:/Learn_Embedded/STM32F4_Register/STM32CUBEIDE/Libraries/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libraries-2f-Src

clean-Libraries-2f-Src:
	-$(RM) ./Libraries/Src/gpio.d ./Libraries/Src/gpio.o ./Libraries/Src/gpio.su ./Libraries/Src/rcc.d ./Libraries/Src/rcc.o ./Libraries/Src/rcc.su ./Libraries/Src/systick.d ./Libraries/Src/systick.o ./Libraries/Src/systick.su

.PHONY: clean-Libraries-2f-Src

