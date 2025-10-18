#ifndef __XPT2046_H__
#define __XPT2046_H__

#define XPT2046_XP 0x9c  // Channel 0
#define XPT2046_YP 0xdc  // Channel 1
#define XPT2046_VBAT 0xac  // Channel 2
#define XPT2046_AUX 0xec  // Channel 3

//十二位模式

#define XPT2046_XP12 0x95  // Channel 0
#define XPT2046_YP12 0xd5  // Channel 1
#define XPT2046_VBAT12 0xa5  // Channel 2
#define XPT2046_AUX12 0xe5  // Channel 3

unsigned int XPT2046_ReadAD(unsigned char command);

#endif