//LCD_Operate.c

#include <iom128v.h>
#include <macros.h>
#include "LCD_Operate.h"
#include "USART_Operate.h"

//LCD��æ
unsigned char LCD_Busy(void)
{
	if(PINA & BIT(4))
		return 1;
	else
		return 0;
}

//LCD����
void LCD_Clear_Screen(unsigned char *color)
{
	USART0_Transmit_String("CLS(");
	USART0_Transmit_String(color);
	USART0_Transmit_String(");\r\n");
}
