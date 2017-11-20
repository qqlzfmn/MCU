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
