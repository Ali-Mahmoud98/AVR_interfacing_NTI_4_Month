#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


typedef struct
{
    u8 clock_select       : 3;
    u8 WGM01              : 1;
    u8 compare_match_mode : 2;
    u8 WGM00              : 1;
    u8 FOC0               : 1;
}TCCR0_t;

typedef struct
{
    u8 clock_select       : 3;
    u8 WGM01              : 1;
    u8 compare_match_mode : 2;
    u8 WGM00              : 1;
    u8 FOC0               : 1;
}TCCR2_t;

typedef struct
{
    u8 WGM                : 2;
    u8 FOC1B              : 1;
    u8 FOC1A              : 1;
    u8 COMP1B             : 2;
    u8 COMP1A             : 1;
}TCCR1A_t;

/************TIMER0 REGs*************/
/*Timer/Counter Control Register*/
#define TCCR0       ((volatile TCCR0_t *)  0x53)
#define TCCR2       ((volatile TCCR2_t *)  0x45)


#define TCCR1A      ((volatile TCCR1A_t*)  0x4F)
#define TCCR1B      (*(volatile u8*)        0x4E)

/*Timer/Counter Register*/
#define TCNT0       (*(((volatile u8 *)    0x52)))
#define TCNT2       (*(((volatile u8 *)    0x44)))

#define TCNT1H      ((volatile u8*)        0x4D)
#define TCNT1L      ((volatile u8*)        0x4C)

/*Output Compare Register*/
#define OCR0        (*(((volatile u8 *)    0x5C)))
#define OCR2        (*(((volatile u8 *)    0x43)))

#define OCR1AH      (*(((volatile u8 *)    0x4B)))
#define OCR1AL      (*(((volatile u8 *)    0x4A)))

#define OCR1BH      (*(((volatile u8 *)    0x49)))
#define OCR1BL      (*(((volatile u8 *)    0x48)))

#define ICR1H       (*(((volatile u8 *)    0x47)))
#define ICR1L       (*(((volatile u8 *)    0x46)))

/*Timer/Counter Interrupt Mask Register*/
#define TIMSK       (*(((volatile u8 *)    0x59)))
#define TOIE0       0
#define OCIE0       1
#define TOIE1       2
#define OCIE1B      3
#define OCIE1A      4
#define TICIE1      5
#define TOIE2       6
#define OCIE2       7

/*Timer/Counter Interrupt Flag Register*/
#define TIFR        (*(((volatile u8 *)    0x58)))
#define TOV0        0
#define OCF0        1
#define TOV1        2
#define OCF1B       3
#define OCF1A       4
#define ICF1        5
#define TOV2        6
#define OCF2        7

/*Special Function IO Register – SFIOR*/
#define SFIOR       (*(((volatile u8 *)    0x50)))
/************************************/
/*TIMER1 TCCR1B*/ 
#define WGM12   3
#define WGM13   4

#endif