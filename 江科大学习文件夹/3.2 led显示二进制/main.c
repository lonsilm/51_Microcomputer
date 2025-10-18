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
	unsigned char NUMled=0;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(100);
			
			NUMled++;
			P2=~NUMled;
			
			Delay(50);
		}
	}
}