################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../dio/dio.c 

OBJS += \
./dio/dio.o 

C_DEPS += \
./dio/dio.d 


# Each subdirectory must supply rules for building sources it contributes
dio/dio.o: ../dio/dio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F3 -DDEBUG -DSTM32F303RETx -DNUCLEO_F303RE -c -I../Inc -I"E:/WS/NTI_4M/Final_Project/UltraSonic/LIB" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/RCC" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/NVIC/Inc" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/systick" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/dio" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/ICU" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/UltraSonic" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"dio/dio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

