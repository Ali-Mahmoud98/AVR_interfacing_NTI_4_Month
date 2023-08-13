#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "LCD_interface.h"
#include "UART_interface.h"

int main()
{
    u8 rx_data;

    LCD_init();
    UART_voidInit();

    LCD_displayString_XY(0,2,"Recieved Data:");
    LCD_moveCursor((u8) 1, (u8) 0);
    while (1)
    {
        rx_data = UART_voidGetChar();
        LCD_displayCharacter(rx_data);
    } 
}