#ifndef FUNCTIONs_H
#define FUNCTIONs_H

//八位模式
#define XPT2046_XP 0x9c  // Channel 0
#define XPT2046_YP 0xdc  // Channel 1
#define XPT2046_VBAT 0xac  // Channel 2
#define XPT2046_AUX 0xec  // Channel 3

//十二位模式
#define XPT2046_XP12 0x95  // Channel 0
#define XPT2046_YP12 0xd5  // Channel 1
#define XPT2046_VBAT12 0xa5  // Channel 2
#define XPT2046_AUX12 0xe5  // Channel 3

void led_stream();
void smg_display_time();
void control_smg();
void control_matrix_led();
void lcd_display();
void ad_read_function();
void uartuser();

#endif
