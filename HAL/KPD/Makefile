MCU=atmega32
F_CPU=16000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-x c -funsigned-char -funsigned-bitfields -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "kpd.d" -MT"kpd.d" -MT"kpd.o"   -o "kpd.o" "KEYPAD_program.c"
####################
STDLIBS=../../LIB 
MCALDIR=../../MCAL
####################

INCLUDES = -I${STDLIBS} -I${MCALDIR}/DIO -I.

lib:
	${CC} ${INCLUDES} ${CFLAGS}
	avr-ar -r "libkpd.a"  kpd.o
	avr-objdump -h -S libkpd.a  >"libkpd.lss"
	avr-size --format=avr --mcu=${MCU} libkpd.a

clean:
	@del *.lss *.elf *.hex *.o *.d *.map *.a