################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/30010_io.c \
../Src/ADCread.c \
../Src/ansi.c \
../Src/ex2.c \
../Src/main.c \
../Src/sprite.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f30x.c 

OBJS += \
./Src/30010_io.o \
./Src/ADCread.o \
./Src/ansi.o \
./Src/ex2.o \
./Src/main.o \
./Src/sprite.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f30x.o 

C_DEPS += \
./Src/30010_io.d \
./Src/ADCread.d \
./Src/ansi.d \
./Src/ex2.d \
./Src/main.d \
./Src/sprite.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f30x.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DNUCLEO_F302R8 -DDEBUG -DUSE_STDPERIPH_DRIVER=1 -c -I"C:/Users/simon/OneDrive/Dokumenter/Skole/DTU/Prog Projekt/Projektet_Rapport/ProgrameringsProjekt/ProgrameringsProjekt/ArcadeGame/SPL/inc" -I"C:/Users/simon/OneDrive/Dokumenter/Skole/DTU/Prog Projekt/Projektet_Rapport/ProgrameringsProjekt/ProgrameringsProjekt/ArcadeGame/Inc" -I"C:/Users/simon/OneDrive/Dokumenter/Skole/DTU/Prog Projekt/Projektet_Rapport/ProgrameringsProjekt/ProgrameringsProjekt/ArcadeGame/cmsis" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/30010_io.d ./Src/30010_io.o ./Src/30010_io.su ./Src/ADCread.d ./Src/ADCread.o ./Src/ADCread.su ./Src/ansi.d ./Src/ansi.o ./Src/ansi.su ./Src/ex2.d ./Src/ex2.o ./Src/ex2.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/sprite.d ./Src/sprite.o ./Src/sprite.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32f30x.d ./Src/system_stm32f30x.o ./Src/system_stm32f30x.su

.PHONY: clean-Src

