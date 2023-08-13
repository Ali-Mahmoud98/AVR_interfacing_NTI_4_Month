#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/**
 * TIMER0 MODES
 * 1- NORMAL
 * 2- PWM Phase correct
 * 3- CTC
 * 4- Fast PWM
*/
#define TIMER0_MODE  FAST_PWM

/*Compare match output mode for timer0*/
/**
 * non-PWM
 * OUT_MODE_COMPARE:
 * 1- NORMAL port operation
 * 2- Toggle OC0 on compare match
 * 3- Clear OC0 on compare match
 * 4- Set OC0 on compare match
*/
#define OUT_MODE_COMPARE  NORMAL_PORT_OPERATION

/*Compare Output Mode, Fast PWM Mode TIMER0*/
/**
 * COMPARE_OUT_MODE_FPWM
 * 1- Normal port operation, OC0 disconnected.
 * 2- Reserved.
 * 3- Clear OC0 on compare match, set OC0 at TOP
 * 4- Set OC0 on compare match, clear OC0 at TOP
 */
#define COMPARE_OUT_MODE_PWM  NORMAL_PORT_OPERATION

/**
 * Clock Select
 * 1- No clock source (Timer/Counter stopped).
 * 2- clk (No prescaling).
 * 3- clk/8 (From prescaler).
 * 4- clk/64 (From prescaler).
 * 5- clk/256 (From prescaler).
 * 6- clk/1024 (From prescaler).
 * 7- External clock source on T0 pin. Clock on falling edge
 * 8- External clock source on T0 pin. Clock on rising edge
*/
#define CLOCK_SELECT    CLOCK_1024

#endif