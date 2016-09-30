################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Camera.cpp \
../DOFCamera.cpp \
../Material.cpp \
../Matrix.cpp \
../Matte.cpp \
../Normal.cpp \
../Object.cpp \
../Plane.cpp \
../Point.cpp \
../RGBColor.cpp \
../Ray.cpp \
../Specular.cpp \
../Sphere.cpp \
../Triangle.cpp \
../Vector3D.cpp \
../World.cpp \
../hitResult.cpp \
../light.cpp \
../main.cpp 

OBJS += \
./Camera.o \
./DOFCamera.o \
./Material.o \
./Matrix.o \
./Matte.o \
./Normal.o \
./Object.o \
./Plane.o \
./Point.o \
./RGBColor.o \
./Ray.o \
./Specular.o \
./Sphere.o \
./Triangle.o \
./Vector3D.o \
./World.o \
./hitResult.o \
./light.o \
./main.o 

CPP_DEPS += \
./Camera.d \
./DOFCamera.d \
./Material.d \
./Matrix.d \
./Matte.d \
./Normal.d \
./Object.d \
./Plane.d \
./Point.d \
./RGBColor.d \
./Ray.d \
./Specular.d \
./Sphere.d \
./Triangle.d \
./Vector3D.d \
./World.d \
./hitResult.d \
./light.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


