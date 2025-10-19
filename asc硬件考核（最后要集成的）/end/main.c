#include <REGX52.H>
#include "key.h"
#include "function.h"
#include "lcd1602.h"

void main()
{
    unsigned char mode=0,key_state;
    LCD_Init();
    while(1)
    {
        if(mode==0)
        {
            led_stream();
        }
        else if(mode==1)
        {
            smg_display_time();
        }
        else if(mode==2)
        {
            control_smg();
        }
        else if(mode==3)
        {
            control_matrix_led();
        }
        else if(mode==4)
        {
            lcd_display();
        }
        else if(mode==5)
        {
            ad_read_function();
        }
        else if(mode==6)
        {
            uartuser();
        }
        else if(mode==7)
        {
            show_i_love_asc();
        }
        key_state=Key();
        if(key_state==1)
        {
            mode++;
			LCD_Init();
            if(mode>=8)
            {
                mode=0;
            }
        }
    }
    
}