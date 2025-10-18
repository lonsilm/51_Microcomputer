#include <REGX52.H>

/*
*@brief: Delay function
*@param: times - time in milliseconds
*/
void Delayms(unsigned int times)	//@11.0592MHz
{
	unsigned char data i, j;

	_nop_();
    while (times--)
    {
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
    }
}

/*
*@brief: Delay function
*@param: times - time in 10 microseconds
*/
void Delay10us(unsigned char times)	//@11.0592MHz
{
	unsigned char data i;
    while (times--)
    {
        i = 2;
        while (--i);
    }
}
