//DeviceInitialize.c

#include <iom128v.h>
#include <macros.h>
#include "DeviceInitialize.h"
#include "USART_Operate.h"

//IO�˿ڳ�ʼ��
void port_init(void)
{
	PORTA = 0x00;
	DDRA  = 0x00;
	PORTB = 0x00;
	DDRB  = 0x00;
	PORTC = 0x00; //����m103���
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

//USART0��ʼ��
void USART0_Init(unsigned int ubrr)
{
	UBRR0H = (unsigned char)(ubrr>>8); //���ò�����
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0); //ʹ�ܽ������뷢����
	UCSR0C = (1<<USBS0)|(3<<UCSZ00); //����֡��ʽ: 8������λ, 2��ֹͣλ
}

//USART1��ʼ��
void USART1_Init(unsigned int ubrr)
{
	UBRR1H = (unsigned char)(ubrr>>8); //���ò�����
	UBRR1L = (unsigned char)ubrr;
	UCSR1B = (1<<RXEN1)|(1<<TXEN1); //ʹ�ܽ������뷢����
	UCSR1C = (1<<USBS1)|(3<<UCSZ01); //����֡��ʽ: 8������λ, 2��ֹͣλ
}

//�豸��ʼ��
void init_devices(void)
{
	//ֹͣ�����ж�ֱ�����ú�
	CLI(); //���������ж�
	XDIV  = 0x00; //��������
	XMCRA = 0x00; //�ⲿ�洢��
	port_init(); //IO�˿ڳ�ʼ��
	USART0_Init(MYUBRR0); //USART0���ڳ�ʼ��
	USART1_Init(MYUBRR1); //USART1���ڳ�ʼ��

	MCUCR = 0x00;
	EICRA = 0x00; //�����ⲿ�жϿ��ƼĴ���
	EICRB = 0x00; //�����ⲿ�жϿ��ƼĴ���
	EIMSK = 0x00;
	TIMSK = 0x00; //��ʱ���ж�Դ
	ETIMSK = 0x00; //��չ��ʱ���ж�Դ
	SEI(); //���������ж�
	//������Χ�豸���ڶ��ѳ�ʼ��
}