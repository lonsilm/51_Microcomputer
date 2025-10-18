#include <REGX52.H>

unsigned int i,j;
void delay(unsigned int t)
{
	while(t--);
}

void main()
{
	while(1)
	{
		for(i=0;i<100;i++)
		{
			for(j=0;j<20;j++)
			{
				P2=0xff;
			delay(100-i);
			P2=0x00;
			delay(i);
			}
		}
		for(i=0;i<100;i++)
		{
			for(j=0;j<40;j++)
			{
				P2=0x00;
			delay(100-i);
			P2=0xff;
			delay(i);
			}
		}
		
	}
}
