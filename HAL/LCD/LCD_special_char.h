#ifndef LCD_SPECIAL_CHAR_H_
#define LCD_SPECIAL_CHAR_H_

#define HART 0b00000, 0b00000, 0b01010, 0b10101, 0b10001, 0b01110, 0b00100, 0b00000


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
void LCD_sendSpecialChar(u8 *letter, u8 positionCGRAM, u8 row, u8 col);

#endif