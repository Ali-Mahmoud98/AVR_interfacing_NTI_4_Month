/**
 * SPI_program.c
 * 
 * Author: Ali Mahmoud
 * Date: 27 Sep 2023
*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"


static void (*SPI_ApfuncINT)(void);

void SPI_MasterInit(void)
{
    /*clock polarity*/
    ASS_BIT(SPCR_REG, CPOL, CPOL_MODE);
    /*clock phase*/
    ASS_BIT(SPCR_REG, CPHA, CPHA_MODE);
    /*SPI CLOCK*/
    #if SPI_CLOCK == FOSC_DIV2
        CLR_BIT(SPCR_REG, SPR0);
        CLR_BIT(SPCR_REG, SPR1);
        SET_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV4
        CLR_BIT(SPCR_REG, SPR0);
        CLR_BIT(SPCR_REG, SPR1);
        CLR_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV8
        SET_BIT(SPCR_REG, SPR0);
        CLR_BIT(SPCR_REG, SPR1);
        SET_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV16
        SET_BIT(SPCR_REG ,SPR0);
        CLR_BIT(SPCR_REG, SPR1);
        CLR_BIT(SPSR_REG ,SPI2X);
    #elif SPI_CLOCK == FOSC_DIV32
        CLR_BIT(SPCR_REG, SPR0);
        SET_BIT(SPCR_REG, SPR1);
        SET_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV64_1
        CLR_BIT(SPCR_REG, SPR0);
        SET_BIT(SPCR_REG, SPR1);
        CLR_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV64_2
        SET_BIT(SPCR_REG, SPR0);
        SET_BIT(SPCR_REG, SPR1);
        SET_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV128
        SET_BIT(SPCR_REG, SPR0);
        SET_BIT(SPCR_REG, SPR1);
        CLR_BIT(SPSR_REG, SPI2X);
    #endif
    /*SPI DATA ORDER*/
    ASS_BIT(SPCR_REG, DORD, DATA_ORDER);

    /*SPI MASRTER MODE*/
    SET_BIT(SPCR_REG, MSTR);

    /*SPI Enable*/
    SET_BIT(SPCR_REG, SPE);
}
void SPI_SlaveInit(void)
{
        /*clock polarity*/
    ASS_BIT(SPCR_REG, CPOL, CPOL_MODE);
    /*clock phase*/
    ASS_BIT(SPCR_REG, CPHA, CPHA_MODE);
    /*SPI CLOCK*/
    #if SPI_CLOCK == FOSC_DIV2
        CLR_BIT(SPCR_REG, SPR0);
        CLR_BIT(SPCR_REG, SPR1);
        SET_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV4
        CLR_BIT(SPCR_REG, SPR0);
        CLR_BIT(SPCR_REG, SPR1);
        CLR_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV8
        SET_BIT(SPCR_REG, SPR0);
        CLR_BIT(SPCR_REG, SPR1);
        SET_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV16
        SET_BIT(SPCR_REG ,SPR0);
        CLR_BIT(SPCR_REG, SPR1);
        CLR_BIT(SPSR_REG ,SPI2X);
    #elif SPI_CLOCK == FOSC_DIV32
        CLR_BIT(SPCR_REG, SPR0);
        SET_BIT(SPCR_REG, SPR1);
        SET_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV64_1
        CLR_BIT(SPCR_REG, SPR0);
        SET_BIT(SPCR_REG, SPR1);
        CLR_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV64_2
        SET_BIT(SPCR_REG, SPR0);
        SET_BIT(SPCR_REG, SPR1);
        SET_BIT(SPSR_REG, SPI2X);
    #elif SPI_CLOCK == FOSC_DIV128
        SET_BIT(SPCR_REG, SPR0);
        SET_BIT(SPCR_REG, SPR1);
        CLR_BIT(SPSR_REG, SPI2X);
    #endif
    /*SPI DATA ORDER*/
    ASS_BIT(SPCR_REG, DORD, DATA_ORDER);

    /*SPI SLAVE MODE*/
    CLR_BIT(SPCR_REG, MSTR);

    /*SPI Enable*/
    SET_BIT(SPCR_REG, SPE);
}

u8 SPI_trancieverSync(u8 data)
{
    SET_REG_VAL(SPDR_REG, data);
    /*Wait until the transmission is finished polling */
    while (GET_BIT(SPSR_REG, SPIF) == 0){}
    return SPDR_REG;
}

void SPI_interrupt_Enable(void)
{
    SET_BIT(SPCR_REG, SPIE);
}

void SPI_voidSetCallBack(void(*Copy_pfun)(void))
{
	SPI_ApfuncINT = Copy_pfun;
}

void __vector_12 (void)	__attribute__((signal)) ;
void __vector_12 (void)
{
    if (SPI_ApfuncINT != NULL)
    {
        SPI_ApfuncINT();
    }
    else
    {
    }
}