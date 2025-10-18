#include <REGX52.H>
#include "Delay.h"

sbit Buzzer=P2^5;
unsigned int i;

unsigned char Key()
{
	unsigned char KeyNumber = 0;
	
	if(P3_1==0)
	{Delayms(20);while(P3_1==0);Delayms(20);
		for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
			KeyNumber=1;
	}
	if(P3_0==0)
	{Delayms(20);while(P3_0==0);Delayms(20);
		for(i=0;i<50;i++)
			{
				Buzzer=!Buzzer;
				Delayms(2);
			}
			KeyNumber=2;}
	if(P3_2==0){Delayms(20);while(P3_2==0);Delayms(20);
		for(i=0;i<80;i++)
			{
				Buzzer=!Buzzer;
				Delayms(4);
			}
			KeyNumber=3;}
	if(P3_3==0){Delayms(20);while(P3_3==0);Delayms(20);
		for(i=0;i<40;i++)
			{
				Buzzer=!Buzzer;
				Delayms(5);
			}
			KeyNumber=4;}
	
	return KeyNumber;
}