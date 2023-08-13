#define F_CPU 16000000

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "LCD_interface.h"
#include "LCD_special_char.h"
#include "ADC_interface.h"

#include <util/delay.h>

// f32 map(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max) {
//     return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
// }

int main()
{
    u32 val = 0;
    u8 l[] = {HART};
    // u32 prev_val = 8000;
    // u32 ipart;
    // u32 dPart;

    LCD_init();
    ADC_init();

    LCD_displayString_XY(0,4,"Voltage (V):");
    LCD_sendSpecialChar(l,0,2,10);
    LCD_sendSpecialChar(l,0,3,10);
    
    while (1)
    {
        // val = ADC_readChannel(0);
        if (val != (u32) ADC_readChannel(0))
        {
            // prev_val = val;
            val = (u32) ADC_readChannel(0);
            // ipart = (u32) map(val,0,1023,0,5);
            // dPart = (u32) ((map(val,0,1023,0,5) - ipart) * 100);
            LCD_moveCursor(1,7);
            // LCD_sendNumber(ipart);
            // LCD_displayCharacter('.');
            // LCD_sendNumber(dPart);
            LCD_sendNumber(((val * 5 * 1000) / 1024) / 1000);
            LCD_displayCharacter('.');
            LCD_sendNumber(((val * 5 * 1000) / 1024) % 1000);
            _delay_ms(100);
        } 
    } 
}