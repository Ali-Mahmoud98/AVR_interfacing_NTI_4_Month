#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define DDRA  *( (volatile u8*) 0x3A) /*DDRA REG*/

/* Bit Masking Macros  */
#define ADC_PRE_MASK				0b11111000
#define ADC_CH_MASK				    0b11100000

#define ADMUX				*((volatile u8*)0x27)		//ADC multiplexer selection register
/* ADMUX Bits   */
#define ADMUX_REFS1         7							//Reference selection bit1
#define ADMUX_REFS0         6							//Reference selection bit0
#define ADMUX_ADLAR         5							//ADC left adjust result



#define ADCSRA				*((volatile u8*)0x26)		//ADC control and status register A
/* ADSRA Bits   */
#define ADEN			7							//ADC enable
#define ADSC			6                           //Start conversion
#define ADATE		    5                           //Auto trigger enable
#define ADIF			4                           //Interrupt flag
#define ADIE			3                           //Interrupt enable
#define ADPS2		    2                           //Prescaler bit2
#define ADPS1		    1                           //Prescaler bit1
#define ADPS0		    0                           //Prescaler bit0


/* Data Reg  */
#define ADCH				*((volatile u8*)0x25)		//ADC high register
#define ADCL				*((volatile u8*)0x24)		//ADC Low register	
#define ADC_DATA_RE 		*((volatile u16*)0x24)		//ADC Low + High	

/*Special FunctionIO Register*/
#define SFIOR               *((volatile u8*) 0x50)


#endif