#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer.h"

void main()
{
    LCD_Init();
    while(1)
    {
        Timer_view();
    }
}