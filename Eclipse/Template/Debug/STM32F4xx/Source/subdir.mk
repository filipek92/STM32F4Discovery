################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../STM32F4xx/Source/startup_stm32f4xx.S 

OBJS += \
./STM32F4xx/Source/startup_stm32f4xx.o 

S_UPPER_DEPS += \
./STM32F4xx/Source/startup_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F4xx/Source/%.o: ../STM32F4xx/Source/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og  -g3 -ggdb -x assembler-with-cpp -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\CMSIS\Include" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\STM32F4xx\Include" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\STM32F4xx\Source" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\Discovery" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\src" -I"C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\Template\STM32F4xx_StdPeriph_Driver\inc" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


