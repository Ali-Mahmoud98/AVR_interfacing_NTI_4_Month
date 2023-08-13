

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* LCD Data bits mode configuration, its value should be 4 or 8*/
#define LCD_DATA_BITS_MODE 4

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 DIO_u8_PORTA
#define LCD_RS_PIN_ID                  DIO_u8_PIN3

#define LCD_E_PORT_ID                  DIO_u8_PORTA
#define LCD_E_PIN_ID                   DIO_u8_PIN2

#define LCD_DATA_PORT_ID               DIO_u8_PORTB

#if (LCD_DATA_BITS_MODE == 4)

#define LCD_DB4_PIN_ID                 DIO_u8_PIN0
#define LCD_DB5_PIN_ID                 DIO_u8_PIN1
#define LCD_DB6_PIN_ID                 DIO_u8_PIN2
#define LCD_DB7_PIN_ID                 DIO_u8_PIN4

#endif

#define HIGH 1
#define LOW 0

/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define DDRAM_INCREASE_BY1                   0x06
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80

#define lcd_DisplayOn_CursorOff       0x0c          // display on, cursor off, don't blink character 
#define lcd_DisplayOn_CursorOn        0x0e          // display on, cursor on, don't blink character 
#define lcd_DisplayOff_CursorOff      0x08          // turn display off
#define lcd_Clear                     0x01          //replace all characters with ASCII 'space'  
#define lcd_EntryMode                 0x06          // shift cursor from left to right on read/write
#define lcd_Home                      0x02          // return cursor to first position on first line 
#define lcd_CGRAM                     0x40          // the first Place/Address at Character Generator RAM
#define lcd_SetCursor                 0x80          // Force cursor to beginning of first line
#define lcd_FunctionReset             0x30          // reset the LCD

#define FOUR_BITS 0x28 

/*******************************************************************************
 *                      Functions Prototypes                                   *
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
void LCD_init(void);

/**
 * LCD_sendCommand - Sends a command to the LCD module.
 *
 * This function is used to send a command byte to the LCD module. The command
 * byte is typically used to control the behavior of the LCD, such as setting
 * the cursor position, turning on/off the display, clearing the screen, etc.
 *
 * @param command: The command byte to be sent to the LCD.
 */
void LCD_sendCommand(u8 command);

/**
 * LCD_displayCharacter - Displays a character on the LCD module.
 *
 * This function is used to display a single character on the LCD module. It sends
 * the specified character to the LCD to be shown on the screen at the current 
 * cursor position.
 *
 * @param data: The character to be displayed on the LCD.
 */
void LCD_displayCharacter(u8 data);

/**
 * LCD_displayString_XY - Displays a string on the LCD module at the specified location.
 *
 * @param row_u8: The row number (0 to 3) where the string will be displayed.
 * @param pos_u8: The starting position (column) within the row to display the string.
 * @param str: Pointer to the null-terminated string to be displayed on the LCD.
 *             The string should be no longer than the width of the LCD (usually 20 characters).
 *             Note: The function will not display characters outside the 20-character width.
 */
void LCD_displayString_XY(u8 row_u8, u8 pos_u8, const char *str);
/**
 * LCD_SendString - Sends a null-terminated string to the LCD module.
 *
 * @param str: Pointer to the null-terminated string to be displayed on the LCD.
 *             The string should be no longer than the width of the LCD (usually 20 characters).
 *             Note: The function will not display characters outside the 20-character width.
 */
void LCD_SendString (const char *str);

/**
 * LCD_moveCursor - Moves the cursor to the specified location on the LCD module.
 *
 * @param row_u8: The row number (0 to 3) where the cursor will be moved.
 * @param pos_u8: The position (column) within the row where the cursor will be moved.
 *                Note: The position is 0-based, meaning the first position is 0.
 */
void LCD_moveCursor(u8 row_u8,u8 pos_u8);

/**
 * LCD_clearScreen - Clears the display on the LCD module.
 *
 * This function clears the entire display on the LCD module, including any
 * characters and cursor positions. After calling this function, the LCD will
 * be completely blank.
 */
void LCD_clearScreen(void);

/**
 * LCD_sendNumber - Displays a signed 32-bit integer on the LCD module.
 *
 * This function is used to display a signed 32-bit integer on the LCD module.
 * It sends the digits of the number to the LCD for display. The number will be
 * displayed at the current cursor position on the LCD.
 *
 * @param num: The signed 32-bit integer to be displayed on the LCD.
 */
void LCD_sendNumber(s32 num);

/**
 * LCD_sendFloatNumber - Displays a floating-point number on the LCD module.
 *
 * @param num: The floating-point number to be displayed on the LCD.
 * @param numsAfterDecimalPoint: The number of decimal places to display after the decimal point.
 */
void LCD_sendFloatNumber(f32 num, s32 numsAfterDcimalPoint);

/**
 * power_int - Calculates the power of an integer.
 *
 * @param base: The base integer.
 * @param exponent: The exponent integer.
 * @return: The result of 'base' raised to the power of 'exponent' as a signed 32-bit integer.
 */
s32 power_int(s32 base, s32 exponent);

/**
 * rev_num - Reverses the digits of a positive 32-bit integer.
 *
 * @param num: The positive 32-bit integer to be reversed.
 * @return The integer with its digits reversed.
 */
u32 rev_num(u32 num);
#endif /* HAL_LCD_LCD_H_ */
