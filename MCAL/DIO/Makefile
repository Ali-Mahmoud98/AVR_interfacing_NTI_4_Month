MCU=atmega32
F_CPU=8000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=${MCU} -DF_CPU=${F_CPU} -MMD -MP -MF"dio.d" -MT"dio.d" -c -o"dio.o" *.c

STDLIBS=../../LIB 

INCLUDES = -I${STDLIBS} -I.

lib:
	${CC}  ${CFLAGS} ${INCLUDES}
	avr-ar -r "libdio.a"  dio.o
	avr-objdump -h -S libdio.a  >"libdio.lss"
	avr-size --format=avr --mcu=${MCU} libdio.a

clean:
	@del *.lss *.elf *.hex *.o *.d *.map *.a