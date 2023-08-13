
#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UDR_T            *((volatile u8 *)0x2C)
#define UDR_R            *((volatile u8 *)0x2C)
#define UCSRA            *((volatile u8 *)0x2B)
// UCSRA register bits
//USART Receive Complete bit
#define RXC	 7
// USART Transmit Complete bit
#define TXC	 6
// USART Data Register Empty bit
#define UDRE 5
// Frame Error bit
#define FE	 4
// Data OverRun bit
#define DOR	 3
// Parity Error bit
#define PE	 2
// Double the USART Transmission Speed bit
#define U2X	 1
// Multi-processor Communication Mode bit
#define MPCM 0

#define UCSRB            *((volatile u8 *)0x2A)
// UCSRB register bits
// Bit 7 – RXCIE: RX Complete Interrupt Enable
#define RXCIE	7
// Bit 6 – TXCIE: TX Complete Interrupt Enable
#define TXCIE	6
// Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable
#define UDRIE	5
// Bit 4 – RXEN: Receiver Enable
#define RXEN	4
// Bit 3 – TXEN: Transmitter Enable
#define TXEN	3
// Bit 2 – UCSZ2: Character Size
#define UCSZ2	2
// Bit 1 – RXB8: Receive Data Bit 8
#define RXB8	1
// Bit 0 – TXB8: Transmit Data Bit 8
#define TXB8	0

#define UCSRC            *((volatile u8 *)0x40)
// UCSRC register bits
// Bit 7 – URSEL: Register Select
#define URSEL 7
// Bit 6 – UMSEL: USART Mode Select
#define UMSEL 6
// Bit 5:4 – UPM1:0: Parity Mode
#define UPM1  5
#define UPM0  4
// Bit 3 – USBS: Stop Bit Select
#define USBS  3
// Bit 2:1 – UCSZ1:0: Character Size 
#define UCSZ1 2
#define UCSZ0 1
// Bit 0 – UCPOL: Clock Polarity
#define UCPOL 0


#define UBRRL            *((volatile u8 *)0x29)
#define UBRRH            *((volatile u8 *)0x40)

// URSEL: Register Select
#define UBRRH_URSEL	7

#endif /* UART_REGISTER_H_ */
