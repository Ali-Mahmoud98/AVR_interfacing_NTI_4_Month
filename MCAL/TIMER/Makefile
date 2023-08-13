MCU=atmega32
F_CPU=8000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=${MCU} -DF_CPU=${F_CPU} -MMD -MP -MF"timer.d" -MT"timer.d" -c -o"timer.o" *.c

STDLIBS=../../LIB 

INCLUDES = -I${STDLIBS} -I.

lib:
	${CC}  ${CFLAGS} ${INCLUDES}
	avr-ar -r "libtimer.a"  timer.o
	avr-objdump -h -S libtimer.a  >"libtimer.lss"
	avr-size --format=avr --mcu=${MCU} libtimer.a

clean:
	@del *.lss *.elf *.hex *.o *.d *.map