//LCD_Operate.c

#include <iom128v.h>
#include <macros.h>
#include "LCD_Operate.h"
#include "USART_Operate.h"

//LCD测忙
unsigned char LCD_Busy(void)
{
	if(lcd_busy)
		return 1;
	else
		return 0;
}

//LCD用color颜色清屏
void LCD_Clear_Screen(unsigned char *color)
{
	GpuSend("CLS(");
	GpuSend(color);
	GpuSend(");\r\n");
}

//LCD设置亮度0-100
void LCD_Set_Brightness(unsigned char *brightness)
{
	GpuSend("SEBL(");
	GpuSend(brightness);
	GpuSend(");\r\n");
}

//设备初始化页面
void LCD_Init_Devices(void)
{
	GpuSend("DR0;");
	GpuSend("CLS(15);");
	GpuSend("SBC(15);");
	GpuSend("DS32(14,50,'设备初始化中',0);");
	GpuSend("DS32(60,90,'请稍候...',0);");
	GpuSend("\r\n");
	GpuSend("\r\n");
}

//待机页面
void LCD_Standby(void)
{
	GpuSend("CLS(15);");
	GpuSend("SBC(15);");
	GpuSend("DS32(30,20,'请按下指纹',0);");
	GpuSend("DS24(26,60,'或输入学号密码',0);");
	GpuSend("CBOX(40,100,180,120,0,0);");
	GpuSend("DS12(44,105,'学号为8位数字',14);");
	GpuSend("CBOX(40,130,180,150,0,0);");
	GpuSend("DS12(44,135,'初始密码与学号相同',14);");
	GpuSend("\r\n");
}

//输入页面
void LCD_input(void)
{
	GpuSend("CLS(15);");
	GpuSend("SBC(15);");
	GpuSend("DS32(30,20,'请按下指纹',0);");
	GpuSend("DS24(26,60,'或输入学号密码',0);");
	GpuSend("CBOX(40,100,180,120,0,0);");
	GpuSend("CBOX(40,130,180,150,0,0);");
	GpuSend("\r\n");
}

//指纹错误页面
void LCD_fingerprint_wrong(void)
{
	GpuSend("CLS(15);");
	GpuSend("SBC(15);");
	GpuSend("DS32(14,20,'指纹输入错误',0);");
	GpuSend("DS24(14,60,'请用学号密码进入',0);");
	GpuSend("CBOX(40,100,180,120,0,0);");
	GpuSend("DS12(44,105,'学号为8位数字',14);");
	GpuSend("CBOX(40,130,180,150,0,0);");
	GpuSend("DS12(44,135,'初始密码与学号相同',14);");
	GpuSend("\r\n");
}

//注册指纹
void LCD_sign_up(void)
{
	GpuSend("CLS(15);");
	GpuSend("SBC(15);");
	GpuSend("DS32(30,72,'请按下指纹',0);");
	GpuSend("\r\n");
}
