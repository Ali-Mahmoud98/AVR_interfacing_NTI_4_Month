MCU=atmega32
F_CPU=16000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-x c -funsigned-char -funsigned-bitfields -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "uart.d" -MT"uart.d" -MT"uart.o"   -o "uart.o" "UART_program.c"

STDLIBS=../../LIB 

INCLUDES = -I${STDLIBS} -I.

lib:
	${CC} ${INCLUDES} ${CFLAGS}
	avr-ar -r "libuart.a"  uart.o
	avr-objdump -h -S libuart.a  >"libuart.lss"
	avr-size --format=avr --mcu=${MCU} libuart.a

clean:
	@del *.lss *.elf *.hex *.o *.d *.map *.a