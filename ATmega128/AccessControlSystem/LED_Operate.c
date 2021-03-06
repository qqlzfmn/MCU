//LED_Operate.c

#include <iom128v.h>
#include <macros.h>
#include "LED_Operate.h"

//点亮指定LED
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

//熄灭指定LED
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

//点亮全部LED
void led_on_all(void)
{
	PORTA = 0x0F;
	DDRA  = 0x0F;
}

//熄灭全部LED
void led_off_all(void)
{
	PORTA = 0x00;
	DDRA  = 0x0F;
}

//全部LED闪烁指定次
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
