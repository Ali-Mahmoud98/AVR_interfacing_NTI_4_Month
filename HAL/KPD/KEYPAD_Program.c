
/****************************************************/
/* Header files Inclusions						    */
/****************************************************/
#define F_CPU 16000000

#include "util/delay.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Private.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"

#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Private.h"

u8 KEYPAD_Au8Keys [KEYPAD_u8_ROW_NUM][KEYPAD_u8_COL_NUM] = KEYPAD_Au8_KEYS;


/*********************************************************************************/
/* Function: KPD_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize KEYPAD								       	    **/
/*********************************************************************************/
void KPD_voidInit(void)
{
	/*Set Rows pins to be output & Columns pins to be input*/
	/*ROW pins to be out*/
	DIO_voidSetPinDirection(KEYPAD_u8_ROWS_PORT, KEYPAD_u8_R1_PIN, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_ROWS_PORT, KEYPAD_u8_R2_PIN, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_ROWS_PORT, KEYPAD_u8_R3_PIN, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_ROWS_PORT, KEYPAD_u8_R4_PIN, DIO_u8_OUTPUT);
	/*COL pins input*/
	DIO_voidSetPinDirection(KEYPAD_u8_COLS_PORT, KEYPAD_u8_C1_PIN, DIO_u8_INPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_COLS_PORT, KEYPAD_u8_C2_PIN, DIO_u8_INPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_COLS_PORT, KEYPAD_u8_C3_PIN, DIO_u8_INPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_COLS_PORT, KEYPAD_u8_C4_PIN, DIO_u8_INPUT);

	/*COL PINS to be input PULL UP*/
	DIO_voidSetPinValue(KEYPAD_u8_COLS_PORT, KEYPAD_u8_C1_PIN, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_u8_COLS_PORT, KEYPAD_u8_C2_PIN, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_u8_COLS_PORT, KEYPAD_u8_C3_PIN, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_u8_COLS_PORT, KEYPAD_u8_C4_PIN, DIO_u8_HIGH);
}

/*********************************************************************************/
/* Function: KPD_u8GetPressedKey	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns u8	                                				    **/
/* Desc:This Function used to get the value of the pressed key		       	    **/
/*********************************************************************************/
u8 KPD_u8GetPressedKey (void)
{
	u8 local_u8RowCounter,
	   local_u8ColCounter,
	   local_u8PinValue,
	   local_u8KeyValue=KEYPAD_KEY_NOT_PRESSED,
	   local_u8Flag= KEYPAD_u8_FLAG_DOWN;
	   
	   /*
	   local_u8RowCounter: the current row number in the For Loop
	   local_u8ColCounter: the current Col number in the For Loop
	   local_u8PinValue  : the state of the current Col reading is High or Low
	   local_u8KeyValue  : the pressed key value in asci ('0' '1' ... '*' '/' ...)
						   initial state =KEYPAD_KEY_NOT_PRESSED = 0xff
	   local_u8Flag      : when a key is pressed flag will be up and the loop will be broken 
						   initially =KEYPAD_u8_FLAG_DOWN; 
	   */
	u8 KEYPAD_Au8RowsPins[KEYPAD_u8_ROW_NUM] = KEYPAD_Au8ROWs;
	u8 KEYPAD_Au8ColsPins[KEYPAD_u8_COL_NUM] = KEYPAD_Au8Cols;

	for (local_u8RowCounter=0; local_u8RowCounter < KEYPAD_u8_ROW_NUM; local_u8RowCounter++ )
	{
		DIO_voidSetPinValue(KEYPAD_u8_ROWS_PORT,KEYPAD_Au8RowsPins[local_u8RowCounter],DIO_u8_LOW); //Activate ROw by Setting 0 at output

		for (local_u8ColCounter=0; local_u8ColCounter < KEYPAD_u8_COL_NUM; local_u8ColCounter++)
		{
			if (DIO_voidGetPinValue(KEYPAD_u8_COLS_PORT, KEYPAD_Au8ColsPins[local_u8ColCounter]) == KEYPAD_u8_FLAG_DOWN)
			{
				_delay_ms(KEYPAD_u8_DEBOUNCING_MS);
				local_u8KeyValue = KEYPAD_Au8Keys[local_u8RowCounter][local_u8ColCounter];
				while (DIO_voidGetPinValue(KEYPAD_u8_COLS_PORT, KEYPAD_Au8ColsPins[local_u8ColCounter]) == KEYPAD_u8_FLAG_DOWN){}
			}
			
		}
		DIO_voidSetPinValue(KEYPAD_u8_ROWS_PORT,KEYPAD_Au8RowsPins[local_u8RowCounter],DIO_u8_HIGH); //De-Activate column by Setting 1 at output
		if (local_u8Flag==KEYPAD_u8_FLAG_UP)
		{
			break;
		}
	}
	return local_u8KeyValue;
}
