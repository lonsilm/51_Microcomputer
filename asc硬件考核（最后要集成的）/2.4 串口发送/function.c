#include <REGX52.H>
#include "Delay.h"
#include "key.h"
#include "uart.h"

void uartuser()
{
    unsigned char keynum = 0;
    Uart1_Init();
    
    keynum = Key();
    if(keynum == 3)
    {
        UART_sendSTRING("Passionate about technology willing to contribute\r\n");
    }
    else if(keynum == 4)
    {
        UART_sendSTRING("adventure success cooperation\r\n");
    }
}