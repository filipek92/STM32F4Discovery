################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/discovery.c \
../src/main.c \
../src/stm32f4xx_it.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/discovery.o \
./src/main.o \
./src/stm32f4xx_it.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/discovery.d \
./src/main.d \
./src/stm32f4xx_it.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og  -g3 -ggdb -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\STM32F4xx\Include" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\STM32F4xx\Source" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\CMSIS\Include" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\Discovery" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\src" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\STM32F4xx_StdPeriph_Driver\inc" -std=gnu11 -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


