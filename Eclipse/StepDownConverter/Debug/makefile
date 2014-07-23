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
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
StepDownConverter.hex \

SECONDARY_LIST += \
StepDownConverter.lst \

SECONDARY_SIZE += \
StepDownConverter.siz \


# All Target
all: StepDownConverter.elf secondary-outputs

# Tool invocations
StepDownConverter.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og  -g3 -ggdb -T "C:\Users\Filip\Git\STM32F4Discovery\Eclipse\StepDownConverter\stm32_flash.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"StepDownConverter.map" -Xlinker --cref -o "StepDownConverter.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

StepDownConverter.hex: StepDownConverter.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "StepDownConverter.elf"  "StepDownConverter.hex"
	@echo 'Finished building: $@'
	@echo ' '

StepDownConverter.lst: StepDownConverter.elf
	@echo 'Invoking: Cross ARM GNU Create Listing'
	arm-none-eabi-objdump --source --all-headers --demangle --line-numbers --wide "StepDownConverter.elf" > "StepDownConverter.lst"
	@echo 'Finished building: $@'
	@echo ' '

StepDownConverter.siz: StepDownConverter.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "StepDownConverter.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) StepDownConverter.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
