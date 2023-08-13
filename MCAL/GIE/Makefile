MCU=atmega32
F_CPU=16000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-x c -funsigned-char -funsigned-bitfields -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "gie.d" -MT"gie.d" -MT"gie.o"   -o "gie.o" "GIE_program.c"

STDLIBS=../../LIB 

INCLUDES = -I${STDLIBS} -I.

lib:
	${CC} ${INCLUDES} ${CFLAGS}
	avr-ar -r "libgie.a"  gie.o
	avr-objdump -h -S libgie.a  >"libgie.lss"
	avr-size --format=avr --mcu=${MCU} libgie.a

clean:
	@del *.lss *.elf *.hex *.o *.d *.map *.a