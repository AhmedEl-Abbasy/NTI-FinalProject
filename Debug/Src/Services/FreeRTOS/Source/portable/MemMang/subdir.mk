################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Services/FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./Src/Services/FreeRTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./Src/Services/FreeRTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Services/FreeRTOS/Source/portable/MemMang/heap_4.o: ../Src/Services/FreeRTOS/Source/portable/MemMang/heap_4.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F3 -DSTM32F303RETx -DNUCLEO_F303RE -c -I"E:/WS/NTI_4M/Final_Project/Project/Startup" -I"E:/WS/NTI_4M/Final_Project/Project/Src/LIB" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/rcc/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/NVIC/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/systick" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/dio/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/ADC/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/EXTI/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/ICU/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/Tim6" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/PWM/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/SCB/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/BUTTON/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/Motor/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/UltraSonic/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/Services/FreeRTOS" -I"E:/WS/NTI_4M/Final_Project/Project/Src/Services/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"E:/WS/NTI_4M/Final_Project/Project/Src/Services/FreeRTOS/Source/portable/MemMang" -I"E:/WS/NTI_4M/Final_Project/Project/Src/Services/FreeRTOS/Source/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Services/FreeRTOS/Source/portable/MemMang/heap_4.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

