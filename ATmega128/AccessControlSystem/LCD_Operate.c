//LCD_Operate.c

#include <iom128v.h>
#include <macros.h>
#include "LCD_Operate.h"
#include "USART_Operate.h"
#include "GlobalDefine.h"

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
	USART0_Transmit_String("CLS(");
	USART0_Transmit_String(color);
	USART0_Transmit_String(");\r\n");
}

//LCD显示
void LCD_Display(void)
{
	USART0_Transmit_String("\r\n");
}