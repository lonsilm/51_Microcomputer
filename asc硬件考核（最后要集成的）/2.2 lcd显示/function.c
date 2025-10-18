#include <REGX52.H>
#include "lcd1602.h"

void lcd_display()
{
        LCD_ShowString(1, 1, "Hello, World!");
        LCD_ShowString(2, 1, "I LOVE ASC!!");
}