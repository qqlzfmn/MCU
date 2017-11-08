#include <iom128v.h>
#include <macros.h>
#include "USART_Operate.h"
#include "FingerprintOperate.h"
#include "LCD_Operate.h"
#include "KeyboardOperate.h"
#include "GlobalDefine.h"

#define uart0_send_string USART0_Transmit_String

void delay(unsigned int ms)
{
	unsigned int i;
	for(ms;ms>0;ms--)
		for(i=1200;i>0;i--);
}

void main(void)
{
	USART0_Init(MYUBRR0);
	PORTA = 0x81;
 	DDRA  = 0x81;
	
	//FINGERPRINT_add_new_user(0x00,0x0B);
	
	while(1)
	{
		while(LCD_Busy());
		LCD_Clear_Screen(cyan);
		//uart0_send_string("DS32(0,50,'实验室门禁系统',1);DS16(65,100,'显示模块测试',2);\r\n");
		while(LCD_Busy());
		delay(5000);
		while(LCD_Busy());
		LCD_Clear_Screen(gray);
		//uart0_send_string("DS32(0,50,'实验室门禁系统',1);DS16(65,100,'显示模块测试',2);\r\n");
		while(LCD_Busy());
		delay(5000);
		
	}
}
