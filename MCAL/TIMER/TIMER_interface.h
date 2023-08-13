#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/*TIMER0 MODES*/
#define NORMAL              1
#define PWM_PHASE_CORRECT   2
#define CTC                 3
#define FAST_PWM            4

/*TIMER1 MODES*/
#define NORMAL_M                0
#define PWM_PHASE_CORRECT_8   1
#define PWM_PHASE_CORRECT_9   2
#define PWM_PHASE_CORRECT_10  3
#define CTC_M                   4
#define FAST_PWM_8            5
#define FAST_PWM_9            6
#define FAST_PWM_10           7
#define PWM_PH_F_CORR_ICR1      8
#define PWM_PH_F_CORR_OCR1A     9
#define PWM_PHASE_CORRECT_ICR1  10
#define PWM_PHASE_CORRECT_OCR1A 11
#define CTC_ICR1                12
#define FAST_PWM_ICR1           14
#define FAST_PWM_OCR1A          15

/*TIMER0 Compare Output Mode, non-PWM Mode*/
#define NORMAL_PORT_OPERATION   0
#define TOGGLE_OC0              1
#define CLEAR_OC0               2
#define SET_OC0                 3

/*TIMER0 Compare Output Mode, fast PWM Mode*/
#define NORMAL_PORT_OPERATION   0
#define CLEAR_OC0               2
#define SET_OC0                 3

/*TIMER1 Compare Output Mode, non-PWM*/
#define NORMAL_OP               0 
#define TOGGLE_ON_CMP           1 
#define NORMAL_CLR_ON_CMP       2
#define NORMAL_SET_ON_CMP       3 

/*Clock Select TIMER0*/
#define NO_CLOCK                0
#define CLOCK_1                 1
#define CLOCK_8                 2
#define CLOCK_64                3
#define CLOCK_256               4
#define CLOCK_1024              5
#define CLOCK_EXT_FALLING       6
#define CLOCK_EXT_RISING        7


/**
 * Initializes Timer0.
 */
void timer0_void_init(void);

/**
 * Sets the preload value for Timer0 with a specified compare match mode.
 *
 * @param CompMatch The compare match mode (0 or 1) to set the preload value for.
 * @param Preload_Value The value to preload into Timer0.
 */
void TIMER0_voidSetPreload(u8 CompMatch, u8 Preload_Value);

/**
 * Turns off Timer0.
 */
void timer0_void_off(void);

/**
 * Enables Timer0 overflow interrupts.
 */
void timer0_Interrupt_OverFlow_Enable(void);

/**
 * Enables Timer0 compare match interrupts.
 */
void timer0_Interrupt_CompMatch_Enable(void);

/**
 * Disable Timer0 overflow interrupts.
 */
void timer0_Interrupt_OverFlow_Disable(void);

/**
 * Disable Timer0 compare match interrupts.
 */
void timer0_Interrupt_CompMatch_Disable(void);

/**
 * Sets the value of OCR0 (Output Compare Register) in Timer0.
 *
 * @param ocr0Val The value to be set in OCR0.
 */
void set_OCR0Val(u8 ocr0Val);

/**
 * Clears Timer0 interrupt flags.
 */
void timer0_Interrupt_FlagClear(void);

/**
 * Clears Timer0 compare match interrupt flag.
 */
void timer0_Interrupt_CompMatch_FlagClear(void);

/**
 * Sets a callback function for Timer0 overflow interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer0 overflow interrupt.
 */
void setCallBack_OV_T0(void (*ptr2fun)(void));

/**
 * Sets a callback function for Timer0 compare match interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer0 compare match interrupt.
 */
void setCallBack_CMP_T0(void (*ptr2fun)(void));

/**
 * Sets a callback function for Timer1 compare match A interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer1 compare match A interrupt.
 */
void setCallBack_CMPA_T1(void (*ptr2fun)(void));

/**
 * Sets a callback function for Timer1 compare match B interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer1 compare match B interrupt.
 */
void setCallBack_CMPB_T1(void (*ptr2fun)(void));

/**
 * Sets a callback function for Timer1 output compare interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer1 output compare interrupt.
 */
void setCallBack_OV_T1(void (*ptr2fun)(void));

/**
 * Sets a callback function for Timer2 overflow interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer2 overflow interrupt.
 */
void setCallBack_OV_T2(void (*ptr2fun)(void));

/**
 * Sets a callback function for Timer2 compare match interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer2 compare match interrupt.
 */
void setCallBack_CMP_T2(void (*ptr2fun)(void));

/**
 * Generates PWM signal using Timer0 with a specified duty cycle.
 *
 * @param Duty_Cycle The duty cycle value for the PWM signal (0 to 255).
 */
void TIMER0_voidPWM (u8 Duty_Cycle);

/**
 * Initializes Timer1 with specified waveform generation mode, compare match mode, and prescaler.
 *
 * @param WFGM_MODE Waveform generation mode for Timer1.
 * @param CMP_MODE Compare match mode for Timer1.
 * @param PRESCALER Prescaler value for Timer1.
 */
void init_void_timer1(u8 WFGM_MODE, u8 CMP_MODE, u8 PRESCALER);

void timer1_interrupt_ENABLE(void);

void timer1_CMPA_Inerrupt_EN(void);

void timer1_CMPB_Inerrupt_EN(void);

#endif