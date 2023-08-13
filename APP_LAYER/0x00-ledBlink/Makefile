MCU=atmega32
F_CPU=16000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=${MCU} -DF_CPU=${F_CPU} -MMD -MP -MF"Main.d" -MT"Main.d" -c -o"Main.o" "main.c"

#**LAYERS FOLDERS
MCALDIR=../../MCAL
HALDIR=../../HAL
STDLIBS=../../LIB
#*****************

INCLUDES= -I${STDLIBS} -I${MCALDIR}/DIO
LIBS=-L${MCALDIR}/DIO


diolib:
	make --directory=${MCALDIR}/DIO lib

all: diolib
	${CC}  ${CFLAGS} ${INCLUDES}
	${CC} -Wl,-Map,MainProgram.map ${LIBS} -mmcu=${MCU} -o"Main.elf"  Main.o -ldio
	avr-objdump -h -S Main.elf  >"Main.lss"
	avr-size --format=avr --mcu=${MCU} Main.elf
	${OBJCOPY} -j .text -j .data -O ihex Main.elf Main.hex

clean:
	@del *.lss *.elf *.hex *.o *.d *.map

# AVRDUDE manual: https://www.nongnu.org/avrdude/user-manual/avrdude_3.html
#Upload HEX file on atmega32 using AVRDUDE
flash:
	avrdude -c usbasp -p m32 -B 0.5 -U flash:w:"Main.hex":a

#avrdude -p m32 -c usbasp -U flash:w:Main.hex:a -P ${PORT}
