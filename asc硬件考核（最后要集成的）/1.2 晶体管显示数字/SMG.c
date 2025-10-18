#include <REGX52.H>
#include "clean.h"
#include "delay.h"

void SMG(int loc,int num)
{
   
	switch(loc)
	{
		case 8:P2_2=0;P2_3=0;P2_4=0;break;
		case 7:P2_2=1;P2_3=0;P2_4=0;break;
		case 6:P2_2=0;P2_3=1;P2_4=0;break;
		case 5:P2_2=1;P2_3=1;P2_4=0;break;
		case 4:P2_2=0;P2_3=0;P2_4=1;break;
		case 3:P2_2=1;P2_3=0;P2_4=1;break;
		case 2:P2_2=0;P2_3=1;P2_4=1;break;
		case 1:P2_2=1;P2_3=1;P2_4=1;break;
	}
	switch(num)
	{
		case 1:P0=0x06;Delayms(1);clean();break;
		case 2:P0=0x5b;Delayms(1);clean();break;
		case 3:P0=0x4f;Delayms(1);clean();break;
		case 4:P0=0x66;Delayms(1);clean();break;
		case 5:P0=0x6d;Delayms(1);clean();break;
		case 6:P0=0x7d;Delayms(1);clean();break;
		case 7:P0=0x07;Delayms(1);clean();break;
		case 8:P0=0x7f;Delayms(1);clean();break;
		case 9:P0=0x6f;Delayms(1);clean();break;
		case 0:P0=0x3f;Delayms(1);clean();break;
	}
}