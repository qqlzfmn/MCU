//#include "GlobalDefine.h"

#ifndef _GlobalDefine_H
#define _GlobalDefine_H

/*-------------------- 以下是引脚定义, 并不参与程序运行 --------------------*/

//定义LED引脚
#define led1				PA0		//定义PA0引脚接led1
#define led2				PA1		//定义PA1引脚接led2
#define led3				PA2		//定义PA2引脚接led3
#define led4				PA3		//定义PA3引脚接led4

//定义LCD引脚
#define lcd_busy			PA4		//定义PA4引脚接lcd_busy
#define lcd_rx				PE1		//定义PE1引脚接lcd_rx
#define lcd_tx				PE0		//定义PE0引脚接lcd_tx

//定义指纹模块引脚
#define fingerprint_rx		PD3		//定义PD3引脚接fingerprint_rx
#define fingerprint_tx		PD2		//定义PD2引脚接fingerprint_tx
#define fingerprint_power	PA7		//定义PA7引脚接fingerprint_power
#define fingerprint_touch	PC6		//定义PA6引脚接fingerprint_touch

//定义键盘模块引脚
#define keyboard_row1		PB0		//定义PB0引脚接keyboard_row1
#define keyboard_row2		PB1		//定义PB1引脚接keyboard_row2
#define keyboard_row3		PB2		//定义PB2引脚接keyboard_row3
#define keyboard_row4		PB3		//定义PB3引脚接keyboard_row4
#define keyboard_col1		PB4		//定义PB4引脚接keyboard_col1
#define keyboard_col2		PB5		//定义PB5引脚接keyboard_col2
#define keyboard_col3		PB6		//定义PB6引脚接keyboard_col3
#define keyboard_col4		PB7		//定义PB7引脚接keyboard_col4

/*-------------------- 以上是引脚定义, 并不参与程序运行 --------------------*/

//延时函数
void delay(unsigned char i);

//点亮指定LED
void led_on(unsigned char i);

//熄灭指定LED
void led_off(unsigned char i);

//点亮全部LED
void led_on_all(void);

//熄灭全部LED
void led_off_all(void);

//LED闪烁指定次
void led_blink(unsigned char i);

#endif
