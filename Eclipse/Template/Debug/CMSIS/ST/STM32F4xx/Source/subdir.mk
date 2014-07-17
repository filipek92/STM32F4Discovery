################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/ST/STM32F4xx/Source/system_stm32f4xx.c 

OBJS += \
./CMSIS/ST/STM32F4xx/Source/system_stm32f4xx.o 

C_DEPS += \
./CMSIS/ST/STM32F4xx/Source/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/ST/STM32F4xx/Source/%.o: ../CMSIS/ST/STM32F4xx/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Users\Filip\Eclipse\Template\Discovery" -I"C:\Users\Filip\Eclipse\Template\src" -I"C:\Users\Filip\Eclipse\Template\STM32F4xx_StdPeriph_Driver\inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


