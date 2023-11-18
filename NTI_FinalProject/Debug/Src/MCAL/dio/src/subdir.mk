################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/dio/src/dio.c 

OBJS += \
./Src/MCAL/dio/src/dio.o 

C_DEPS += \
./Src/MCAL/dio/src/dio.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/dio/src/%.o Src/MCAL/dio/src/%.su Src/MCAL/dio/src/%.cyclo: ../Src/MCAL/dio/src/%.c Src/MCAL/dio/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F3 -DSTM32F303RETx -DNUCLEO_F303RE -c -I../Inc -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/HAL/Motor/inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/LIB" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/dio/inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/EXTI/Inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/NVIC/Inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/rcc/inc" -I"C:/Users/Abelrahman/Desktop/NTI/ARM/NTI_FinalProject/Src/MCAL/SCB/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-dio-2f-src

clean-Src-2f-MCAL-2f-dio-2f-src:
	-$(RM) ./Src/MCAL/dio/src/dio.cyclo ./Src/MCAL/dio/src/dio.d ./Src/MCAL/dio/src/dio.o ./Src/MCAL/dio/src/dio.su

.PHONY: clean-Src-2f-MCAL-2f-dio-2f-src

