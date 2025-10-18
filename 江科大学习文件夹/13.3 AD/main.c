#include <REGX52.H>
#include "delay.h"
#include "LCD1602.h"
#include "xpt2046.h"

unsigned int ADValue1;
unsigned int ADValue2;
unsigned int ADValue3;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADJ");
	LCD_ShowString(1,7,"NTC");
	LCD_ShowString(1,12,"GR");
	while(1)
	{
		ADValue1 = XPT2046_ReadAD(XPT2046_XP);
		ADValue2 = XPT2046_ReadAD(XPT2046_YP);
		ADValue3 = XPT2046_ReadAD(XPT2046_VBAT);
		LCD_ShowNum(2,1,ADValue1,4);
		LCD_ShowNum(2,7,ADValue2,4);
		LCD_ShowNum(2,12,ADValue3,4);
		Delay(10);
	}
}