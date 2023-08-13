#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "DIO_Interface.h"
#include "TIMER_interface.h"
// #include "ADC_interface.h"
#include "EXTINT_interface.h"

void incraese2per(void);
void decrease2per(void);

u8 duty_cycle = 0;


int main(void)
{
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN4, DIO_u8_OUTPUT);
    GIE_voidGlobalInterruptEnable();

    EXTINT_voidEnable(EXTINT_INT0, EXTINT_RAISING_EDGE);
    EXTINT_voidEnable(EXTINT_INT1, EXTINT_RAISING_EDGE);
    EXTINT_voidSetCallBack(incraese2per, EXTINT_INT0);
    EXTINT_voidSetCallBack(decrease2per, EXTINT_INT1);
    timer0_void_init();
    DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN3, DIO_u8_OUTPUT);
    while (1)
    {
        TIMER0_voidPWM(duty_cycle);
    }
    return 0;
}

void incraese2per(void)
{
    DIO_voidTogglePinValue(DIO_u8_PORTB, DIO_u8_PIN4);
    duty_cycle += 2;
    if (duty_cycle > 100)
    {
        duty_cycle = 100;
    }
}
void decrease2per(void)
{
    DIO_voidTogglePinValue(DIO_u8_PORTB, DIO_u8_PIN4);
    if (duty_cycle <= 2)
    {
        duty_cycle = 0;
    }
    duty_cycle -= 2;
}