MCU=atmega32
F_CPU=16000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-x c -funsigned-char -funsigned-bitfields -DDEBUG -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "spi.d" -MT"spi.d" -MT"spi.o"   -o "spi.o" "SPI_program.c"

STDLIBS=../../LIB 

INCLUDES = -I${STDLIBS} -I.

lib:
	${CC} ${INCLUDES} ${CFLAGS}
	avr-ar -r "libspi.a"  spi.o
	avr-objdump -h -S libspi.a  >"libspi.lss"
	avr-size --format=avr --mcu=${MCU} libspi.a

clean:
	@del *.lss *.elf *.hex *.o *.d *.map *.a