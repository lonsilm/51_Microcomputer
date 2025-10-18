#include <REGX52.H>
#include <intrins.h>

void Delay(int xms)	//@12.000MHz
{
	unsigned char data i, j;
	while(xms){
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main()
{
	char NUM=0;
	P2=0xfe;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			NUM++;
			if(NUM>7)
				NUM=0;
			P2=~(0x01<<NUM);
		}
		
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			
			NUM--;
			if(NUM<0)
				NUM=7;
			P2=~(0x01<<NUM);
		}
	}
}