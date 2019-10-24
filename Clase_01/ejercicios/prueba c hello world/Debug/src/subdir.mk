################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/prueba\ c\ hello\ world.c 

OBJS += \
./src/prueba\ c\ hello\ world.o 

C_DEPS += \
./src/prueba\ c\ hello\ world.d 


# Each subdirectory must supply rules for building sources it contributes
src/prueba\ c\ hello\ world.o: ../src/prueba\ c\ hello\ world.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/prueba c hello world.d" -MT"src/prueba\ c\ hello\ world.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


