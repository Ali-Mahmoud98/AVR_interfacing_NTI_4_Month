#define F_CPU 8000000

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include <util/delay.h>

#ifndef NULL
#define NULL ((void *) 0)
#endif
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void (*callBackFunction)(void) = NULL;

void ADC_init(void)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	DDRA &= ~(1<<0); //make A0 input
	DDRA &= ~(1<<1); //make A1 input
	ADMUX = (1<<ADMUX_REFS0); // AREF=AVCC

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock = F_CPU/8 = 1Mhz/8 = 125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //enable adc + PRrescalar div factor =128

}

u16 ADC_readChannel(u8 channel_num)
{
	/* Put Code Here */
	u16 ADC, ADCLOW;
	
	ADMUX=ADMUX|(channel_num & 0x0f);	/* Set input channel to read */

	#if INTERRUPT == DISABLE
	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */
	#endif
	
	ADCLOW = (int)ADCL;		/* Read lower byte*/
	ADC = (int)ADCH*256;		/* Read higher 2 bits and 
					Multiply with weight */
	ADC += ADCLOW;				
	
	return ADC; /* Read the digital value from the data register */
}

/**
 * Enables automatic triggering for ADC conversions.
 */
void ADC_autoTrigger_Enable(void)
{
	SET_BIT(ADCSRA, ADATE);
	SFIOR |= (ADC_TRIGGER_SRC << 5);
}
/**
 * Enables INTERRUPT for ADC conversions.
 */
void ADC_interrupt_ENABLE(void)
{
	SET_BIT(ADCSRA, ADIE);
}

void ADC_setCallBack(void (*ptr2fun) (void))
{
	callBackFunction = ptr2fun;
}

void ADC_falg_clear(void)
{
    SET_BIT(ADCSRA, ADIF);
}

void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
	callBackFunction();
    
}