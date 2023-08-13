#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "DIO_Interface.h"
#include "TIMER_interface.h"
// #include "ADC_interface.h"
#include "LCD_interface.h"

// u8 hr = 0;
// u8 min = 0;
u8 sec = 8;

void watch(void);
void free1(void);
void free2(void);

int main(void)
{
    u8 prev = 5;
    LCD_init();

    DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_OUTPUT);
    //timer0_void_init();
    init_void_timer1(NORMAL, NORMAL_OP, CLOCK_256);

    setCallBack_OV_T1(watch);
    // setCallBack_CMPA_T1(free1);
    // setCallBack_CMPB_T1(free2);
    GIE_voidGlobalInterruptEnable();
    timer1_interrupt_ENABLE();
    // timer1_CMPA_Inerrupt_EN();

    while (1)
    {
        if(prev != sec)
        {
            prev = sec;
            LCD_clearScreen();
            LCD_moveCursor(0,0);
            LCD_sendNumber(sec);
        }
    }
    return 0;
}

void watch(void)
{
    DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, HIGH);
    sec++;
}

void free1(void)
{
    sec++;
}
void free2(void)
{
    sec++;
}
