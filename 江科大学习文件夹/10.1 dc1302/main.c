#include <REGX52.H>
#include "lcd1602.h"
#include "dc1302.h"

unsigned char second;

void main()
{
    LCD_Init();
    DS1302_Init();
    LCD_ShowString(1,1,"RTC");

    DS1302_WriteByte(0x80,0x03);
    

    while(1)
    {
      second=DS1302_ReadByte(0x81);
			LCD_ShowNum(2,1,second,3);
    }
}
