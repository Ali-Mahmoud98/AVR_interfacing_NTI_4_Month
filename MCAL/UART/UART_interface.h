#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_voidInit(void);

void UART_voidSendChar(u8 data);

u8 UART_voidGetChar(void);

void UART_voidGetString(u8* str);
void UART_voidSendString(const u8* str);

#endif /* UART_INTERFACE_H_ */
