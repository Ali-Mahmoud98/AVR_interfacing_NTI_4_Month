#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_register.h"

#define F_CPU 8000000UL
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)	

//static UART_u8ReceivedFlag=0;
//static UART_u8TransmitFlag=0;

void UART_voidInit(void)
{
	/* PUT SOME CODE HERE */
  // Set BaudRate -> 9600 or whatever
  UBRRL = BAUD_PRESCALE;		/* Load lower 8-bits of the baud rate value */
	UBRRH = (BAUD_PRESCALE >> 8);	/* Load upper 8-bits*/
  // Set Frame Format -> 8 data, 1 stop, No Parity or what ever
  UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
  // Enable Sending and Recieving by Enabling RXE and TXE bits in USCRB register
  UCSRB = (1 << RXEN) | (1 << TXEN);
}

void UART_voidSendChar(u8 data)
{
  // wait for the trasmitting flag (UDRE bit in UCSRA register)
  while (! (UCSRA & (1<<UDRE)));
	//send data
  UDR_T = data;
}

u8 UART_voidGetChar(void)
{
  u8 data;
  // wait for the receiving flag (RXC bit in UCSRA register)
  while ((UCSRA & (1 << RXC)) == 0);/* Wait till data is received */
  //read data
	data = UDR_R;

  return data;
  
}

void UART_voidGetString(u8* str)
{
	while (UART_voidGetChar() != '\0'){}
}

void UART_voidSendString(const u8* str)
{
  u8 j=0;
	while (str[j] != '\0')
	{
		UART_voidSendChar(str[j]);	
		j++;
	}
}

/*
UART ISRs
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	//UART_u8ReceivedFlag=1;
}


void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	//UART_u8TransmitFlag=1;
}
*/