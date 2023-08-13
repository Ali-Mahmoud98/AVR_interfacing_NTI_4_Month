MCU=atmega32
F_CPU=16000000UL
CC=avr-gcc
OBJCOPY=avr-objcopy

#disable unused funcs
DIS_UN_FUNC = -ffunction-sections -fdata-sections

CFLAGS=-x c -funsigned-char -funsigned-bitfields -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "Main.d" -MT"Main.d" -MT"Main.o"   -o "Main.o" "main.c"
INCLUDES= -I"LIB" -I"./MCAL/01-DIO" -I"./MCAL/EXT" -I"./MCAL/GIE" -I"./HAL/LED" -I.
#note with library you should put all dependants first >> lcd depen on dio 
LIBS= -L./MCAL/01-DIO -L./MCAL/EXT -L./MCAL/GIE -L./HAL/LED
LIBFILES= -lext -lgie -lled -ldio

diolib:
	@cd MCAL\01-DIO && make lib
	@cd ..

ledlib: 
	@cd HAL\LED && make lib
	@cd ..
	@cd ..

extlib:
	@cd MCAL\EXT && make lib
	@cd ..
	@cd ..

kpdlib:
	@cd MCAL\GIE && make lib
	@cd ..
	@cd ..

#${LIBS} ${LIBFILES}
#linking: ${CC} -Wl,-Map,MainProgram.map  -mmcu=${MCU} ${LIBS} -o "Main.elf" Main.o ${LIBFILES}
all: ledlib diolib  extlib kpdlib
	${CC}  ${CFLAGS} ${INCLUDES}
	${CC} -o Main.elf  ${LIBS} main.o ${LIBFILES} -Wl,-Map="Main.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=${MCU} 
	avr-objdump -h -S Main.elf  >"Main.lss"
	avr-size --format=avr --mcu=${MCU} Main.elf
	${OBJCOPY} -j .text -j .data -O ihex Main.elf Main.hex

clean:
	@del /s *.lss *.elf *.hex *.o *.d *.map *.a

# AVRDUDE manual: https://www.nongnu.org/avrdude/user-manual/avrdude_3.html
#Upload HEX file on atmega32 using AVRDUDE
flash:
	avrdude -c usbasp -p m32 -B 0.5 -U flash:w:"Main.hex":a

#avrdude -p m32 -c usbasp -U flash:w:Main.hex:a -P ${PORT}