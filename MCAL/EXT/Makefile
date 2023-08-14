MCU=atmega32
F_CPU=16000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-x c -funsigned-char -funsigned-bitfields -DDEBUG -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "ext.d" -MT"ext.d" -MT"ext.o"   -o "ext.o" "EXTINT_program.c"

STDLIBS=../../LIB 

INCLUDES = -I${STDLIBS} -I.

lib:
	${CC} ${INCLUDES} ${CFLAGS}
	avr-ar -r "libext.a"  ext.o
	avr-objdump -h -S libext.a  >"libext.lss"
	avr-size --format=avr --mcu=${MCU} libext.a

clean:
	@del *.lss *.elf *.hex *.o *.d *.map *.a