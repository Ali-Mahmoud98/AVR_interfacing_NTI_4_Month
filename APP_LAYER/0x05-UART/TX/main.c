#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "KEYPAD_Interface.h"
#include "UART_interface.h"

int main()
{
    u8 kpdVal = 0xFF;
    KPD_voidInit();
    UART_voidInit();
    while (1)
    {
        kpdVal = KPD_u8GetPressedKey();
        if (kpdVal != 0xFF)
        {
            UART_voidSendChar(kpdVal);   
        }
    }
}
