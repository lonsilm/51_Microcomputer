#include <REGX52.H>


void Timer0_Init(void)		//1毫秒@12.000MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xfc;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;
	ET0 = 1;
	EA = 1;
	PT0 = 0;				//定时器0开始计时
}



//中断执行函数的模板
//每隔1s

/*
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

		这里写你需要执行的程序

	}
}
*/