#define F_CPU 16000000

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
#include "KEYPAD_Interface.h"

#include <util/delay.h>

int isDigit(u8 c)
{
    u8 a = 0;
    if (c >= '0' && c <= '9')
    {
        a = 1;
    }
    return a;
}
void reset_screen()
{
    LCD_displayString_XY(0,0,"                   ");
    LCD_displayString_XY(0,0,"ERROR");
    LCD_displayString_XY(1,0,"FORMAT is");
    LCD_displayString_XY(2,0,"NUM1 + NUM2");
    _delay_ms(3000);
    LCD_clearScreen();
    LCD_displayString_XY(0,3,"Calculator:");
    LCD_moveCursor((u8) 1, (u8) 0);
}

int main()
{
    u8 keyPad_Val = 0xFF;
    u16 i = 0;
    u8 start = 0;
    s32 num[3] = {0};
    // u8 buffer1[12] = {0};
    LCD_init();
    ADC_init();
    KPD_voidInit();


    LCD_displayString_XY(0,3,"Calculator:");
    LCD_moveCursor((u8) 1, (u8) 0);

    while (1)
    {
        keyPad_Val= KPD_u8GetPressedKey();
        if (keyPad_Val != 0xFF)
        {
            if (start == 0 && !isDigit(keyPad_Val))
            {
                reset_screen();
            } 
            else if (isDigit(keyPad_Val) && (i < 2))
            {
                start = 1;
                num[i] = (num[i] * 10) + (keyPad_Val - '0');
                LCD_displayCharacter(keyPad_Val); 
            }
            else if (keyPad_Val == '+')
            {
                i = 1; // Set the index to store in the second number
                if (i == 1)
                {
                    LCD_displayString_XY(2, 0,"+"); // Clear the second line
                    LCD_moveCursor(3, 0);
                }   
            }
            else if (keyPad_Val == '=')
            {
                if (i == 1)
                {
                    LCD_displayString_XY(1, 0, "                "); // Clear the second line
                    LCD_displayString_XY(2, 0, "                "); // Clear the second line
                    LCD_displayString_XY(3, 0, "                "); // Clear the second line
                    LCD_moveCursor(1, 0);
                    num[3] = num[1] + num[0];
                    LCD_sendNumber(num[3]);
                    i = 0; // Reset the index for the next calculation
                }
                start = 0;
            }
            else if (keyPad_Val == 'C')
            {
                // Clear the calculator and reset the values
                num[0] = 0;
                num[1] = 0;
                num[3] = 0;
                i = 0;
                LCD_clearScreen();
                LCD_displayString_XY(0, 3, "Calculator:");
                LCD_moveCursor(1, 0);
                start = 0;
            }
        } 
    } 
}