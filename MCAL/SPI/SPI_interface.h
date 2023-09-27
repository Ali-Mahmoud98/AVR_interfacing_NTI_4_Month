/**
 * Author: Ali Mahmoud
 * Date: 27 Sep 2023
 * Description: Interface file for SPI module
*/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/* CLOCK Polarity*/
#define IDLE_LOW  0
#define IDLE_HIGH 1

/**
 * Clock phase:
 * identifies send (setup) on leading and recieve (sample) on 
 * trailing edge or vise versa.
 */
#define SAMPLE_LEADING     0
#define SAMPLE_TRAILLING   1

/* SPI CLOCK Rate Select => prescaler*/
#define FOSC_DIV2           0
#define FOSC_DIV4           1
#define FOSC_DIV8           2
#define FOSC_DIV16          3
#define FOSC_DIV32          4
#define FOSC_DIV64_1        5    
#define FOSC_DIV64_2        6    /*Double speed*/
#define FOSC_DIV128         7      

/*SPI DATA Order*/
#define MSB_FIRST       0
#define LSB_FISRT       1


void SPI_MasterInit(void);
void SPI_SlaveInit(void);

u8 SPI_trancieverSync(u8 data);


#endif