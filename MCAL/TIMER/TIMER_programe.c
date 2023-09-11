#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"


#ifndef NULL
#define NULL    ((void *) 0)
#endif

/*****************TIMER0*******************/
void (*cmpMatchCallB_T0)(void) = NULL;
void (*overFlowCallB_T0)(void) = NULL;
/*****************TIMER1*******************/
void (*cmpMatchCallB_T1_1)(void) = NULL;
void (*cmpMatchCallB_T1_2)(void) = NULL;
void (*overFlowCallB_T1)(void) = NULL;
void (*cmpMatchCallB_T1_CEVENT)(void) = NULL;
/*****************TIMER2*******************/
void (*cmpMatchCallB_T2)(void) = NULL;
void (*overFlowCallB_T2)(void) = NULL;




/**************************Start TIMER0 FUNCTIONS***************************/
/**
 * Initializes Timer0.
 */
void timer0_void_init(void)
{
    /*init Timer MODES*/
    #if TIMER0_MODE == NORMAL
        TCCR0->WGM00 = 0;
        TCCR0->WGM01 = 0;
        TCCR0->FOC0 = 1;
        /*set output mode*/
        TCCR0->compare_match_mode = OUT_MODE_COMPARE;

    #elif TIMER0_MODE == PWM_PHASE_CORRECT
        TCCR0->WGM00 = 1;
        TCCR0->WGM01 = 0;
        /*set output mode*/
        TCCR0->FOC0 = 0;
        TCCR0->compare_match_mode = COMPARE_OUT_MODE_PWM;

    #elif TIMER0_MODE == CTC
        TCCR0->WGM00 = 0;
        TCCR0->WGM01 = 1;
        TCCR0->FOC0 = 1;
        /*set output mode*/
        TCCR0->compare_match_mode = OUT_MODE_COMPARE;

    #elif TIMER0_MODE == FAST_PWM
        TCCR0->WGM00 = 1;
        TCCR0->WGM01 = 1;
        TCCR0->FOC0 = 0;
        /*set output mode*/
        TCCR0->compare_match_mode = COMPARE_OUT_MODE_PWM;

    #endif
    TCCR0->clock_select = CLOCK_SELECT;
}

/**
 * Sets the preload value for Timer0 with a specified compare match mode.
 *
 * @param CompMatch The compare match mode (0 or 1) to set the preload value for.
 * @param Preload_Value The value to preload into Timer0.
 */
void TIMER0_voidSetPreload (u8 CompMatch __attribute__((unused)) ,u8 Preload_Value)
{
    #if COMPARE_OUT_MODE_PWM != NORMAL_PORT_OPERATION
	    OCR0 = CompMatch;
    #endif
	TCNT0 = Preload_Value;
}

/**
 * Turns off Timer0.
 */
void timer0_void_off(void)
{
    TCCR0->clock_select = 0;
}
/**
 * Turns off Timer0.
 */
void Timer0_set_preLoadVal(u8 val)
{
    TCNT0 = val;
}
/**
 * Enables Timer0 overflow interrupts.
 */
void timer0_Interrupt_OverFlow_Enable(void)
{
    SET_BIT(TIMSK, TOIE0);
}

/**
 * Enables Timer0 compare match interrupts.
 */
void timer0_Interrupt_CompMatch_Enable(void)
{
    SET_BIT(TIMSK, OCIE0);
}
/**
 * Disable Timer0 overflow interrupts.
 */
void timer0_Interrupt_OverFlow_Disable(void)
{
    CLR_BIT(TIMSK, TOIE0);
}

/**
 * Disable Timer0 compare match interrupts.
 */
void timer0_Interrupt_CompMatch_Disable(void)
{
    CLR_BIT(TIMSK, OCIE0);
}
/**
 * Sets the value of OCR0 (Output Compare Register) in Timer0.
 *
 * @param ocr0Val The value to be set in OCR0.
 */
