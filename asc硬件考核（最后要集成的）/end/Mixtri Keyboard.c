#include <REGX52.H>
#include "Delay.h"

sbit Buzzer=P2^5;

//还是会想补一句，while，delay的用法是为了防止按键抖动
//可以理解为如果按键按下后20ms内没有松开就认为是有效按键
/*
*@brief 混合键盘按键扫描函数
*@return 返回按键值，未按下返回-1
*/

char Mix_key_num()
{
    char key_num = -1,i;

    P1 = 0xFF;                     // 让P1端口全部输出高电平
    //检测第一列按键
    P1_3 = 0;                    // 让P1.3输出低电平
    if(P1_7 == 0){Delayms(20);while(P1_7 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 1;} // 检测P1.7按键
    if(P1_6 == 0){Delayms(20);while(P1_6 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 4;} // 检测P1.5按键
    if(P1_5== 0){Delayms(20);while(P1_5 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 7;} // 检测P1.9按键
    P1 = 0xFF; 
    //检测第二列按键
    P1_2 = 0;                    // 让P1.2输出低电平
    if(P1_7 == 0){Delayms(20);while(P1_7 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 2;} // 检测P1.7按键
    if(P1_6 == 0){Delayms(20);while(P1_6 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 5;} // 检测P1.6按键
    if(P1_5 == 0){Delayms(20);while(P1_5 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 8;} // 检测P1.5按键
    if(P1_4 == 0){Delayms(20);while(P1_4 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 0;} // 检测P1.4按键
    P1 = 0xFF; 
    //检测第三列按键
    P1_1 = 0;                    // 让P1.1输出低电平
    if(P1_7 == 0){Delayms(20);while(P1_7 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 3;} // 检测P1.7按键
    if(P1_6 == 0){Delayms(20);while(P1_6 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 6;} // 检测P1.6按键
    if(P1_5 == 0){Delayms(20);while(P1_5 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 9;} // 检测P1.5按键
    P1 = 0xFF;
    //检测第四列按键
    P1_0 = 0;                    // 让P1.0输出低电平
    if(P1_7 == 0){Delayms(20);while(P1_7 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 11;} // 检测P1.7按键
    if(P1_6 == 0){Delayms(20);while(P1_6 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 12;} // 检测P1.6按键
    if(P1_5 == 0){Delayms(20);while(P1_5 == 0);Delayms(20);
        for(i=0;i<100;i++)
			{
				Buzzer=!Buzzer;
				Delayms(1);
			}
        key_num = 13;} // 检测P1.5按键
    P1 = 0xFF;

    return key_num;
}