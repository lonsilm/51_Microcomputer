#include <REGX52.H>
#include "delay.h"

#define  MatrixLED_Port   P0 
    sbit RCK=P3^5; //RCLK
    sbit SCK=P3^6; //SRCLK
    sbit SER=P3^4; //SER
void MATRIXLED_Init()
{

}

/*
*@brief 74HC595写入一个字节
*@param dat:要写入的数据
*/
void _74HC595_WriteByte(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SCK=0;
		SER=dat&(0x80>>i);
		SCK=1;
	}
	RCK=1;
	RCK=0;
}

/*
*@brief 显示某一列
*@param column:列号(0~7) Data:要显示的数据
*/
void MatrixLED_ShowColumn(unsigned char column,unsigned char Data)
{
	_74HC595_WriteByte(Data);
	MatrixLED_Port =~(0x80>>column);
	Delayms(1);
	MatrixLED_Port =0xff;
}