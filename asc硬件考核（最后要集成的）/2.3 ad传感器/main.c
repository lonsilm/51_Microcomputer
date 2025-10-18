#include <REGX52.H>
#include "function.h"
#include "lcd1602.h"

void main()
{
	LCD_Init();
	while(1)
	{
		ad_read_function();
	}
	
}