void set_OCR0Val(u8 ocr0Val)
{
    OCR0 = ocr0Val;
}
/**
 * Clears Timer0 interrupt flags.
 */
void timer0_Interrupt_FlagClear(void)
{
    SET_BIT(TIFR, TOV0);
}
/**
 * Clears Timer0 compare match interrupt flag.
 */
void timer0_Interrupt_CompMatch_FlagClear(void)
{
    SET_BIT(TIFR, OCF0);
}

void TIMER0_voidPWM (u8 Duty_Cycle)
{
    #if COMPARE_OUT_MODE_PWM == SET_OC0
	OCR0 = (u8)(255 - ( ((f32) Duty_Cycle / 100) * 255));
	#elif COMPARE_OUT_MODE_PWM == CLEAR_OC0
	OCR0 = (u8)(((f32) Duty_Cycle / 100) * 256);
    #endif
}

/**************************END TIMER0 FUNCtions******************************************/

//-------------------------------------------------------------------------------------------------
/*****************************************************************************/
/*****************************************************************************/
/**************************START TIMER1 FUNCtions***************************/

/**
 * Initializes Timer1 with specified waveform generation mode, compare match mode, and prescaler.
 *
 * @param WFGM_MODE Waveform generation mode for Timer1.
 * @param CMP_MODE Compare match mode for Timer1.
 * @param PRESCALER Prescaler value for Timer1.
 */
void init_void_timer1(u8 WFGM_MODE, u8 CMP_MODE, u8 PRESCALER)
{
    switch (WFGM_MODE)
    {
    case NORMAL_M:
        TCCR1A->WGM = 0;
        CLR_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        TCCR1A->COMP1A = NORMAL_OP;
        TCCR1A->COMP1B = NORMAL_OP;
        break;
    default:
        break;
    }
    switch (PRESCALER)
    {
    case NO_CLOCK:
        CLR_BIT(TCCR1B, 0);
        CLR_BIT(TCCR1B, 1);
        CLR_BIT(TCCR1B, 2);
        break;
    case CLOCK_1:
        SET_BIT(TCCR1B, 0);
        CLR_BIT(TCCR1B, 1);
        CLR_BIT(TCCR1B, 2);
        break;
    case CLOCK_8:
        CLR_BIT(TCCR1B, 0);
        SET_BIT(TCCR1B, 1);
        CLR_BIT(TCCR1B, 2);
        break;
    case CLOCK_64:
        SET_BIT(TCCR1B, 0);
        SET_BIT(TCCR1B, 1);
        CLR_BIT(TCCR1B, 2);
        break;
    case CLOCK_256:
        CLR_BIT(TCCR1B, 0);
        CLR_BIT(TCCR1B, 1);
        SET_BIT(TCCR1B, 2);
        break;
    case CLOCK_1024:
        SET_BIT(TCCR1B, 0);
        CLR_BIT(TCCR1B, 1);
        SET_BIT(TCCR1B, 2);
        break;
    case CLOCK_EXT_FALLING:
        CLR_BIT(TCCR1B, 0);
        SET_BIT(TCCR1B, 1);
        SET_BIT(TCCR1B, 2);
        break;
    case CLOCK_EXT_RISING:
        SET_BIT(TCCR1B, 0);
        SET_BIT(TCCR1B, 1);
        SET_BIT(TCCR1B, 2);
        break;
    
    default:
        break;
    }
}
 
void timer1_interrupt_ENABLE(void)
{
    SET_BIT(TIMSK ,TOIE1);
}

void timer1_CMPA_Inerrupt_EN(void)
{
    SET_BIT(TIMSK, OCF1A);
}

void timer1_CMPB_Inerrupt_EN(void)
{
    SET_BIT(TIMSK, OCF1B);
}
/**************************END TIMER1 FUNCtions***************************/
/*****************************************************************************/
/*****************************************************************************/


//-------------------------------------------------------------------------------------------------
/*****************************************************************************/
/*****************************************************************************/
/**************************START TIMER2 FUNCtions***************************/


