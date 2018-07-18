################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/PathTestSuite.cpp \
../tests/UnitTests.cpp 

OBJS += \
./tests/PathTestSuite.o \
./tests/UnitTests.o 

CPP_DEPS += \
./tests/PathTestSuite.d \
./tests/UnitTests.d 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/home/kordian/Desktop/Eclipse_Workspace/Genetic_TSP/include" -I"/home/kordian/Desktop/Eclipse_Workspace/Genetic_TSP/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


