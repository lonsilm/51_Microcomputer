#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "STT View.h"
#include "Timer.h" // 你需要实现Timer函数

void main()
{
    int stt = 0;   // 0: Timer, 1: Birthday
    int flag = 0;  // 0:主界面, 1:计时器界面

    LCD_Init();
    stt_display1(); // 显示主界面（Timer）

    while(1)
    {
        if(flag == 0) // 主界面
        {
            // 切换主界面显示内容
            if(P3_1 == 0)
            {
                Delay(20);
                if(P3_1 == 0)
                {
                    while(P3_1 == 0); // 等待松手
                    stt = !stt;
                    if(stt == 0)
                        stt_display1();
                    else
                        stt_display2();
                }
            }
            // 进入计时器界面
            if(P3_0 == 0)
            {
                Delay(20);
                if(P3_0 == 0)
                {
                    while(P3_0 == 0); // 等待松手
                    if(stt == 0) // 只有Timer界面时才进入
                    {
                        flag = 1;
                        Timer_InitView(); // 进入计时器界面初始化显示
                    }
                }
            }
        }
        else if(flag == 1) // 计时器界面
        {
            Timer_view(flag); // 计时器运行与显示（你需要实现）

            // 按P3_0返回主界面
            if(P3_0 == 0)
            {
                Delay(20);
                if(P3_0 == 0)
                {
                    while(P3_0 == 0); // 等待松手
                    flag = 0;
                    stt_display1(); // 返回主界面
                }
            }
        }
    }
}
//全是屎
//傻逼ai还要骂我
//投死你的ma