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


//void Delay100ms(void)	//@12.000MHz
//{
//	unsigned char data i, j;

//	i = 195;
//	j = 138;
//	do
//	{
//		while (--j);
//	} while (--i);
//}


//void Delay1000ms(void)	//@12.000MHz
//{
//	unsigned char data i, j, k;

//	_nop_();
//	i = 8;
//	j = 154;
//	k = 122;
//	do
//	{
//		do
//		{
//			while (--k);
//		} while (--j);
//	} while (--i);
//}

void main()
{
//	P2=0xfe; //1111 1110
	P2=0x00;
	Delay(1000);
	while(1)
	{
		if(P3_1==0){
			Delay(20);
			
//				Delay1000ms();
//				P2= 0xFE; //1111 1110
//				Delay100ms();
//				P2= 0xFD; //1111 1101
//				Delay100ms();
//				P2= 0xFB; //1111 1011
//				Delay100ms();
//				P2= 0xF7; //1111 0111
//				Delay100ms();
//				P2= 0xef; //1110 1111
//				Delay100ms();
//				P2= 0xdf; //1101 1111
//				Delay100ms();
//				P2= 0xbf; //1011 1111
//				Delay100ms();
//				P2= 0x7f; //0111 1111
			{	 
					int i=0;
					for( i=0;i<8;i++)
					{
						P2=~(1 << i);
						Delay(70);
					}
			}
//				Delay100ms();
//				P2= 0x00; //0000 0000
//				Delay1000ms();
//				P2= 0x18; //0001 1000
//				Delay100ms();
//				P2= 0x3c; //0011 1100
//				Delay100ms();
//				P2= 0x7e; //0111 1110
//				Delay100ms();
//				P2= 0xFF; //1111 1111
			{
				int i=0;
				int j=4;
				
				for(i=3,j=4;i>=0,j<8;j++,i--)
				{
					P2=~((1 << i) | (1 << j));
					Delay(500);
				}
			}

//				Delay100ms();
//				P2= 0x7e; //0111 1110
//				Delay100ms();
//				P2= 0x3c; //0011 1100
//				Delay100ms();
//				P2= 0x18; //0001 1000
//				Delay100ms();
//				P2= 0x00; //0000 0000
//				Delay100ms();
			{
				int i=0;
				int j=4;
				
				for(i=0,j=7;i<4,j>=4;j--,i++)
				{
					P2=((1 << i) | (1 << j));
					Delay(500);
				}
			}
				
		}
		else 
			P2=0xff;
	}
}