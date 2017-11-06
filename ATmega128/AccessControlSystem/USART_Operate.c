//USART_Operate.c

#include <iom128v.h>
#include "USART_Operate.h"

//USART0��ʼ��
void USART0_Init(unsigned int ubrr)
{
	UBRR0H = (unsigned char)(ubrr>>8); //���ò�����
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0); //ʹ�ܽ������뷢����
	UCSR0C = (1<<USBS0)|(3<<UCSZ00); //����֡��ʽ: 8������λ, 2��ֹͣλ
}

//USART0��5��8������λ�ķ�ʽ����֡
void USART0_Transmit(unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0))); //�ȴ����ͻ�����Ϊ��
	UDR0 = data; //�����ݷ��뻺����, ��������
}

//USART0��9������λ�ķ�ʽ����֡
void USART0_Transmit_9bits(unsigned int data)
{
	while(!(UCSR0A & (1<<UDRE0))); //�ȴ����ͻ�����Ϊ��
	UCSR0B &= ~(1<<TXB80); //����9λ���Ƶ�TXB8
	if(data & 0x0100)
		UCSR0B |= (1<<TXB80);
	UDR0 = data; //�����ݷ��뻺����, ��������
}

//USART0��5��8������λ�ķ�ʽ����֡
unsigned char USART0_Receive(void)
{
	while(!(UCSR0A & (1<<RXC0))); //�ȴ���������
	return UDR0; //�ӻ������л�ȡ����������
}

//USART0��9������λ�ķ�ʽ����֡
unsigned int USART0_Receive_9bits(void)
{
	unsigned char status, resh, resl;

	while(!(UCSR0A & (1<<RXC0))); //�ȴ���������
	status = UCSR0A; //�ӻ������л��״̬����9λ������
	resh = UCSR0B;
	resl = UDR0;
	if(status & (1<<FE0) | (1<<DOR0) | (1<<UPE0)) //�������, ����-1
		return -1;
	resh = (resh >> 1) & 0x01; //���˵�9λ����, Ȼ�󷵻�
	return ((resh << 8) | resl);
}

//USART0��5��8������λ�ķ�ʽ�����ַ���
void USART0_Transmit_String(unsigned char *p)
{
    while(*p)
    {
        USART0_Transmit(*p);
        p++;
    }
}

//USART0ˢ�½��ջ�����
void USART0_Flush(void)
{
	unsigned char dummy;
	while(UCSR0A & (1<<RXC0))
		dummy = UDR0;
}

//USART1��ʼ��
void USART1_Init(unsigned int ubrr)
{
	UBRR1H = (unsigned char)(ubrr>>8); //���ò�����
	UBRR1L = (unsigned char)ubrr;
	UCSR1B = (1<<RXEN1)|(1<<TXEN1); //ʹ�ܽ������뷢����
	UCSR1C = (1<<USBS1)|(3<<UCSZ01); //����֡��ʽ: 8������λ, 2��ֹͣλ
}

//USART1��5��8������λ�ķ�ʽ����֡
void USART1_Transmit(unsigned char data)
{
	while(!(UCSR1A & (1<<UDRE1))); //�ȴ����ͻ�����Ϊ��
	UDR1 = data; //�����ݷ��뻺����, ��������
}

//USART1��9������λ�ķ�ʽ����֡
void USART1_Transmit_9bits(unsigned int data)
{
	while(!(UCSR1A & (1<<UDRE1))); //�ȴ����ͻ�����Ϊ��
	UCSR1B &= ~(1<<TXB81); //����9λ���Ƶ�TXB8
	if(data & 0x0100)
		UCSR1B |= (1<<TXB81);
	UDR1 = data; //�����ݷ��뻺����, ��������
}

//USART1��5��8������λ�ķ�ʽ����֡
unsigned char USART1_Receive(void)
{
	while(!(UCSR1A & (1<<RXC1))); //�ȴ���������
	return UDR1; //�ӻ������л�ȡ����������
}

//USART1��9������λ�ķ�ʽ����֡
unsigned int USART1_Receive_9bits(void)
{
	unsigned char status, resh, resl;

	while(!(UCSR1A & (1<<RXC1))); //�ȴ���������
	status = UCSR1A; //�ӻ������л��״̬����9λ������
	resh = UCSR1B;
	resl = UDR1;
	if(status & (1<<FE1) | (1<<DOR1) | (1<<UPE1)) //�������, ����-1
		return -1;
	resh = (resh >> 1) & 0x01; //���˵�9λ����, Ȼ�󷵻�
	return ((resh << 8) | resl);
}

//USART1��5��8������λ�ķ�ʽ�����ַ���
void USART1_Transmit_String(unsigned char *p)
{
    while(*p)
    {
        USART1_Transmit(*p);
        p++;
    }
}

//USART1ˢ�½��ջ�����
void USART1_Flush(void)
{
	unsigned char dummy;
	while(UCSR1A & (1<<RXC1))
		dummy = UDR1;
}