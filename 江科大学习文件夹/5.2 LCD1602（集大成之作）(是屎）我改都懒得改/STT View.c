#include <REGX52.H>
#include "LCD1602.h"

void stt_display1()
{
    LCD_ShowString(1,1,"                ");
    LCD_ShowString(2,1,"                ");
    while(1)
    {
        LCD_ShowString(1,1,"-> Timer");
        LCD_ShowString(2,1,"   Birthday");
    }
}
void stt_display2()
{
    LCD_ShowString(1,1,"                ");
    LCD_ShowString(2,1,"                ");    
    while(1)
    {
        LCD_ShowString(1,1,"   Timer");
        LCD_ShowString(2,1,"-> Birthday");
    }
}