MCU=atmega32
F_CPU=8000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy

#disable unused funcs
DIS_UN_FUNC = -ffunction-sections -fdata-sections

CFLAGS=-x c -funsigned-char -funsigned-bitfields -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "Main.d" -MT"Main.d" -MT"Main.o"   -o "Main.o" "main.c"

#**LAYERS FOLDERS
MCALDIR=../../../MCAL
HALDIR=../../../HAL
STDLIBS=../../../LIB
#*****************

INCLUDES= -I${STDLIBS} -I${MCALDIR}/DIO -I${HALDIR}/LCD -I${MCALDIR}/UART -I.
#note with library you should put all dependants first >> lcd depen on dio 
LIBS= -L${MCALDIR}/DIO -L${HALDIR}/LCD -L${MCALDIR}/UART
LIBFILES= -llcd -ldio -luart
#llcd should be here before ldio
# OBJS= ./02-LCD/lcd.o ./01-DIO/dio.o
# SRCS= ./01-DIO/*.c ./*.c
# PORT=/dev/ttyACM0

#remove unused funcs
REM_UNUSED = -Wl,--gc-sections

diolib:
	make --directory=${MCALDIR}/DIO lib

lcdlib: 
	make --directory=${MCALDIR}/LCD lib

uartlib:
	make --directory=${MCALDIR}/UART lib

#${LIBS} ${LIBFILES}
#linking: ${CC} -Wl,-Map,MainProgram.map  -mmcu=${MCU} ${LIBS} -o "Main.elf" Main.o ${LIBFILES}
all: lcdlib diolib uartlib
	${CC}  ${CFLAGS} ${INCLUDES}
	${CC} -o Main.elf  ${LIBS} main.o ${LIBFILES} -Wl,-Map="Main.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=${MCU} 
	avr-objdump -h -S Main.elf  >"Main.lss"
	avr-size --format=avr --mcu=${MCU} Main.elf
	${OBJCOPY} -j .text -j .data -O ihex Main.elf Main.hex

clean:
	@del /s *.lss *.elf *.hex *.o *.d *.map *.a

# AVRDUDE manual: https://www.nongnu.org/avrdude/user-manual/avrdude_3.html
#Upload HEX file on atmega32 using AVRDUDE
flash:
	avrdude -c usbasp -p m32 -B 0.5 -U flash:w:"Main.hex":a

#avrdude -p m32 -c usbasp -U flash:w:Main.hex:a -P ${PORT}