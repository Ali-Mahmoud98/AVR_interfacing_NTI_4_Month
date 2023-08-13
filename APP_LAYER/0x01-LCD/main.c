#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "LCD_interface.h"
#include "LCD_special_char.h"

int main()
{
    u8 arr[8] = {HART};
    //intialization of LCD
    LCD_init();

    LCD_displayString_XY(0,7,"Hello");
    //put special character at position 0 in CGRAM
    //then print the character in fourth row and 11th column
    LCD_sendSpecialChar(arr,0,3,10);
}