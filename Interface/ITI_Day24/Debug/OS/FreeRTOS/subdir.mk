################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/FreeRTOS/croutine.c \
../OS/FreeRTOS/event_groups.c \
../OS/FreeRTOS/heap_1.c \
../OS/FreeRTOS/list.c \
../OS/FreeRTOS/port.c \
../OS/FreeRTOS/queue.c \
../OS/FreeRTOS/tasks.c \
../OS/FreeRTOS/timers.c 

OBJS += \
./OS/FreeRTOS/croutine.o \
./OS/FreeRTOS/event_groups.o \
./OS/FreeRTOS/heap_1.o \
./OS/FreeRTOS/list.o \
./OS/FreeRTOS/port.o \
./OS/FreeRTOS/queue.o \
./OS/FreeRTOS/tasks.o \
./OS/FreeRTOS/timers.o 

C_DEPS += \
./OS/FreeRTOS/croutine.d \
./OS/FreeRTOS/event_groups.d \
./OS/FreeRTOS/heap_1.d \
./OS/FreeRTOS/list.d \
./OS/FreeRTOS/port.d \
./OS/FreeRTOS/queue.d \
./OS/FreeRTOS/tasks.d \
./OS/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
OS/FreeRTOS/%.o: ../OS/FreeRTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Diploma\interface\ITI_Day24" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


