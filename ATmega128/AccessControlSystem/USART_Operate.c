//USART_Operate.c

#include <iom128v.h>
#include "USART_Operate.h"

/*-------------------- USART0 --------------------*/

//USART0初始化
void USART0_Init(unsigned int ubrr)
{
	UCSR0B = 0x00; //关闭收器与发送器, 等待设置波特率
	UCSR0A = 0x00; //控制和状态寄存器0A初值
	UBRR0H = (unsigned char)(ubrr>>8); //设置波特率
	UBRR0L = (unsigned char)ubrr;
	UCSR0C = (0<<USBS0)|(3<<UCSZ00); //设置帧格式: 8个数据位, 1个停止位
	UCSR0B = (1<<RXEN0)|(1<<TXEN0); //使能接收器与发送器
}

//USART0以5到8个数据位的方式发送帧
void USART0_Transmit(unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0))); //等待发送缓冲器为空
	UDR0 = data; //将数据放入缓冲器, 发送数据
}

//USART0以9个数据位的方式发送帧
void USART0_Transmit_9bits(unsigned int data)
{
	while(!(UCSR0A & (1<<UDRE0))); //等待发送缓冲器为空
	UCSR0B &= ~(1<<TXB80); //将第9位复制到TXB8
	if(data & 0x0100)
		UCSR0B |= (1<<TXB80);
	UDR0 = data; //将数据放入缓冲器, 发送数据
}

//USART0以5到8个数据位的方式接收帧
unsigned char USART0_Receive(void)
{
	while(!(UCSR0A & (1<<RXC0))); //等待接收数据
	return UDR0; //从缓冲器中获取并返回数据
}

//USART0以9个数据位的方式接收帧
unsigned int USART0_Receive_9bits(void)
{
	unsigned char status, resh, resl;

	while(!(UCSR0A & (1<<RXC0))); //等待接收数据
	status = UCSR0A; //从缓冲器中获得状态、第9位及数据
	resh = UCSR0B;
	resl = UDR0;
	if(status & (1<<FE0) | (1<<DOR0) | (1<<UPE0)) //如果出错, 返回-1
		return -1;
	resh = (resh >> 1) & 0x01; //过滤第9位数据, 然后返回
	return ((resh << 8) | resl);
}

//USART0以5到8个数据位的方式发送字符串
void USART0_Transmit_String(unsigned char *p)
{
    while(*p)
    {
        USART0_Transmit(*p);
        p++;
    }
}

//USART0刷新接收缓冲器
void USART0_Flush(void)
{
	unsigned char dummy;
	while(UCSR0A & (1<<RXC0))
		dummy = UDR0;
}

/*-------------------- USART1 --------------------*/

//USART1初始化
void USART1_Init(unsigned int ubrr)
{
	UCSR1B = 0x00; //关闭收器与发送器, 等待设置波特率
	UCSR1A = 0x00; //控制和状态寄存器1A初值
	UBRR1H = (unsigned char)(ubrr>>8); //设置波特率
	UBRR1L = (unsigned char)ubrr;
	UCSR1C = (0<<USBS1)|(3<<UCSZ10); //设置帧格式: 8个数据位, 1个停止位
	UCSR1B = (1<<RXEN1)|(1<<TXEN1); //使能接收器与发送器
}

//USART1以5到8个数据位的方式发送帧
void USART1_Transmit(unsigned char data)
{
	while(!(UCSR1A & (1<<UDRE1))); //等待发送缓冲器为空
	UDR1 = data; //将数据放入缓冲器, 发送数据
}

//USART1以9个数据位的方式发送帧
void USART1_Transmit_9bits(unsigned int data)
{
	while(!(UCSR1A & (1<<UDRE1))); //等待发送缓冲器为空
	UCSR1B &= ~(1<<TXB81); //将第9位复制到TXB8
	if(data & 0x0100)
		UCSR1B |= (1<<TXB81);
	UDR1 = data; //将数据放入缓冲器, 发送数据
}

//USART1以5到8个数据位的方式接收帧
unsigned char USART1_Receive(void)
{
	while(!(UCSR1A & (1<<RXC1))); //等待接收数据
	return UDR1; //从缓冲器中获取并返回数据
}

//USART1以9个数据位的方式接收帧
unsigned int USART1_Receive_9bits(void)
{
	unsigned char status, resh, resl;

	while(!(UCSR1A & (1<<RXC1))); //等待接收数据
	status = UCSR1A; //从缓冲器中获得状态、第9位及数据
	resh = UCSR1B;
	resl = UDR1;
	if(status & (1<<FE1) | (1<<DOR1) | (1<<UPE1)) //如果出错, 返回-1
		return -1;
	resh = (resh >> 1) & 0x01; //过滤第9位数据, 然后返回
	return ((resh << 8) | resl);
}

//USART1以5到8个数据位的方式发送字符串
void USART1_Transmit_String(unsigned char *p)
{
    while(*p)
    {
        USART1_Transmit(*p);
        p++;
    }
}

//USART1刷新接收缓冲器
void USART1_Flush(void)
{
	unsigned char dummy;
	while(UCSR1A & (1<<RXC1))
		dummy = UDR1;
}
