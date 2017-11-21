//#include "LCD_Operate.h"

#ifndef _LCD_Operate_H
#define _LCD_Operate_H

#define black 		"0"		//黑色
#define red 		"1" 	//红色
#define green 		"2" 	//绿色
#define blue 		"3" 	//蓝色
#define yellow 		"4" 	//黄色
#define cyan 		"5" 	//青色
#define pink 		"6" 	//粉色
#define gray 		"7" 	//灰色
#define dark_gray 	"8" 	//深灰 
#define dark_red 	"9" 	//深红
#define dark_green 	"10" 	//深绿
#define dark_blue 	"11" 	//深蓝
#define dark_yellow "12" 	//深黄
#define dark_cyan 	"13" 	//深青
#define white 		"14" 	//白色
#define light_gray 	"15"	//浅灰

#define GpuSend		USART0_Transmit_String

#define lcd_busy	PINA & BIT(4) //定义PA4引脚接lcd_busy

//LCD测忙
unsigned char LCD_Busy(void);

//LCD用color颜色清屏
void LCD_Clear_Screen(unsigned char *color);

//LCD设置亮度0-100
void LCD_Set_Brightness(unsigned char *brightness);

//设备初始化页面
void LCD_Init_Devices(void);

//待机页面
void LCD_Standby(void);

//输入页面
void LCD_input(void);

//指纹错误页面
void LCD_fingerprint_wrong(void);

//注册指纹
void LCD_sign_up(void);

#endif
