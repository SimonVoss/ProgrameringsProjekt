################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/30010_io.c \
../Src/ADCread.c \
../Src/PCBJoystick.c \
../Src/ansi.c \
../Src/bullets.c \
../Src/buzz.c \
../Src/config.c \
../Src/enemy.c \
../Src/gameBoard.c \
../Src/include.c \
../Src/lcd.c \
../Src/letters.c \
../Src/main.c \
../Src/math.c \
../Src/player.c \
../Src/sets.c \
../Src/sinlut.c \
../Src/sprite.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f30x.c \
../Src/timer.c 

OBJS += \
./Src/30010_io.o \
./Src/ADCread.o \
./Src/PCBJoystick.o \
./Src/ansi.o \
./Src/bullets.o \
./Src/buzz.o \
./Src/config.o \
./Src/enemy.o \
./Src/gameBoard.o \
./Src/include.o \
./Src/lcd.o \
./Src/letters.o \
./Src/main.o \
./Src/math.o \
./Src/player.o \
./Src/sets.o \
./Src/sinlut.o \
./Src/sprite.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f30x.o \
./Src/timer.o 

C_DEPS += \
./Src/30010_io.d \
./Src/ADCread.d \
./Src/PCBJoystick.d \
./Src/ansi.d \
./Src/bullets.d \
./Src/buzz.d \
./Src/config.d \
./Src/enemy.d \
./Src/gameBoard.d \
./Src/include.d \
./Src/lcd.d \
./Src/letters.d \
./Src/main.d \
./Src/math.d \
./Src/player.d \
./Src/sets.d \
./Src/sinlut.d \
./Src/sprite.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f30x.d \
./Src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DNUCLEO_F302R8 -DDEBUG -DUSE_STDPERIPH_DRIVER=1 -c -I"C:/Users/Sigurd/Desktop/Programmerings projekt/ProgrameringsProjekt/ProgrameringsProjekt/ArcadeGame/SPL/inc" -I"C:/Users/Sigurd/Desktop/Programmerings projekt/ProgrameringsProjekt/ProgrameringsProjekt/ArcadeGame/Inc" -I"C:/Users/Sigurd/Desktop/Programmerings projekt/ProgrameringsProjekt/ProgrameringsProjekt/ArcadeGame/cmsis" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/30010_io.d ./Src/30010_io.o ./Src/30010_io.su ./Src/ADCread.d ./Src/ADCread.o ./Src/ADCread.su ./Src/PCBJoystick.d ./Src/PCBJoystick.o ./Src/PCBJoystick.su ./Src/ansi.d ./Src/ansi.o ./Src/ansi.su ./Src/bullets.d ./Src/bullets.o ./Src/bullets.su ./Src/buzz.d ./Src/buzz.o ./Src/buzz.su ./Src/config.d ./Src/config.o ./Src/config.su ./Src/enemy.d ./Src/enemy.o ./Src/enemy.su ./Src/gameBoard.d ./Src/gameBoard.o ./Src/gameBoard.su ./Src/include.d ./Src/include.o ./Src/include.su ./Src/lcd.d ./Src/lcd.o ./Src/lcd.su ./Src/letters.d ./Src/letters.o ./Src/letters.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/math.d ./Src/math.o ./Src/math.su ./Src/player.d ./Src/player.o ./Src/player.su ./Src/sets.d ./Src/sets.o ./Src/sets.su ./Src/sinlut.d ./Src/sinlut.o ./Src/sinlut.su ./Src/sprite.d ./Src/sprite.o ./Src/sprite.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32f30x.d ./Src/system_stm32f30x.o ./Src/system_stm32f30x.su ./Src/timer.d ./Src/timer.o ./Src/timer.su

.PHONY: clean-Src

