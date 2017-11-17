//DeviceInitialize.c

#include <iom128v.h>
#include <macros.h>
#include "DeviceInitialize.h"
#include "USART_Operate.h"

//IO端口初始化
void port_init(void)
{
	PORTA = 0x00;
	DDRA  = 0x00;
	PORTB = 0x00;
	DDRB  = 0x00;
	PORTC = 0x00; //仅当m103输出
	DDRC  = 0x00;
	PORTD = 0x00;
	DDRD  = 0x00;
	PORTE = 0x00;
	DDRE  = 0x00;
	PORTF = 0x00;
	DDRF  = 0x00;
	PORTG = 0x00;
	DDRG  = 0x00;
}

//USART0初始化
void USART0_Init(unsigned int ubrr)
{
	UBRR0H = (unsigned char)(ubrr>>8); //设置波特率
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0); //使能接收器与发送器
	UCSR0C = (1<<USBS0)|(3<<UCSZ00); //设置帧格式: 8个数据位, 2个停止位
}

//USART1初始化
void USART1_Init(unsigned int ubrr)
{
	UBRR1H = (unsigned char)(ubrr>>8); //设置波特率
	UBRR1L = (unsigned char)ubrr;
	UCSR1B = (1<<RXEN1)|(1<<TXEN1); //使能接收器与发送器
	UCSR1C = (1<<USBS1)|(3<<UCSZ01); //设置帧格式: 8个数据位, 2个停止位
}

//设备初始化
void init_devices(void)
{
	//停止错误中断直到设置好
	CLI(); //禁用所有中断
	XDIV  = 0x00; //晶振驱动
	XMCRA = 0x00; //外部存储器
	port_init(); //IO端口初始化
	USART0_Init(MYUBRR0); //USART0串口初始化
	USART1_Init(MYUBRR1); //USART1串口初始化

	MCUCR = 0x00;
	EICRA = 0x00; //设置外部中断控制寄存器
	EICRB = 0x00; //设置外部中断控制寄存器
	EIMSK = 0x00;
	TIMSK = 0x00; //定时器中断源
	ETIMSK = 0x00; //扩展定时器中断源
	SEI(); //重新启用中断
	//所有外围设备现在都已初始化
}
