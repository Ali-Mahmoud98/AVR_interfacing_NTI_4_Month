#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "LCD_interface.h"
#include "lcd_private.h"
#include "LCD_special_char.h"
#include <util/delay.h> /* For the delay functions */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/**
 * LCD_init - Initializes the LCD module.
 *
 * This function configures the necessary pins and sends commands to initialize
 * the LCD module in 4-bit mode with 2 lines and 5x8 dot display. It also turns
 * off the cursor and clears the LCD screen at the beginning.
 * 
 * Note: This function assumes that the required delays have been implemented 
 * using the _delay_ms() function or equivalent.
 */
void LCD_init(void)
{
	/* Configure the direction for RS and E pins as output pins */
	DIO_voidSetPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_OUTPUT);

	_delay_ms(20);		/* LCD Power ON delay always > 15ms */


	/* Configure 4 pins in the data port as output pins */
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, DIO_u8_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);


	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */

}

/**
 * LCD_sendCommand - Sends a command to the LCD module.
 *
 * This function is used to send a command byte to the LCD module. The command
 * byte is typically used to control the behavior of the LCD, such as setting
 * the cursor position, turning on/off the display, clearing the screen, etc.
 *
 * @param command: The command byte to be sent to the LCD.
 */
void LCD_sendCommand(u8 command)
{
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, GET_BIT(command, 7));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, GET_BIT(command, 6));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, GET_BIT(command, 5));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, GET_BIT(command, 4));  
	DIO_voidSetPinValue  ( LCD_RS_PORT_ID , LCD_RS_PIN_ID , LOW );		/* RS=1, data reg. */
	LCD_SendFallingEdge();

	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, GET_BIT(command, 3));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, GET_BIT(command, 2));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, GET_BIT(command, 1));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, GET_BIT(command, 0)); 
	DIO_voidSetPinValue  ( LCD_RS_PORT_ID , LCD_RS_PIN_ID , LOW );		/* RS=1, data reg. */
	LCD_SendFallingEdge();

	_delay_ms(1); /* delay for processing Th = 13ns */

}

/**
 * LCD_displayCharacter - Displays a character on the LCD module.
 *
 * This function is used to display a single character on the LCD module. It sends
 * the specified character to the LCD to be shown on the screen at the current 
 * cursor position.
 *
 * @param data: The character to be displayed on the LCD.
 */
void LCD_displayCharacter(u8 data)
{
	/* sending upper nibble */
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, GET_BIT(data, 7));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, GET_BIT(data, 6));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, GET_BIT(data, 5));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, GET_BIT(data, 4));  
	DIO_voidSetPinValue  ( LCD_RS_PORT_ID , LCD_RS_PIN_ID , HIGH );		/* RS=1, data reg. */
	LCD_SendFallingEdge();

	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN4, GET_BIT(data, 3));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, GET_BIT(data, 2));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, GET_BIT(data, 1));  
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, GET_BIT(data, 0)); 
	DIO_voidSetPinValue  ( LCD_RS_PORT_ID , LCD_RS_PIN_ID , HIGH );		/* RS=1, data reg. */
	LCD_SendFallingEdge();

	_delay_ms(1);
}

/**
 * LCD_displayString_XY - Displays a string on the LCD module at the specified location.
 *
 * @param row_u8: The row number (0 to 3) where the string will be displayed.
 * @param pos_u8: The starting position (column) within the row to display the string.
 * @param str: Pointer to the null-terminated string to be displayed on the LCD.
 *             The string should be no longer than the width of the LCD (usually 20 characters).
 *             Note: The function will not display characters outside the 20-character width.
 */
void LCD_displayString_XY(u8 row_u8, u8 pos_u8, const char *str)
{
	if (row_u8 < 0 || pos_u8 < 0)
		return;
	/*send char to location XY*/
	if (row_u8 == 0 && pos_u8<20)
		LCD_sendCommand(pos_u8 + 0x80);	/* Command of first row and required position<20 */
	else if (row_u8 == 1 && pos_u8<20)
		LCD_sendCommand(pos_u8 + 0xC0);	/* Command of first row and required position<20 */
	else if (row_u8 == 2 && pos_u8<20)
		LCD_sendCommand(pos_u8 + 0x94);	/* Command of first row and required position<20 */
	else if (row_u8 == 3 && pos_u8<20)
		LCD_sendCommand(pos_u8 + 0xD4);	/* Command of first row and required position<20 */
	LCD_SendString(str);		/* Call LCD string function */
}

/**
 * LCD_SendString - Sends a null-terminated string to the LCD module.
 *
 * @param str: Pointer to the null-terminated string to be displayed on the LCD.
 *             The string should be no longer than the width of the LCD (usually 20 characters).
 *             Note: The function will not display characters outside the 20-character width.
 */
void LCD_SendString (const char *str){
    u8 Iterator_u8 = 0 ;

	while( str[Iterator_u8] != '\0' ){

		LCD_displayCharacter( str[Iterator_u8] );
		Iterator_u8++ ;
	}
}

