#include <REGX52.H>

int num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void Delay(int xms)	//@12.000MHz
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
}

void SMG(int loc,int number)
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
	P0 = num[number];
}

void clean()
{
    P0=0x00;
}

void main()
{
    while(1)
    {
        SMG(1,2);Delay(1);clean();
        SMG(2,0);Delay(1);clean();
        SMG(3,0);Delay(1);clean(); 
        SMG(4,6);Delay(1);clean();
        SMG(5,1);Delay(1);clean();
        SMG(6,0);Delay(1);clean();
        SMG(7,0);Delay(1);clean();
        SMG(8,4);Delay(1);clean();
    }
}