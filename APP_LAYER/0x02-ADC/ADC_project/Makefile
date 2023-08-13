MCU=atmega32
F_CPU=16000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
DIS_UN_FUNC = -ffunction-sections -fdata-sections
CFLAGS=-Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=${MCU} -DF_CPU=${F_CPU} -MMD -MP -MF"Main.d" -MT"Main.d" -c -o"Main.o" "main.c"

#**LAYERS FOLDERS
MCALDIR=../../../MCAL
HALDIR=../../../HAL
STDLIBS=../../../LIB
#*****************

INCLUDES= -I${STDLIBS} -I${MCAL}/DIO -I${HALDIR}/LCD -I${MCALDIR}/ADC -I.
#note with library you should put all dependants first >> lcd depen on dio 
LIBS= -L${STDLIBS} -L${MCAL}/DIO -L${HALDIR}/LCD -L${MCALDIR}/ADC
LIBFILES= -llcd -ladc -ldio
#llcd should be here before ldio
REM_UNUSED = -Wl,--gc-sections

diolib:
	make --directory=${MCALDIR}/DIO lib

lcdlib: 
	make --directory=${HALDIR}/LCD lib

adclib:
	make --directory=${MCALDIR}/ADC lib

# prev_linker: ${CC} -Wl,-Map,MainProgram.map  -mmcu=${MCU} ${LIBS} -o "Main.elf" Main.o ${LIBFILES}
all: lcdlib diolib adclib
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