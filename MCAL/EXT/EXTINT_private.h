
#ifndef EXTINT_PRIVATE_H_
#define EXTINT_PRIVATE_H_

/*REGISTERS*/
#define MCUCR   *((volatile u8 *)0x55)
#define MCUCSR  *((volatile u8 *)0x54)
#define GICR    *((volatile u8 *)0x5B)
#define GIFR    *((volatile u8 *)0x5A)

/* MCUCR PINS */

#define MCUCR_ISC11        3
#define MCUCR_ISC10        2
#define MCUCR_ISC01        1
#define MCUCR_ISC00        0

/* MCUCSR */
#define MCUCSR_ISC2        6

/* GICR */
#define GICR_INT1          7
#define GICR_INT0          6
#define GICR_INT2          5


#endif /* EXTINT_PRIVATE_H_ */
