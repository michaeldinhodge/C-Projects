################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BSTAndGameTest.cpp \
../src/BSTAndGamesFunctionsForUI.cpp \
../src/BSTAndGamesUITest.cpp \
../src/Employee.cpp \
../src/Game.cpp \
../src/UnitTseting.cpp 

OBJS += \
./src/BSTAndGameTest.o \
./src/BSTAndGamesFunctionsForUI.o \
./src/BSTAndGamesUITest.o \
./src/Employee.o \
./src/Game.o \
./src/UnitTseting.o 

CPP_DEPS += \
./src/BSTAndGameTest.d \
./src/BSTAndGamesFunctionsForUI.d \
./src/BSTAndGamesUITest.d \
./src/Employee.d \
./src/Game.d \
./src/UnitTseting.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


