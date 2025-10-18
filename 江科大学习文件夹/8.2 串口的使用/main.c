#include <REGX52.H>
#include "delay.h"
#include "UART.h"
#include "smg.h"
#include "lcd1602.h"

void main()
{
	Uart1_Init();
	LCD_Init();
	while(1)
	{
		UART_sendBYTE('s');
		Delay(1);
	}
}