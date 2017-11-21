#include <iom128v.h>
#include <macros.h>
#include "USART_Operate.h"
#include "FingerprintOperate.h"
#include "LCD_Operate.h"
#include "KeyboardOperate.h"
#include "DeviceInitialize.h"
#include "LED_Operate.h"
#include "Delay.h"

//待机
void Standby(void)
{
	while(LCD_Busy());
	LCD_Standby();
	
	while(1)
	{
		switch(Keyboard_Scan())
		{
			case 'A':
				while(LCD_Busy());
				LCD_sign_up();
				FINGERPRINT_add_new_user(0);
				break; //添加指纹到第0页
			case 'B':
				while(LCD_Busy());
				LCD_Standby();
				FINGERPRINT_search_reg_user();
				break; //搜索指纹是否在库中
			case 'C':
				FINGERPRINT_Cmd_Delete_Model(0);
				break; //删除第0页的指纹
			case 'D':
				FINGERPRINT_Cmd_Delete_All_Model();
				break; //删除全部指纹
		}
	}
}

void main(void)
{
	init_devices(); //设备初始化
	while(LCD_Busy());
	LCD_Init_Devices(); //LCD显示设备初始化页面
	led_blink(3); //指示灯闪烁3次提示设备初始化完成

	Standby(); //待机
}
