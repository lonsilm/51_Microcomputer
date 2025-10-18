#include <REGX52.H>
#include "key.h"
#include "delay.h"
#include "timer0.h"
#include "smg.h"

sbit Motor = P1^0;


unsigned char Cont,Compere;
unsigned char keynum,speed;

void main()
{
	Timer0_Init100us();
	Compere=5;  //5%占空比
	while(1)
	{
		keynum=Key();
		if(keynum==1)
		{
			speed++;
			speed%=4;	
			if(speed==0)
			{
				Compere=0;
			}
			else if(speed==1)
			{
				Compere=40;
			}
			else if(speed==2)
			{
				Compere=69;
			}
			else
			{
				Compere=100;
			}
		}
		SMG(5,speed);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count=0;
	
	TL0 = 0xAE;				//设置定时初始值
	TH0 = 0xFB;				//设置定时初始值
	//这里再赋初始值是因为如果第一次溢出之后
	//寄存器就会从零开始+1；时间就不是100us了
	
	Cont++;

	Cont%=100;
	
	if(Cont<Compere)
	{
		Motor=1;
	}
	else
	{
		Motor=0;
	}

}