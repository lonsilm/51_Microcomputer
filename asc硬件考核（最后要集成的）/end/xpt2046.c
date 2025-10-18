#include <REGX52.H>

sbit XPT2046_CS = P3^5;        // Chip Select
sbit XPT2046_CLK = P3^6;       // Clock
sbit XPT2046_DIN = P3^4;       // Data Input
sbit XPT2046_DOUT = P3^7;      // Data Output



unsigned int XPT2046_ReadAD(unsigned char command)
{
    unsigned int ADValue = 0;
    unsigned char i;
    XPT2046_CS=0;
    XPT2046_CLK = 0;
    // 发送8位命令，DIN强制为0/1
    for(i=0;i<8;i++)
    {
        XPT2046_DIN = (command & (0x80>>i));
        XPT2046_CLK = 1;
        XPT2046_CLK = 0;
    }
    // 采集16位AD数据（MSB first）
    for(i=0;i<16;i++)
    {
        XPT2046_CLK = 1;
        XPT2046_CLK = 0;
		if(XPT2046_DOUT) ADValue |= (0x8000>>i);
    }
    XPT2046_CS = 1;             // Disable chip
    if(command & 0x08)
    return ADValue>>8; // YP/XP channel is 12-bit
    else
    return ADValue>>4;
}