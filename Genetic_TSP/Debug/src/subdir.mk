################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Genetic_TSP.cpp \
../src/Path.cpp \
../src/PointInitializer.cpp \
../src/Population.cpp \
../src/dziala.cpp 

OBJS += \
./src/Genetic_TSP.o \
./src/Path.o \
./src/PointInitializer.o \
./src/Population.o \
./src/dziala.o 

CPP_DEPS += \
./src/Genetic_TSP.d \
./src/Path.d \
./src/PointInitializer.d \
./src/Population.d \
./src/dziala.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/home/kordian/Desktop/Eclipse_Workspace/Genetic_TSP/include" -O3 -g3 -pedantic -pedantic-errors -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


