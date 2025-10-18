#include <REGX52.H>
#include "Delay.h"

sbit Buzzer=P2^5;
unsigned int i;

unsigned char Key()
{
	unsigned char KeyNumber = 0;
	
	if(P3_1==0)
	{Delay(20);while(P3_1==0);Delay(20);
		// for(i=0;i<100;i++)
		// 	{
		// 		Buzzer=!Buzzer;
		// 		Delay(1);
		// 	}
			KeyNumber=1;
	}
	if(P3_0==0)
	{Delay(20);while(P3_0==0);Delay(20);
		for(i=0;i<50;i++)
			{
				Buzzer=!Buzzer;
				Delay(2);
			}
			KeyNumber=2;}
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);
		for(i=0;i<25;i++)
			{
				Buzzer=!Buzzer;
				Delay(4);
			}
			KeyNumber=3;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);
		for(i=0;i<20;i++)
			{
				Buzzer=!Buzzer;
				Delay(5);
			}
			KeyNumber=4;}
	
	return KeyNumber;
}