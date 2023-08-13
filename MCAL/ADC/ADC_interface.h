#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/************** ADC Auto Trigger Source Selections**************/
#define FREE_MODE_RUNNING       0
#define ANALOG_COMPARATOR       1
#define EXTINT_REQ0             2
#define TIMER0_COMPARE_MATCH    3
#define TIMER0_OVERFLOW         4
#define TIMER1_COMPARE_MATCHB   5
#define TIMER1_OVERFLOW         6 
#define TIMER1_CAPTURE_EVENT    7 
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
u16 ADC_readChannel(u8 channel_num);

/**
 * Enables automatic triggering for ADC conversions.
 */
void ADC_autoTrigger_Enable(void);

/**
 * Enables INTERRUPT for ADC conversions.
 */
void ADC_interrupt_ENABLE(void);

void ADC_setCallBack(void (*ptr2fun) (void));

void ADC_falg_clear(void);

#endif /* ADC_H_ */