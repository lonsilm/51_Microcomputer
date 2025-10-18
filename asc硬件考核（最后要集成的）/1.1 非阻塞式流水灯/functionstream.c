#include <REGX52.H>
#include "Timer0.h"

unsigned char stream_i=0;


/*
*@brief  非阻塞流水灯函数
*/
void led_stream()
{
    if(stream_i>=8)
    {
        stream_i=0;
    }
    P2=~(0x01<<stream_i);
    
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

		stream_i++;//每隔1秒流水灯移动一次

	}
}