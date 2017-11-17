//GlobalDefine.c

#include <iom128v.h>
#include <macros.h>
#include "GlobalDefine.h"

//��ʱ����
void delay(unsigned char i)
{
	unsigned char j, k;
	
	for(i; i>0; i--)
		for(j=0xFF; j>0; j--)
			for(k=0xFF; k>0; k--);
}

//����ָ��LED
void led_on(unsigned char i)
{
	switch(i)
	{
		case 1:
			PORTA |= BIT(0);
			DDRA  |= BIT(0);
			break;
		case 2:
			PORTA |= BIT(1);
			DDRA  |= BIT(1);
			break;
		case 3:
			PORTA |= BIT(2);
			DDRA  |= BIT(2);
			break;
		case 4:
			PORTA |= BIT(3);
			DDRA  |= BIT(3);
			break;
	}
}

//Ϩ��ָ��LED
void led_off(unsigned char i)
{
	switch(i)
	{
		case 1:
			PORTA &=~BIT(0);
			DDRA  &=~BIT(0);
			break;
		case 2:
			PORTA &=~BIT(1);
			DDRA  &=~BIT(1);
			break;
		case 3:
			PORTA &=~BIT(2);
			DDRA  &=~BIT(2);
			break;
		case 4:
			PORTA &=~BIT(3);
			DDRA  &=~BIT(3);
			break;
	}
}

//����ȫ��LED
void led_on_all(void)
{
	PORTA = 0x0F;
	DDRA  = 0x0F;
}

//Ϩ��ȫ��LED
void led_off_all(void)
{
	PORTA = 0x00;
	DDRA  = 0x0F;
}

//LED��˸ָ����
void led_blink(unsigned char i)
{
	for(i; i>0; i--)
	{
		led_on_all();
		delay(10);
		led_off_all();
		delay(10);
	}
}
