#include <REGX52.H>

int Delay(int xms)	//@12.000MHz
{
	while(xms--){
		unsigned char data i, j;

		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
	return 0;
}


void SMG(unsigned int place,num)
{
	switch(place)
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

void clean()
{
	P0=0x00;
}

void display(int sec,int min)
{
	int i;
	for(i=0;i<250;i++)
	{
		SMG(8,sec%10);Delay(1);
		clean();
		SMG(7,sec/10);Delay(1);
		clean();
		SMG(4,min%10);Delay(1);
		clean();
		SMG(3,min/10);Delay(1);
		clean();
	}
}



void main()
{
	int sec=0;
	int min=0;
	int flag=0;

	if(P3_1==0)
	{
		Delay(20);
		while(P3_1==0);
		Delay(20);
		flag=1;
	}

	while(flag)
	{
		display(sec,min);
		sec++;
		if(sec==60)
		{
			sec=0;
			min++;
			if(min==60)
				min=0;
		}
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			flag=0;
		}
	}
	while(!flag)
	{
		display(sec,min);
		if(P3_1==0)
		{
		Delay(20);
		if(P3_1==0)
			flag=1;
		}

	}
	
}