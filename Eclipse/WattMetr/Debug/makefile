################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include STM32F4xx_StdPeriph_Driver/src/subdir.mk
-include STM32F4xx/Source/subdir.mk
-include Discovery/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
WattMetr.hex \

SECONDARY_LIST += \
WattMetr.lst \

SECONDARY_SIZE += \
WattMetr.siz \


# All Target
all: WattMetr.elf secondary-outputs

# Tool invocations
WattMetr.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og  -g3 -ggdb -T "C:\Users\Filip\GIT\STM32F4Discovery\Eclipse\WattMetr\stm32_flash.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"WattMetr.map" -Xlinker --cref -o "WattMetr.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

WattMetr.hex: WattMetr.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "WattMetr.elf"  "WattMetr.hex"
	@echo 'Finished building: $@'
	@echo ' '

WattMetr.lst: WattMetr.elf
	@echo 'Invoking: Cross ARM GNU Create Listing'
	arm-none-eabi-objdump --source --all-headers --demangle --line-numbers --wide "WattMetr.elf" > "WattMetr.lst"
	@echo 'Finished building: $@'
	@echo ' '

WattMetr.siz: WattMetr.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "WattMetr.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(S_UPPER_DEPS) WattMetr.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
