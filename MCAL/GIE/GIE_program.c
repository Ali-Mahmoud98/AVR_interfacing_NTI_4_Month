
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_private.h"
#include "GIE_interface.h"


//enable global interrupt
void GIE_voidGlobalInterruptEnable(void)
{
	SET_BIT(SREG, SREG_I);
}
//disable interrupt
void GIE_voidGlobalInterruptDisable(void)
{
	CLR_BIT(SREG, SREG_I);
}
