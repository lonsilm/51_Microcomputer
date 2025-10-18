#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "Mixtri Keyboard.h"

unsigned long int input;
int password=5201;

void main(void)

{
    char keynum=-1;
    LCD_Init();
    LCD_ShowString(1,1,"Password:");
    
    
		
    while(1)
    {
      keynum=Mix_key_num();
      if(keynum!=-1 && keynum<=10)
      {
        input+=keynum;
				input*=10;
      
				
				LCD_ShowNum(2,1,input/10,4);
      }
				
			if(input>10000)
			{
          if(keynum==11)
          {
					input/=10;
						if(input==password)
						{
							LCD_Init();
							LCD_ShowString(1,1," Happy Birthday ");
							LCD_ShowString(2,1,"to Yuan Zhenguo!");
							while(1);
						}
						else
						{
							LCD_ShowString(1,1,"  Wrong Password  ");
							LCD_ShowString(2,1,"   Try Again!    ");
							Delay(1000);
							LCD_Init();
							LCD_ShowString(1,1,"Password:");
							input=0;
						}
						
				}
      }

      if(keynum==12)
      {
        input=0;
        LCD_Init();
        LCD_ShowString(1,1,"Password:");
      }
				
    }
}