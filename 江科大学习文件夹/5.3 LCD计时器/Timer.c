#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"

void Timer_view()
{
    int sec = 0;
    int min = 0;
    int hr = 0;
	LCD_ShowString(1, 1, "Timer:");
	Delay(10);//延时10s
    while(1)
    {
        Delay(1000); // 延时1秒
        if(sec < 59)
            sec++;
        else
        {
            sec = 0;
            if(min < 59)
                min++;
            else
            {
                min = 0;
                if(hr < 23)
                    hr++;
                else
                    hr = 0;
            }
        }
        // 显示时间
   
    LCD_ShowNum(2, 3, hr, 2);
    LCD_ShowString(2, 5, ":");
    LCD_ShowNum(2, 6, min, 2);
    LCD_ShowString(2, 8, ":");
    LCD_ShowNum(2, 9, sec, 2);
    }
}