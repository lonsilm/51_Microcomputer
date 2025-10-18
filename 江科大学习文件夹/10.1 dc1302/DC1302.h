#ifndef __DC1302__
#define __DC1302__

void DS1302_Init();
void DS1302_WriteByte(unsigned char Command,unsigned char Data);
unsigned char DS1302_ReadByte(unsigned char Commend);

#endif