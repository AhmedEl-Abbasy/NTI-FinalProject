################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F3 -DSTM32F303RETx -DNUCLEO_F303RE -c -I"E:/WS/NTI_4M/Final_Project/Project/Startup" -I"E:/WS/NTI_4M/Final_Project/Project/Src/LIB" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/rcc/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/NVIC/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/systick" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/dio/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/ADC/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/EXTI/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/ICU/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/PWM/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/SCB/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/BUTTON/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/Motor/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/UltraSonic/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F3 -DSTM32F303RETx -DNUCLEO_F303RE -c -I"E:/WS/NTI_4M/Final_Project/Project/Startup" -I"E:/WS/NTI_4M/Final_Project/Project/Src/LIB" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/rcc/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/NVIC/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/systick" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/dio/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/ADC/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/EXTI/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/ICU/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/PWM/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/SCB/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/BUTTON/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/Motor/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/UltraSonic/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F3 -DSTM32F303RETx -DNUCLEO_F303RE -c -I"E:/WS/NTI_4M/Final_Project/Project/Startup" -I"E:/WS/NTI_4M/Final_Project/Project/Src/LIB" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/rcc/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/NVIC/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/systick" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/dio/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/ADC/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/EXTI/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/ICU/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/PWM/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/MCAL/SCB/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/BUTTON/Inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/Motor/inc" -I"E:/WS/NTI_4M/Final_Project/Project/Src/HAL/UltraSonic/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

