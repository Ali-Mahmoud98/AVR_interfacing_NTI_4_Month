MCU=atmega32
F_CPU=8000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=${MCU} -DF_CPU=${F_CPU} -MMD -MP -MF"lcd.d" -MT"lcd.d" -c -o"lcd.o" *.c
####################
STDLIBS=../../LIB 
MCALDIR=../../MCAL
####################

INCLUDES = -I${STDLIBS} -I${MCALDIR}/DIO -I.

# INCLUDES = -I"../00-LIB" -I"../01-DIO" -I.

lib:
	${CC}  ${CFLAGS} ${INCLUDES}
	avr-ar -r "liblcd.a"  lcd.o
	avr-objdump -h -S liblcd.a  >"liblcd.lss"
	avr-size --format=avr --mcu=${MCU} liblcd.a

clean:
	@rm -r *.lss *.elf *.hex *.o *.d *.map