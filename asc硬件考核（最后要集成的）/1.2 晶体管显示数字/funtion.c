#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "smg.h"
#include "Clean.h"

unsigned char hh,mm,ss;

void smg_display_time()
{
    Timer0_Init();//初始化定时器0
        if(ss>=60)
        {
            ss=0;
            mm++;
            if(mm>=60)
            {
                mm=0;
                hh++;
                if(hh>=24)
                {
                    hh=0;
                }
            }
        }
    SMG(1,hh/10);
    SMG(2,hh%10);
    SMG(4,mm/10);
    SMG(5,mm%10);
    SMG(7,ss/10);
    SMG(8,ss%10);
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count=0;
	
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xfc;				//设置定时初始值
	//这里再赋初始值是因为如果第一次溢出之后
	//寄存器就会从零开始+1；时间就不是1ms了
	
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;

		ss++;//每隔1秒钟，秒数加1
        

	}
}