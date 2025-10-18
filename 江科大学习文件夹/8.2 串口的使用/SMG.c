#include <REGX52.H>

/*
* @brift: 数码管显示函数
* @param: loc - 位选  num - 段选
* @return: 无
*/
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
		case 1:P0=0x06;break;
		case 2:P0=0x5b;break;
		case 3:P0=0x4f;break;
		case 4:P0=0x66;break;
		case 5:P0=0x6d;break;
		case 6:P0=0x7d;break;
		case 7:P0=0x07;break;
		case 8:P0=0x7f;break;
		case 9:P0=0x6f;break;
		case 0:P0=0x3f;break;
	}
}