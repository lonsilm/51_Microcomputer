#include <REGX52.H>
#include "Delay.h"
#include "xpt2046.h"
#include "lcd1602.h"

void  ad_read_function()
{
    unsigned int ADValue;
    LCD_ShowString(1,1,"GR");
    ADValue = XPT2046_ReadAD(XPT2046_VBAT12);
    LCD_ShowNum(2,1,ADValue,4);
    Delayms(100);
}