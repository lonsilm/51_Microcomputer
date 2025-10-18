#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"

void Timer_view(int flag)
{
    int sec = 0;
    int min = 0;
    int hr = 0;

    LCD_ShowString(1,1,"                ");
    LCD_ShowString(2,1,"                ");
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
        LCD_ShowNum(2, 4, hr, 2);
        LCD_ShowString(2, 5, ":"); 
        LCD_ShowNum(2, 7, min, 2);
        LCD_ShowString(2, 8, ":");
        LCD_ShowNum(2, 9, sec, 2);
        if(flag == 0) // 检测到返回主界面标志
        {
            flag = 0; // 重置标志
            break;
        }
    }
}

void Timer_InitView()
{
    LCD_ShowString(1,1,"                ");
    LCD_ShowString(2,1,"                ");
    while(1)
    {
        LCD_ShowString(1, 1, "   Timer   ");
        LCD_ShowString(2, 1, "  00:00:00 ");
    }
}