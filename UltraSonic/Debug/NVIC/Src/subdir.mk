################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NVIC/Src/NVIC.c 

OBJS += \
./NVIC/Src/NVIC.o 

C_DEPS += \
./NVIC/Src/NVIC.d 


# Each subdirectory must supply rules for building sources it contributes
NVIC/Src/NVIC.o: ../NVIC/Src/NVIC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F3 -DDEBUG -DSTM32F303RETx -DNUCLEO_F303RE -c -I../Inc -I"E:/WS/NTI_4M/Final_Project/UltraSonic/LIB" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/RCC" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/NVIC/Inc" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/systick" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/dio" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/ICU" -I"E:/WS/NTI_4M/Final_Project/UltraSonic/UltraSonic" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"NVIC/Src/NVIC.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

