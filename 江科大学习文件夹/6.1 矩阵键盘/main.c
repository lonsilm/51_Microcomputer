#include <REGX52.H>
#include "Delay.h"
#include "Mixtri Keyboard.h"
#include "LCD1602.h"

void main(void)
{
    char key_num=-1;
		int column = 1;

    LCD_Init();
    LCD_ShowString(1,1,"Hello World!");
    Delay(750);
    LCD_Init();
    LCD_ShowString(1,1,"Password: ");

    while(1)
    {
        key_num = Mix_key_num();
        if(key_num != -1)
        {
            LCD_ShowNum(2,column++,key_num,1);
        }
        if(column > 6) 
				{
					LCD_ShowString(2,1,"Wrong!!");
					Delay(1000);
					column = 1;
          LCD_Init();
          LCD_ShowString(1,1,"Password: ");
				}
    }
}