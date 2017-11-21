//LCD_Operate.c

#include <iom128v.h>
#include <macros.h>
#include "LCD_Operate.h"
#include "USART_Operate.h"

//LCD��æ
unsigned char LCD_Busy(void)
{
	if(lcd_busy)
		return 1;
	else
		return 0;
}

//LCD��color��ɫ����
void LCD_Clear_Screen(unsigned char *color)
{
	GpuSend("CLS(");
	GpuSend(color);
	GpuSend(");\r\n");
}

//LCD��������0-100
void LCD_Set_Brightness(unsigned char *brightness)
{
	GpuSend("SEBL(");
	GpuSend(brightness);
	GpuSend(");\r\n");
}

//�豸��ʼ��ҳ��
void LCD_Init_Devices(void)
{
	GpuSend("DR0;");
	GpuSend("CLS(15);");
	GpuSend("SBC(15);");
	GpuSend("DS32(14,50,'�豸��ʼ����',0);");
	GpuSend("DS32(60,90,'���Ժ�...',0);");
	GpuSend("\r\n");
	GpuSend("\r\n");
}

//����ҳ��
void LCD_Standby(void)
{
	GpuSend("CLS(15);");
	GpuSend("SBC(15);");
	GpuSend("DS32(30,20,'�밴��ָ��',0);");
	GpuSend("DS24(26,60,'������ѧ������',0);");
	GpuSend("CBOX(40,100,180,120,0,0);");
	GpuSend("DS12(44,105,'ѧ��Ϊ8λ����',14);");
	GpuSend("CBOX(40,130,180,150,0,0);");
	GpuSend("DS12(44,135,'��ʼ������ѧ����ͬ',14);");
	GpuSend("\r\n");
}

//����ҳ��
void LCD_input(void)
{
	GpuSend("CLS(15);");
	GpuSend("SBC(15);");
	GpuSend("DS32(30,20,'�밴��ָ��',0);");
	GpuSend("DS24(26,60,'������ѧ������',0);");
	GpuSend("CBOX(40,100,180,120,0,0);");
	GpuSend("CBOX(40,130,180,150,0,0);");
	GpuSend("\r\n");
}

//ָ�ƴ���ҳ��
void LCD_fingerprint_wrong(void)
{
	GpuSend("CLS(15);");
	GpuSend("SBC(15);");
	GpuSend("DS32(14,20,'ָ���������',0);");
	GpuSend("DS24(14,60,'����ѧ���������',0);");
	GpuSend("CBOX(40,100,180,120,0,0);");
	GpuSend("DS12(44,105,'ѧ��Ϊ8λ����',14);");
	GpuSend("CBOX(40,130,180,150,0,0);");
	GpuSend("DS12(44,135,'��ʼ������ѧ����ͬ',14);");
	GpuSend("\r\n");
}

//ע��ָ��
void LCD_sign_up(void)
{
	GpuSend("CLS(15);");
	GpuSend("SBC(15);");
	GpuSend("DS32(30,72,'�밴��ָ��',0);");
	GpuSend("\r\n");
}
