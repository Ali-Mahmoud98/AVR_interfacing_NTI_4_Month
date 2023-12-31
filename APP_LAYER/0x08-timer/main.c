#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "DIO_Interface.h"
#include "TIMER_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"

volatile u8 sec = 0;
volatile u16 val = 0;

void watch(void);
void sendValueToLCD(void);
void tog_led(void);

int main(void)
{
    u8 prev = 5;
    u16 prev2 = 0;
    LCD_init();

    DIO_voidSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_INPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN6, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_OUTPUT);
    timer0_void_init();
    TIMER0_voidSetPreload(0, 112);
    init_void_timer1(NORMAL, NORMAL_OP, CLOCK_256);

    ADC_init();
    ADC_autoTrigger_Enable();
    ADC_setCallBack(sendValueToLCD);

    setCallBack_OV_T1(tog_led);
    
    timer1_interrupt_ENABLE();
    timer0_Interrupt_OverFlow_Enable();
    setCallBack_OV_T0(watch);
    ADC_interrupt_ENABLE();

    GIE_voidGlobalInterruptEnable();

    LCD_displayString_XY(0, 0, "No. of T0 OVS: ");
    LCD_displayString_XY(1, 0, "ADC Value: ");

    while (1)
    {
        if(prev != sec)
        {
            prev = sec;
            LCD_SendString("     ");
            LCD_moveCursor(0,15);
            LCD_sendNumber(sec);
        }

        if(prev2 != val)
        {
            prev2 = val;
            LCD_SendString("     ");
            LCD_moveCursor(1,11);
            LCD_sendNumber(val);
        }
    }
    return 0;
}

void watch(void)
{
    static u16 delay = 0;
    if (delay >= 31)
    {
        sec++;
        delay = 0;
        TIMER0_voidSetPreload(0, 123);
    }
    delay++;
}

void sendValueToLCD(void)
{
   val = ADC_readChannel(0);
}


void tog_led(void)
{
    DIO_voidTogglePinValue(DIO_u8_PORTA, DIO_u8_PIN6);
}