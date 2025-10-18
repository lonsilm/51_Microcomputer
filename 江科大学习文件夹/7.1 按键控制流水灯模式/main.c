#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <intrins.h>

unsigned char keynumber;
char flag;

void main()
{
		P2=0xfe;
		Timer0_Init();
		while(1)
		{
			keynumber = Key();
			if(keynumber)
			{
				if(keynumber==1)
				{
					flag++;
					if(flag>=2)
					{
						flag=0;
					}
				}
				if(keynumber==2){P2_1=~P2_1;}
				if(keynumber==3){P2_2=~P2_2;}
				if(keynumber==4){P2_3=~P2_3;}
			}
		}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count=0;
	
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xfc;				//设置定时初始值
	//这里再赋初始值是因为如果第一次溢出之后
	//寄存器就会从零开始+1；时间就不是1ms了
	
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;

		if(flag==0)
		{
			P2=_crol_(P2,1);
		}
		if(flag==1)
		{
			P2=_cror_(P2,1);
		}
			

	}
}