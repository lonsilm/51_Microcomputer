#include <REGX52.H>
#include <INTRINS.H>

void Delay100ms(void)	//@12.000MHz
{
	unsigned char data i, j;

	i = 195;
	j = 138;
	do
	{
		while (--j);
	} while (--i);
}


void Delay1000ms(void)	//@12.000MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 8;
	j = 154;
	k = 122;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	while(1)
	{
		Delay1000ms();
		P2= 0xFE; //1111 1110
		Delay100ms();
		P2= 0xFD; //1111 1101
		Delay100ms();
		P2= 0xFB; //1111 1011
		Delay100ms();
		P2= 0xF7; //1111 0111
		Delay100ms();
		P2= 0xef; //1110 1111
		Delay100ms();
		P2= 0xdf; //1101 1111
		Delay100ms();
		P2= 0xbf; //1011 1111
		Delay100ms();
		P2= 0x7f; //0111 1111
		Delay100ms();
		P2= 0x00; //0000 0000
		Delay1000ms();
		P2= 0x18; //0001 1000
		Delay100ms();
		P2= 0x3c; //0011 1100
		Delay100ms();
		P2= 0x7e; //0111 1110
		Delay100ms();
		P2= 0xFF; //1111 1111
		Delay100ms();
		P2= 0x7e; //0111 1110
		Delay100ms();
		P2= 0x3c; //0011 1100
		Delay100ms();
		P2= 0x18; //0001 1000
		Delay100ms();
		P2= 0x00; //0000 0000
		Delay100ms();
	}
	
}