################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Discovery/stm32f4_discovery.c 

OBJS += \
./Discovery/stm32f4_discovery.o 

C_DEPS += \
./Discovery/stm32f4_discovery.d 


# Each subdirectory must supply rules for building sources it contributes
Discovery/%.o: ../Discovery/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og  -g3 -ggdb -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"C:\Users\Filip\Eclipse\Template\STM32F4xx\Include" -I"C:\Users\Filip\Eclipse\Template\STM32F4xx\Source" -I"C:\Users\Filip\Eclipse\Template\CMSIS\Include" -I"C:\Users\Filip\Eclipse\Template\Discovery" -I"C:\Users\Filip\Eclipse\Template\src" -I"C:\Users\Filip\Eclipse\Template\STM32F4xx_StdPeriph_Driver\inc" -std=gnu11 -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


