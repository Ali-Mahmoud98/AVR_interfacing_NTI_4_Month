MCU=atmega32
F_CPU=16000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-x c -funsigned-char -funsigned-bitfields -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "led.d" -MT"led.d" -MT"led.o"   -o "led.o" "LED_interface.c"
####################
STDLIBS=../../LIB 
MCALDIR=../../MCAL
####################

INCLUDES = -I${STDLIBS} -I${MCALDIR}/DIO -I.
# INCLUDES = -I"../../LIB" -I"../../MCAL/01-DIO" -I.

lib:
	${CC} ${INCLUDES} ${CFLAGS}
	avr-ar -r "libled.a"  led.o
	avr-objdump -h -S libled.a  >"libled.lss"
	avr-size --format=avr --mcu=${MCU} libled.a

clean:
	@del *.lss *.elf *.hex *.o *.d *.map *.a