#include <iom128v.h>
#include <macros.h>
#include "USART_Operate.h"
#include "FingerprintOperate.h"
#include "LCD_Operate.h"
#include "KeyboardOperate.h"
#include "DeviceInitialize.h"
#include "LED_Operate.h"
#include "Delay.h"

//����
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
				break; //���ָ�Ƶ���0ҳ
			case 'B':
				while(LCD_Busy());
				LCD_Standby();
				FINGERPRINT_search_reg_user();
				break; //����ָ���Ƿ��ڿ���
			case 'C':
				FINGERPRINT_Cmd_Delete_Model(0);
				break; //ɾ����0ҳ��ָ��
			case 'D':
				FINGERPRINT_Cmd_Delete_All_Model();
				break; //ɾ��ȫ��ָ��
		}
	}
}

void main(void)
{
	init_devices(); //�豸��ʼ��
	while(LCD_Busy());
	LCD_Init_Devices(); //LCD��ʾ�豸��ʼ��ҳ��
	led_blink(3); //ָʾ����˸3����ʾ�豸��ʼ�����

	Standby(); //����
}
