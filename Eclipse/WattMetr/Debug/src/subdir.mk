################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/comunication.c \
../src/hd44780.c \
../src/main.c \
../src/measure.c \
../src/stm32f4xx_it.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/comunication.o \
./src/hd44780.o \
./src/main.o \
./src/measure.o \
./src/stm32f4xx_it.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/comunication.d \
./src/hd44780.d \
./src/main.d \
./src/measure.d \
./src/stm32f4xx_it.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og  -g3 -ggdb -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\WattMetr\STM32F4xx\Include" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\WattMetr\STM32F4xx\Source" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\WattMetr\CMSIS\Include" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\WattMetr\Discovery" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\WattMetr\src" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\WattMetr\STM32F4xx_StdPeriph_Driver\inc" -std=gnu11 -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