/**************************END TIMER2 FUNCtions***************************/
//-------------------------------------------------------------------------------------------------



/*************START SET CALLBACK FUNCTIONs************/

/*********************TIMER0**************************/
/**
 * Sets a callback function for Timer0 overflow interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer0 overflow interrupt.
 */
void setCallBack_OV_T0(void (*ptr2fun)(void))
{
    overFlowCallB_T0 = ptr2fun;
}
/**
 * Sets a callback function for Timer0 compare match interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer0 compare match interrupt.
 */
void setCallBack_CMP_T0(void (*ptr2fun)(void))
{
    cmpMatchCallB_T0 = ptr2fun;
}
/********************TIMER1***************************/
/**
 * Sets a callback function for Timer1 compare match A interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer1 compare match A interrupt.
 */
void setCallBack_CEVENT_T1(void (*ptr2fun)(void))
{
    cmpMatchCallB_T1_CEVENT = ptr2fun;
}
/**
 * Sets a callback function for Timer1 compare match A interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer1 compare match A interrupt.
 */
void setCallBack_CMPA_T1(void (*ptr2fun)(void))
{
    cmpMatchCallB_T1_1 = ptr2fun;
}
/**
 * Sets a callback function for Timer1 compare match B interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer1 compare match B interrupt.
 */
void setCallBack_CMPB_T1(void (*ptr2fun)(void))
{
    cmpMatchCallB_T1_2 = ptr2fun;
}
/**
 * Sets a callback function for Timer1 overflow interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer1 output compare interrupt.
 */
void setCallBack_OV_T1(void (*ptr2fun)(void))
{
    overFlowCallB_T1 = ptr2fun;
}
/********************TIMER1***************************/
/**
 * Sets a callback function for Timer2 overflow interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer2 overflow interrupt.
 */
void setCallBack_OV_T2(void (*ptr2fun)(void))
{
    overFlowCallB_T2 = ptr2fun;
}
/**
 * Sets a callback function for Timer2 compare match interrupt.
 *
 * @param ptr2fun Pointer to the function to be called on Timer2 compare match interrupt.
 */
void setCallBack_CMP_T2(void (*ptr2fun)(void))
{
    cmpMatchCallB_T2 = ptr2fun;
}
/***************END SET CALLBACK FUNCTIONs************/


/*********INTERRUPT SIGNAL HANDLERs**********/
/*****************TIMER2*******************/
/*Timer/Counter2 Compare Match*/
void __vector_4(void)  __attribute__((signal));
void __vector_4(void)
{
	cmpMatchCallB_T2();
}
/*Timer/Counter2 Overflow*/
void __vector_5(void)  __attribute__((signal));
void __vector_5(void)
{
	overFlowCallB_T2();
}
/*****************TIMER2*******************/


/*****************TIMER1*******************/
/*Timer/Counter1 Capture Event*/
void __vector_6(void)  __attribute__((signal));
void __vector_6(void)
{
	cmpMatchCallB_T1_CEVENT();
}
/*Timer/Counter1 Compare MatchA*/
void __vector_7(void)  __attribute__((signal));
void __vector_7(void)
{
	cmpMatchCallB_T1_1();
}
/*Timer/Counter1 Compare MatchB*/
void __vector_8(void)  __attribute__((signal));
void __vector_8(void)
{
	cmpMatchCallB_T1_2();
}
/*Timer/Counter1 Overflow*/
void __vector_9(void)  __attribute__((signal));
void __vector_9(void)
{
    overFlowCallB_T1();
}
/*****************END TIMER1*******************/

/*****************TIMER0*******************/
/*Timer/Counter0 Compare Match*/
void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
	cmpMatchCallB_T0();
    //SET_BIT(TIFR, OCF0);
}
/*Timer/Counter0 Overflow*/
void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{
	overFlowCallB_T0();
    // SET_BIT(TIFR, TOV0);
}
/*****************END TIMER0*******************/