################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/ADC/Src/adc.c 

OBJS += \
./Src/MCAL/ADC/Src/adc.o 

C_DEPS += \
./Src/MCAL/ADC/Src/adc.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/ADC/Src/%.o Src/MCAL/ADC/Src/%.su Src/MCAL/ADC/Src/%.cyclo: ../Src/MCAL/ADC/Src/%.c Src/MCAL/ADC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F3 -DSTM32F303RETx -DNUCLEO_F303RE -c -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/MCAL/systick" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/HAL/UltraSonic/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/MCAL/ICU/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/MCAL/PWM/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/MCAL/ADC/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/HAL/BUTTON/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/HAL/Motor/inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/LIB" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/MCAL/dio/inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/MCAL/EXTI/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/MCAL/NVIC/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/MCAL/rcc/inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231130-H/final_project_/NTI-FinalProject/NTI_FinalProject/Src/MCAL/SCB/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-ADC-2f-Src

clean-Src-2f-MCAL-2f-ADC-2f-Src:
	-$(RM) ./Src/MCAL/ADC/Src/adc.cyclo ./Src/MCAL/ADC/Src/adc.d ./Src/MCAL/ADC/Src/adc.o ./Src/MCAL/ADC/Src/adc.su

.PHONY: clean-Src-2f-MCAL-2f-ADC-2f-Src

