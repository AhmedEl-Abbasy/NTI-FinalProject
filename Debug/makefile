################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/Services/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Src/Services/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Src/Services/FreeRTOS/Source/subdir.mk
-include Src/MCAL/systick/subdir.mk
-include Src/MCAL/rcc/src/subdir.mk
-include Src/MCAL/dio/src/subdir.mk
-include Src/MCAL/Tim6/subdir.mk
-include Src/MCAL/SCB/Src/subdir.mk
-include Src/MCAL/PWM/Src/subdir.mk
-include Src/MCAL/NVIC/Src/subdir.mk
-include Src/MCAL/ICU/Src/subdir.mk
-include Src/MCAL/EXTI/Src/subdir.mk
-include Src/MCAL/ADC/Src/subdir.mk
-include Src/HAL/UltraSonic/Src/subdir.mk
-include Src/HAL/Motor/src/subdir.mk
-include Src/HAL/BUTTON/Src/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
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
EXECUTABLES += \
NTI_FinalProject.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
NTI_FinalProject.list \

OBJCOPY_BIN += \
NTI_FinalProject.bin \


# All Target
all: NTI_FinalProject.elf secondary-outputs

# Tool invocations
NTI_FinalProject.elf: $(OBJS) $(USER_OBJS) E:\WS\NTI_4M\Final_Project\Project\STM32F303RETX_FLASH.ld
	arm-none-eabi-gcc -o "NTI_FinalProject.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\WS\NTI_4M\Final_Project\Project\STM32F303RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="NTI_FinalProject.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

NTI_FinalProject.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "NTI_FinalProject.list"
	@echo 'Finished building: $@'
	@echo ' '

NTI_FinalProject.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "NTI_FinalProject.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
