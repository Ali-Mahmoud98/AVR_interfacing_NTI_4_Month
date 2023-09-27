/**
 * Author: Ali Mahmoud
 * Date: 27 Sep 2023
 * Description: Configuration file for SPI module
*/
#ifndef SPI_CONFIG_H 
#define SPI_CONFIG_H

/* Clock polarity */
#define CPOL_MODE    IDLE_LOW

/*Clock Phase*/
#define CPHA_MODE    SAMPLE_LEADING

/*SPI CLOCK Rate Select => prescaler*/
#define SPI_CLOCK   FOSC_DIV16

/*SPI DATA Order*/
#define DATA_ORDER      MSB_FIRST

#endif /*SPI_CONFIG_H*/