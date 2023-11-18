################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/Motor/src/motor.c 

OBJS += \
./Src/HAL/Motor/src/motor.o 

C_DEPS += \
./Src/HAL/Motor/src/motor.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/Motor/src/%.o Src/HAL/Motor/src/%.su Src/HAL/Motor/src/%.cyclo: ../Src/HAL/Motor/src/%.c Src/HAL/Motor/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F3 -DSTM32F303RETx -DNUCLEO_F303RE -c -I../Inc -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/HAL/Motor/inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/LIB" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/dio/inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/EXTI/Inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/NVIC/Inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/rcc/inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/SCB/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-Motor-2f-src

clean-Src-2f-HAL-2f-Motor-2f-src:
	-$(RM) ./Src/HAL/Motor/src/motor.cyclo ./Src/HAL/Motor/src/motor.d ./Src/HAL/Motor/src/motor.o ./Src/HAL/Motor/src/motor.su

.PHONY: clean-Src-2f-HAL-2f-Motor-2f-src

