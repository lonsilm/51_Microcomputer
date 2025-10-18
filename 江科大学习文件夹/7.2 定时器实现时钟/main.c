#include <REGX52.H>
#include "key.h"
#include "lcd1602.h"
#include "Timer0.h"
#include "delay.h"

unsigned char sec,min,hour;

void main()
{
    LCD_Init();
    Timer0_Init();
    LCD_ShowString(1,1,"COLCK:");
		LCD_ShowString(2,1,"  :  :  ");
    while(1)
    {
		LCD_ShowNum(2,1,hour,2);

        LCD_ShowNum(2,4,min,2);

        LCD_ShowNum(2,7,sec,2);
    }
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count=0;
	
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xDfc;				//设置定时初始值
	//这里再赋初始值是因为如果第一次溢出之后
	//寄存器就会从零开始+1；时间就不是1ms了
	
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;

		sec++;
		if(sec>=60)
        {
            sec=0;
            min++;
            if(min>=60)
            {
                min=0;
                hour++;
                if(hour>=24)
                {
                    hour=0;
                }
            }
        }

	}
}