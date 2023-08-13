MCU=atmega32
F_CPU=8000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy

#disable unused funcs
DIS_UN_FUNC = -ffunction-sections -fdata-sections

CFLAGS=-x c -funsigned-char -funsigned-bitfields -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "Main.d" -MT"Main.d" -MT"Main.o"   -o "Main.o" "main.c"
#**LAYERS FOLDERS
MCALDIR=../../MCAL
HALDIR=../../HAL
STDLIBS=../../LIB
#*****************

INCLUDES= -I${STDLIBS} -I${MCALDIR}/DIO -I${HALDIR}/LCD -I${MCALDIR}/ADC -I.
INCLUDES+= -I${MCALDIR}/TIMER -I${MCALDIR}/EXT -I${MCALDIR}/GIE
#note with library you should put all dependants first >> lcd depen on dio 
LIBS= -L${STDLIBS} -L${MCALDIR}/DIO -L${HALDIR}/LCD -L${MCALDIR}/ADC -L${HALDIR}/KPD
LIBS+= -L${MCALDIR}/TIMER -L${MCALDIR}/EXT -L${MCALDIR}/GIE -L${MCALDIR}/DIO
LIBFILES= -ltimer -llcd -lgie -ldio -ladc
#llcd should be here before ldio

#remove unused funcs
REM_UNUSED = -Wl,--gc-sections

diolib:
	make --directory=${MCALDIR}/DIO lib

lcdlib: 
	make --directory=${HALDIR}/LCD lib

adclib:
	make --directory=${MCALDIR}/ADC lib

kpdlib:
	make --directory=${MCALDIR}/KPD lib

timerlib:
	make --directory=${MCALDIR}/TIMER lib

extlib:
	make --directory=${MCALDIR}/EXT lib

gielib:
	make --directory=${MCALDIR}/GIE lib

#${LIBS} ${LIBFILES}
#linking1: ${CC} -Wl,-Map,MainProgram.map  -mmcu=${MCU} ${LIBS} -o "Main.elf" Main.o ${LIBFILES}
#linking2: ${CC} -o Main.elf  ${LIBS} main.o ${LIBFILES} -Wl,-Map="Main.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=${MCU}
all: lcdlib  diolib timerlib gielib adclib
	${CC}  ${CFLAGS} ${INCLUDES}
	${CC} -o Main.elf  ${LIBS} main.o ${LIBFILES} -Wl,-Map="Main.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=${MCU} 
	avr-objdump -h -S Main.elf  >"Main.lss"
	avr-size --format=avr --mcu=${MCU} Main.elf
	${OBJCOPY} -j .text -j .data -O ihex Main.elf Main.hex

clean:
	@del *.lss *.elf *.hex *.o *.d *.map *.a

# AVRDUDE manual: https://www.nongnu.org/avrdude/user-manual/avrdude_3.html
#Upload HEX file on atmega32 using AVRDUDE
flash:
	avrdude -c usbasp -p m32 -B 0.5 -U flash:w:"Main.hex":a

#avrdude -p m32 -c usbasp -U flash:w:Main.hex:a -P ${PORT}