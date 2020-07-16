################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/binary\ tree.c 

OBJS += \
./src/binary\ tree.o 

C_DEPS += \
./src/binary\ tree.d 


# Each subdirectory must supply rules for building sources it contributes
src/binary\ tree.o: ../src/binary\ tree.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/binary tree.d" -MT"src/binary\ tree.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


