#include <iom128v.h>
#include <macros.h>
#include "USART_Operate.h"
#include "FingerprintOperate.h"
#include "LCD_Operate.h"
#include "KeyboardOperate.h"
#include "GlobalDefine.h"
#include "DeviceInitialize.h"

void main(void)
{
	init_devices(); //设备初始化
	
	delay(10); //等待设备初始化完成
	led_blink(3); //指示灯闪烁3次提示设备初始化完成
	USART0_Transmit_String("Hello World!");
	USART1_Transmit_String("Hello World!");
	while(1) //待机
	{
		//while(LCD_Busy());
		//LCD_Clear_Screen(gray);
		//USART0_Transmit_String("DS32(0,50,'实验室门禁系统',1);DS16(65,100,'显示模块测试',2);\r\n");
		//delay(100);
		switch(Keyboard_Scan())
		{
			case 'A': FINGERPRINT_add_new_user(0); break;
			case 'B': FINGERPRINT_search_reg_user(); break;
			case 'C': led_on(3); LCD_Clear_Screen(gray); break;
			case 'D': led_on(4); USART1_Transmit_String("Hello World!"); break;
		}
	}
}
