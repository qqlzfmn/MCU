//#include "LED_Operate.h"

#ifndef _LED_Operate_H
#define _LED_Operate_H

//点亮指定LED
void led_on(unsigned char i);

//熄灭指定LED
void led_off(unsigned char i);

//点亮全部LED
void led_on_all(void);

//熄灭全部LED
void led_off_all(void);

//全部LED闪烁指定次
void led_blink(unsigned char i);

#endif
