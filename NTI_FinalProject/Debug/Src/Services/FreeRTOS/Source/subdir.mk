################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Services/FreeRTOS/Source/croutine.c \
../Src/Services/FreeRTOS/Source/event_groups.c \
../Src/Services/FreeRTOS/Source/list.c \
../Src/Services/FreeRTOS/Source/queue.c \
../Src/Services/FreeRTOS/Source/stream_buffer.c \
../Src/Services/FreeRTOS/Source/tasks.c \
../Src/Services/FreeRTOS/Source/timers.c 

OBJS += \
./Src/Services/FreeRTOS/Source/croutine.o \
./Src/Services/FreeRTOS/Source/event_groups.o \
./Src/Services/FreeRTOS/Source/list.o \
./Src/Services/FreeRTOS/Source/queue.o \
./Src/Services/FreeRTOS/Source/stream_buffer.o \
./Src/Services/FreeRTOS/Source/tasks.o \
./Src/Services/FreeRTOS/Source/timers.o 

C_DEPS += \
./Src/Services/FreeRTOS/Source/croutine.d \
./Src/Services/FreeRTOS/Source/event_groups.d \
./Src/Services/FreeRTOS/Source/list.d \
./Src/Services/FreeRTOS/Source/queue.d \
./Src/Services/FreeRTOS/Source/stream_buffer.d \
./Src/Services/FreeRTOS/Source/tasks.d \
./Src/Services/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Services/FreeRTOS/Source/%.o Src/Services/FreeRTOS/Source/%.su Src/Services/FreeRTOS/Source/%.cyclo: ../Src/Services/FreeRTOS/Source/%.c Src/Services/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F3 -DSTM32F303RETx -DNUCLEO_F303RE -c -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/MCAL/systick" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/MCAL/Tim6" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/HAL/UltraSonic/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/MCAL/ICU/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/MCAL/PWM/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/MCAL/ADC/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/HAL/BUTTON/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/HAL/Motor/inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/LIB" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/MCAL/dio/inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/MCAL/EXTI/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/MCAL/NVIC/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/MCAL/rcc/inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/MCAL/SCB/Inc" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/Services/FreeRTOS" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/Services/FreeRTOS/Source/include" -I"E:/0_0/Courses/Embedded system/NTI-4M/Days/NTI-231205-H/NTI-FinalProject/NTI_FinalProject/Src/Services/FreeRTOS/Source/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Services-2f-FreeRTOS-2f-Source

clean-Src-2f-Services-2f-FreeRTOS-2f-Source:
	-$(RM) ./Src/Services/FreeRTOS/Source/croutine.cyclo ./Src/Services/FreeRTOS/Source/croutine.d ./Src/Services/FreeRTOS/Source/croutine.o ./Src/Services/FreeRTOS/Source/croutine.su ./Src/Services/FreeRTOS/Source/event_groups.cyclo ./Src/Services/FreeRTOS/Source/event_groups.d ./Src/Services/FreeRTOS/Source/event_groups.o ./Src/Services/FreeRTOS/Source/event_groups.su ./Src/Services/FreeRTOS/Source/list.cyclo ./Src/Services/FreeRTOS/Source/list.d ./Src/Services/FreeRTOS/Source/list.o ./Src/Services/FreeRTOS/Source/list.su ./Src/Services/FreeRTOS/Source/queue.cyclo ./Src/Services/FreeRTOS/Source/queue.d ./Src/Services/FreeRTOS/Source/queue.o ./Src/Services/FreeRTOS/Source/queue.su ./Src/Services/FreeRTOS/Source/stream_buffer.cyclo ./Src/Services/FreeRTOS/Source/stream_buffer.d ./Src/Services/FreeRTOS/Source/stream_buffer.o ./Src/Services/FreeRTOS/Source/stream_buffer.su ./Src/Services/FreeRTOS/Source/tasks.cyclo ./Src/Services/FreeRTOS/Source/tasks.d ./Src/Services/FreeRTOS/Source/tasks.o ./Src/Services/FreeRTOS/Source/tasks.su ./Src/Services/FreeRTOS/Source/timers.cyclo ./Src/Services/FreeRTOS/Source/timers.d ./Src/Services/FreeRTOS/Source/timers.o ./Src/Services/FreeRTOS/Source/timers.su

.PHONY: clean-Src-2f-Services-2f-FreeRTOS-2f-Source

