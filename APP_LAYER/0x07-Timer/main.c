#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "DIO_Interface.h"
#include "TIMER_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"

volatile u16 val = 0;

void sendValueToLCD(void);
void tog_led(void);

int main(void)
{
    u16 prev = 0;
    //DIO_voidSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN6, DIO_u8_OUTPUT);
    LCD_init();
    timer0_void_init();
    ADC_init();
    ADC_autoTrigger_Enable();
    ADC_setCallBack(sendValueToLCD);
    ADC_interrupt_ENABLE();
    timer0_Interrupt_OverFlow_Enable();
    setCallBack_OV_T0(tog_led);
    GIE_voidGlobalInterruptEnable();
    while (1)
    {
        if (prev != val)
        {
            prev = val;
            LCD_clearScreen();
        }
        LCD_moveCursor(0,0);
        LCD_sendNumber((s32)val);
    }
    return 0;
}

void sendValueToLCD(void)
{
   val = ADC_readChannel(0);
}

void tog_led(void){
    
}