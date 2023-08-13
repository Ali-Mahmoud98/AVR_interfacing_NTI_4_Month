#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "LED_interface.h"
#include "EXTINT_interface.h"
#include "GIE_interface.h"

void led_ON_callBack(void);

LED led1 = {DIO_u8_PORTA, DIO_u8_PIN6, ACTIVE_HIGH, LOW};

int main(void)
{
	led_init(led1);
	GIE_voidGlobalInterruptEnable();
	EXTINT_voidEnable(EXTINT_INT1,EXTINT_ANY_LOGICAL_CHANGE);
	EXTINT_voidSetCallBack(led_ON_callBack,EXTINT_INT1);
    while (1) 
    {
    }
}

void led_ON_callBack()
{
	led_toggle(led1);
}