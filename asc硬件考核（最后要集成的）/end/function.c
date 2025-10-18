#include <REGX52.H>
#include "Timer0.h"
#include "smg.h"
#include "Clean.h"
#include "Delay.h"
#include "Mixtri Keyboard.h"
#include "matrixled.h"
#include "key.h"
#include "lcd1602.h"
#include "xpt2046.h"
#include "uart.h"


unsigned char stream_i=0;


/*
*@brief  非阻塞流水灯函数
*/
void led_stream()
{
    if(stream_i>=8)
    {
        stream_i=0;
    }
    P2=~(0x01<<stream_i);
    
}

/*
* @brief  数码管显示时间函数
*/
unsigned char hh,mm,ss;

void smg_display_time()
{
    Timer0_Init();//初始化定时器0
        if(ss>=60)
        {
            ss=0;
            mm++;
            if(mm>=60)
            {
                mm=0;
                hh++;
                if(hh>=24)
                {
                    hh=0;
                }
            }
        }
    SMG(1,hh/10);
    SMG(2,hh%10);
    SMG(4,mm/10);
    SMG(5,mm%10);
    SMG(7,ss/10);
    SMG(8,ss%10);
}

/**@brief  按键操控数码管显示函数
*/
void control_smg()
{
    unsigned char key;
    static unsigned char num=0;
    key=Key();
    if(key==3)
    {
        num++;
    }
    if(key==4)
    {
        num--;
    }
    SMG(7,num/10);
    SMG(8,num%10);
}


/*
*@brief  控制点阵显示函数
*/
// 合并数字图案为二维数组，便于索引和维护
unsigned char code digits[10][8] = {
    {0x00,0x00,0x7E,0x81,0x81,0x7E,0x00,0x00}, // 0
    {0x00,0x00,0x41,0xFF,0xFF,0x01,0x00,0x00}, // 1
    {0x00,0x41,0x83,0x85,0x89,0x71,0x00,0x00}, // 2
    {0x00,0x42,0x81,0x89,0x89,0x76,0x00,0x00}, // 3
    {0x00,0x18,0x78,0x08,0xFF,0x08,0x08,0x00}, // 4
    {0x00,0x08,0xF1,0x51,0x51,0x0E,0x00,0x00}, // 5
    {0x00,0x7E,0x91,0x91,0x91,0x4E,0x00,0x00}, // 6
    {0x00,0x80,0x80,0x81,0x8C,0xE0,0x00,0x00}, // 7
    {0x00,0x6E,0x91,0x91,0x91,0x6E,0x00,0x00}, // 8
    {0x00,0x72,0x89,0x89,0x89,0x7E,0x00,0x00}  // 9
};

unsigned char code A_zimo[8] = {0x00,0x01,0x04,0x18,0x48,0xFF,0x00,0x00};
unsigned char code S_zimo[8] = {0x00,0x66,0x91,0x89,0x89,0x66,0x00,0x00};
unsigned char code C_zimo[8] = {0x00,0x7E,0x81,0x81,0x81,0x81,0x66,0x00};

void control_matrix_led()
{
    unsigned char mixkey_num, i;
    mixkey_num = Mix_key_num();

    // 如果是数字 0..9，直接从 digits 表中取图案
    if(mixkey_num <= 9)
    {
        
        for(i = 0; i < 8; i++)
        {
            MatrixLED_ShowColumn(i, digits[mixkey_num][i]);
            Delayms(2);
        }
        
    }

    // 处理字母或特殊键
    switch(mixkey_num)
    {
        case 11:
            for(i = 0; i < 8; i++) { MatrixLED_ShowColumn(i, A_zimo[i]); Delayms(2); }
            break;
        case 12:
            for(i = 0; i < 8; i++) { MatrixLED_ShowColumn(i, S_zimo[i]); Delayms(2); }
            break;
        case 13:
            for(i = 0; i < 8; i++) { MatrixLED_ShowColumn(i, C_zimo[i]); Delayms(2); }
            break;
        default:
            // 未定义或无按键时，可选择清空或保持当前显示，此处不改变显示
            break;
    }
}

/*
*@brief  LCD显示函数
*/
void lcd_display()
{
        LCD_ShowString(1, 1, "Hello, World!");
        LCD_ShowString(2, 1, "I LOVE ASC!!");
}

/*
*@brief  AD读取函数
*/
void  ad_read_function()
{
    unsigned int ADValue1;
    LCD_ShowString(1,1,"GR");
    ADValue1 = XPT2046_ReadAD(XPT2046_VBAT12);
    LCD_ShowNum(2,1,ADValue1,4);
    Delayms(100);
}

void uartuser()
{
    unsigned char keynum = 0;
    Uart1_Init();
    
    keynum = Key();
    if(keynum == 3)
    {
        UART_sendSTRING("Passionate about technology willing to contribute\r\n");
    }
    else if(keynum == 4)
    {
        UART_sendSTRING("adventure success cooperation\r\n");
    }
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count=0;
	
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xfc;				//设置定时初始值
	//这里再赋初始值是因为如果第一次溢出之后
	//寄存器就会从零开始+1；时间就不是1ms了
	
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;

		stream_i++;//每隔1秒流水灯移动一次
        ss++;//每隔1秒秒数加1
	}
}