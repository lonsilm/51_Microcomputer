#ifndef __UART_H__
#define __UART_H__

void Uart1_Init(void);
void UART_sendBYTE(unsigned char Byte);
void UART_sendSTRING(unsigned char *Str);

#endif