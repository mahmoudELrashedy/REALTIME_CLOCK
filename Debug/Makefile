################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../CLK.c \
../EXTI_FUNC.c \
../get_pressed_key.c \
../GI_FUNC.c \
../LCD_LIB.c \
../main.c \
../SEVENSEGMENT.c \
../TMR0_program.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
CLK.o \
EXTI_FUNC.o \
get_pressed_key.o \
GI_FUNC.o \
LCD_LIB.o \
main.o \
SEVENSEGMENT.o \
TMR0_program.o

OBJS_AS_ARGS +=  \
CLK.o \
EXTI_FUNC.o \
get_pressed_key.o \
GI_FUNC.o \
LCD_LIB.o \
main.o \
SEVENSEGMENT.o \
TMR0_program.o

C_DEPS +=  \
CLK.d \
EXTI_FUNC.d \
get_pressed_key.d \
GI_FUNC.d \
LCD_LIB.d \
main.d \
SEVENSEGMENT.d \
TMR0_program.d

C_DEPS_AS_ARGS +=  \
CLK.d \
EXTI_FUNC.d \
get_pressed_key.d \
GI_FUNC.d \
LCD_LIB.d \
main.d \
SEVENSEGMENT.d \
TMR0_program.d

OUTPUT_FILE_PATH +=REALTIME_CLOCK.elf

OUTPUT_FILE_PATH_AS_ARGS +=REALTIME_CLOCK.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler

















./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)E:\atmel studio setup\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"E:\atmel studio setup\7.0\Packs\atmel\ATmega_DFP\1.2.150\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "E:\atmel studio setup\7.0\Packs\atmel\ATmega_DFP\1.2.150\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)E:\atmel studio setup\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="REALTIME_CLOCK.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "E:\atmel studio setup\7.0\Packs\atmel\ATmega_DFP\1.2.150\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"E:\atmel studio setup\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "REALTIME_CLOCK.elf" "REALTIME_CLOCK.hex"
	"E:\atmel studio setup\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "REALTIME_CLOCK.elf" "REALTIME_CLOCK.eep" || exit 0
	"E:\atmel studio setup\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "REALTIME_CLOCK.elf" > "REALTIME_CLOCK.lss"
	"E:\atmel studio setup\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "REALTIME_CLOCK.elf" "REALTIME_CLOCK.srec"
	"E:\atmel studio setup\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "REALTIME_CLOCK.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "REALTIME_CLOCK.elf" "REALTIME_CLOCK.a" "REALTIME_CLOCK.hex" "REALTIME_CLOCK.lss" "REALTIME_CLOCK.eep" "REALTIME_CLOCK.map" "REALTIME_CLOCK.srec" "REALTIME_CLOCK.usersignatures"
	