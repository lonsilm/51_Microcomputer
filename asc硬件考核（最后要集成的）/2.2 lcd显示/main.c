#include <REGX52.H>
#include "lcd1602.h"
#include "function.h"

void main()
{
    LCD_Init();
    while(1)
    {
        lcd_display();
    }
}