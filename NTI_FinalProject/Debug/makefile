################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/MCAL/systick/subdir.mk
-include Src/MCAL/rcc/src/subdir.mk
-include Src/MCAL/dio/src/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := NTI_FinalProject
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
NTI_FinalProject.elf \

MAP_FILES += \
NTI_FinalProject.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
NTI_FinalProject.list \


# All Target
all: main-build

# Main-build Target
main-build: NTI_FinalProject.elf secondary-outputs

# Tool invocations
NTI_FinalProject.elf NTI_FinalProject.map: $(OBJS) $(USER_OBJS) E:\0_0\Courses\Embedded\ system\NTI-4M\Days\NTI-231130-H\final_project_\NTI-FinalProject\NTI_FinalProject\STM32F303RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "NTI_FinalProject.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\0_0\Courses\Embedded system\NTI-4M\Days\NTI-231130-H\final_project_\NTI-FinalProject\NTI_FinalProject\STM32F303RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="NTI_FinalProject.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

NTI_FinalProject.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "NTI_FinalProject.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) NTI_FinalProject.elf NTI_FinalProject.list NTI_FinalProject.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
