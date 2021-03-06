//KeyboardOperate.c

#include <iom128v.h>
#include "KeyboardOperate.h"
#include "Delay.h"

//判断按下的是哪个按键
unsigned char Keyboard_Scan(void)
{
	unsigned char temp; //设置PB口读取寄存位
	unsigned char key = 0; //设置按键值寄存位(初值为0, 可以用于判断是否有按键按下)
	
	//检测第一行按键
	PORTB = 0xFE; //PB0以外全设为高电平
	DDRB  = 0x0F; //PB低四位设为输入
	temp  = PINB; //读出PB口的数值到temp
	temp &= 0xF0; //检查高四位
	if(temp != 0xF0) //若高四位不全是高电平, 说明有按键按下
	{
		delay(1); //消抖
		temp  = PINB; //读出PB口的数值到temp
		temp &= 0xF0; //再次检查高四位的电平
		if(temp != 0xF0) //若高四位还不全是高电平, 说明确实有按键按下
		{
			temp = PINB; //读出PB口的数值到temp
			switch(temp) //判断是哪个按键按下
			{
				case 0xEE: key = '1'; break;
				case 0xDE: key = '2'; break;
				case 0xBE: key = '3'; break;
				case 0x7E: key = 'A'; break;
			}
		}
		//while(temp != 0xF0); //松手检测
	}
	
	//检测第二行按键
	PORTB = 0xFD; //PB1以外全设为高电平
	DDRB  = 0x0F; //PB低四位设为输入
	temp  = PINB; //读出PB口的数值到temp
	temp &= 0xF0; //检查高四位
	if(temp != 0xF0) //若高四位不全是高电平, 说明有按键按下
	{
		delay(1); //消抖
		temp  = PINB; //读出PB口的数值到temp
		temp &= 0xF0; //再次检查高四位的电平
		if(temp != 0xF0) //若高四位还不全是高电平, 说明确实有按键按下
		{
			temp = PINB; //读出PB口的数值到temp
			switch(temp) //判断是哪个按键按下
			{
				case 0xED: key = '4'; break;
				case 0xDD: key = '5'; break;
				case 0xBD: key = '6'; break;
				case 0x7D: key = 'B'; break;
			}
		}
		//while(temp != 0xF0); //松手检测
	}
	
	//检测第三行按键
	PORTB = 0xFB; //PB2以外全设为高电平
	DDRB  = 0x0F; //PB低四位设为输入
	temp  = PINB; //读出PB口的数值到temp
	temp &= 0xF0; //检查高四位
	if(temp != 0xF0) //若高四位不全是高电平, 说明有按键按下
	{
		delay(1); //消抖
		temp  = PINB; //读出PB口的数值到temp
		temp &= 0xF0; //再次检查高四位的电平
		if(temp != 0xF0) //若高四位还不全是高电平, 说明确实有按键按下
		{
			temp = PINB; //读出PB口的数值到temp
			switch(temp) //判断是哪个按键按下
			{
				case 0xEB: key = '7'; break;
				case 0xDB: key = '8'; break;
				case 0xBB: key = '9'; break;
				case 0x7B: key = 'C'; break;
			}
		}
		//while(temp != 0xF0); //松手检测
	}
	
	//检测第四行按键
	PORTB = 0xF7; //PB3以外全设为高电平
	DDRB  = 0x0F; //PB低四位设为输入
	temp  = PINB; //读出PB口的数值到temp
	temp &= 0xF0; //检查高四位
	if(temp != 0xF0) //若高四位不全是高电平, 说明有按键按下
	{
		delay(1); //消抖
		temp  = PINB; //读出PB口的数值到temp
		temp &= 0xF0; //再次检查高四位的电平
		if(temp != 0xF0) //若高四位还不全是高电平, 说明确实有按键按下
		{
			temp = PINB; //读出PB口的数值到temp
			switch(temp) //判断是哪个按键按下
			{
				case 0xE7: key = '*'; break;
				case 0xD7: key = '0'; break;
				case 0xB7: key = '#'; break;
				case 0x77: key = 'D'; break;
			}
		}
		//while(temp != 0xF0); //松手检测
	}
	return key; //返回读到的按键值
}