/**
 * LCD_moveCursor - Moves the cursor to the specified location on the LCD module.
 *
 * @param row_u8: The row number (0 to 3) where the cursor will be moved.
 * @param pos_u8: The position (column) within the row where the cursor will be moved.
 *                Note: The position is 0-based, meaning the first position is 0.
 */
void LCD_moveCursor(u8 row_u8,u8 pos_u8)
{
	if (row_u8 < 0 || pos_u8 < 0)
		return;
	
	if (row_u8 == 0 && pos_u8<20)
		LCD_sendCommand((pos_u8 + 0x80));	/* Command of first row and required position<20 */
	else if (row_u8 == 1 && pos_u8<20)
		LCD_sendCommand((pos_u8 + 0xC0));	/* Command of first row and required position<20 */
	else if (row_u8 == 2 && pos_u8<20)
		LCD_sendCommand((pos_u8 + 0x94));	/* Command of first row and required position<20 */
	else if (row_u8 == 3 && pos_u8<20)
		LCD_sendCommand((pos_u8 + 0xD4));	/* Command of first row and required position<20 */
}

/**
 * LCD_clearScreen - Clears the display on the LCD module.
 *
 * This function clears the entire display on the LCD module, including any
 * characters and cursor positions. After calling this function, the LCD will
 * be completely blank.
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}

/**
 * LCD_SendFallingEdge - Sends a falling edge signal to the LCD module.
 *
 * Note: This function is intended for internal use within the LCD driver and
 * should not be called directly from outside the driver.
 */
static void LCD_SendFallingEdge(){
    
    DIO_voidSetPinValue  ( LCD_E_PORT_ID, LCD_E_PIN_ID , HIGH );
	_delay_ms(1);
	DIO_voidSetPinValue  ( LCD_E_PORT_ID, LCD_E_PIN_ID , LOW  );
	_delay_ms(1);
}

/**
 * LCD_sendNumber - Displays a signed 32-bit integer on the LCD module.
 *
 * This function is used to display a signed 32-bit integer on the LCD module.
 * It sends the digits of the number to the LCD for display. The number will be
 * displayed at the current cursor position on the LCD.
 *
 * @param num: The signed 32-bit integer to be displayed on the LCD.
 */
void LCD_sendNumber(s32 num)
{
	u32 n;

	if (num == 0)
	{
		LCD_displayCharacter('0');
		return;
	}
	if (num < 0)
	{
		n = -num;
		LCD_displayCharacter('-');
	} else
	{
		n = num;
	}

	n = rev_num(n);

	while ((n != 1))
	{
		LCD_displayCharacter('0' + (n % 10));
		n /= 10;
	}
}
/**
 * LCD_sendFloatNumber - Displays a floating-point number on the LCD module.
 *
 * @param num: The floating-point number to be displayed on the LCD.
 * @param numsAfterDecimalPoint: The number of decimal places to display after the decimal point.
 */
void LCD_sendFloatNumber(f32 num, s32 numsAfterDcimalPoint)
{
	if (numsAfterDcimalPoint < 1)
		return;
	
	s32 intpart = (s32) num;
	s32 decpart = (num -  intpart) * (power_int(10, numsAfterDcimalPoint));
	LCD_sendNumber(intpart);
	LCD_displayCharacter('.');
	LCD_sendNumber(decpart);
}

/**
 * power_int - Calculates the power of an integer.
 *
 * @param base: The base integer.
 * @param exponent: The exponent integer.
 * @return: The result of 'base' raised to the power of 'exponent' as a signed 32-bit integer.
 */
s32 power_int(s32 base, s32 exponent) 
{
    s32 result = 1;
    s32 i;

    for (i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

/**
 * rev_num - Reverses the digits of a positive 32-bit integer.
 *
 * @param num: The positive 32-bit integer to be reversed.
 * @return The integer with its digits reversed.
 */
u32 rev_num(u32 num)
{
	u32 rev = 1;

	while (num)
	{
		rev = (rev * 10) + (num % 10);
		num /= 10;
	}
	return rev;
}

/**
 * LCD_sendSpecialChar - Sends a custom special character to the LCD module.
 *
 * Note: This function requires prior configuration of the custom character in CGRAM
 * using 'LCD_defineSpecialChar' function or similar. The 'row' and 'col' parameters
 * must be within the valid range of the LCD dimensions to ensure correct display.
 *
 * @param letter: Pointer to the array containing the custom character's pattern in CGRAM format.
 * @param positionCGRAM: The position in CGRAM (0 to 7) where the custom pattern will be stored.
 * @param row: The row (0 to 3) where the custom character will be displayed on the LCD.
 * @param col: The column (0 to 19) where the custom character will be displayed on the LCD.
 */
void LCD_sendSpecialChar(u8 *letter, u8 positionCGRAM, u8 row, u8 col)
{
	if (row > 3 || col > 19 || positionCGRAM > 7)
		return;
	
	LCD_sendCommand(lcd_CGRAM + (positionCGRAM * 8));
	for (u8 i = 0; (i < (u8) 8); i++)
	{
		LCD_displayCharacter(letter[i]);
	}
	LCD_moveCursor(row,col);
    LCD_displayCharacter(positionCGRAM);
}