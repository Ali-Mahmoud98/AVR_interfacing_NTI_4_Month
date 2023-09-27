/**
 * Author: Ali Mahmoud
 * Date: 27 Sep 2023
 * Description: Private file for SPI module
*/
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPCR_REG       (*((volatile u8* )0x2D))
#define SPSR_REG       (*((volatile u8* )0x2E))
/* SPI Data Register – SPDR */
#define SPDR_REG       (*((volatile u8* )0x2F))

/* SPI Control Register – SPCR */
/*SPIE: SPI Interrupt Enable*/
#define SPIE    7
/*SPE: SPI Enable*/
#define SPE     6
/*DORD: Data Order*/
#define DORD    5
/*MSTR: Master/Slave Select*/
#define MSTR    4
/*CPOL: Clock Polarity*/
#define CPOL    3
/*CPHA: Clock Phase*/
#define CPHA    2
/*SPR: SPI Clock Rate Select*/
#define SPR0    0
#define SPR1    1

/*SPI Status Register – SPSR*/
/*SPIF: SPI Interrupt Flag*/
#define SPIF    7
/*WCOL: Write COLlision Flag*/
#define WCOL    6
/* bits 5-1 reserved */
/*SPI2X: Double SPI Speed Bit*/
#define SPI2X   0


#endif