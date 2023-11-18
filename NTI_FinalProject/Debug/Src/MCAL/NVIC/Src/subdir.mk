################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/NVIC/Src/NVIC.c 

OBJS += \
./Src/MCAL/NVIC/Src/NVIC.o 

C_DEPS += \
./Src/MCAL/NVIC/Src/NVIC.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/NVIC/Src/%.o Src/MCAL/NVIC/Src/%.su Src/MCAL/NVIC/Src/%.cyclo: ../Src/MCAL/NVIC/Src/%.c Src/MCAL/NVIC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F3 -DSTM32F303RETx -DNUCLEO_F303RE -c -I../Inc -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/HAL/Motor/inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/LIB" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/dio/inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/EXTI/Inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/NVIC/Inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/rcc/inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/SCB/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-NVIC-2f-Src

clean-Src-2f-MCAL-2f-NVIC-2f-Src:
	-$(RM) ./Src/MCAL/NVIC/Src/NVIC.cyclo ./Src/MCAL/NVIC/Src/NVIC.d ./Src/MCAL/NVIC/Src/NVIC.o ./Src/MCAL/NVIC/Src/NVIC.su

.PHONY: clean-Src-2f-MCAL-2f-NVIC-2f-Src

