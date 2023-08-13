MCU=atmega32
F_CPU=16000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-x c -funsigned-char -funsigned-bitfields -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "adc.d" -MT"adc.d" -MT"adc.o"   -o "adc.o" "ADC_program.c"

STDLIBS=../../LIB 

INCLUDES = -I${STDLIBS} -I.

lib:
	${CC} ${INCLUDES} ${CFLAGS}
	avr-ar -r "libadc.a"  adc.o
	avr-objdump -h -S libadc.a  >"libadc.lss"
	avr-size --format=avr --mcu=${MCU} libadc.a

clean:
	@rm -r *.lss *.elf *.hex *.o *.d *.map *.a