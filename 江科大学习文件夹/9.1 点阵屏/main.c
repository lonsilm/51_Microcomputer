#include <REGX52.H>
#include "delay.h"
#include "uart.h"
#include "MatrixLED.h"

int main()
{
	MATRIXLED_Init();
	while(1)
	{
		//8*8的爱心
//		MatrixLED_ShowColumn(0,0x70);
//		MatrixLED_ShowColumn(1,0x88);
//		MatrixLED_ShowColumn(2,0x84);
//		MatrixLED_ShowColumn(3,0x42);
//		MatrixLED_ShowColumn(4,0x42);
//		MatrixLED_ShowColumn(5,0x84);
//		MatrixLED_ShowColumn(6,0x88);
//		MatrixLED_ShowColumn(7,0x70);
		//8*8的笑脸
			MatrixLED_ShowColumn(0,0x3c);
			MatrixLED_ShowColumn(1,0x42);
			MatrixLED_ShowColumn(2,0xa9);
			MatrixLED_ShowColumn(3,0x85);
			MatrixLED_ShowColumn(4,0x85);
			MatrixLED_ShowColumn(5,0xa9);
			MatrixLED_ShowColumn(6,0x42);
			MatrixLED_ShowColumn(7,0x3c);
			
	}
}