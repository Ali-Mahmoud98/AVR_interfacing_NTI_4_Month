#ifndef F_CPU

#define F_CPU 16000000UL // clock speed is 16MHz

#endif
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

#include <util/delay.h>

int main(void)
{
    DIO_voidSetPinDirection(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_OUTPUT);

    while (1)
    {
        DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN6, DIO_u8_HIGH);
        _delay_ms(500);
        DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN6, DIO_u8_LOW);
        _delay_ms(500);
    }
    return 0;
}