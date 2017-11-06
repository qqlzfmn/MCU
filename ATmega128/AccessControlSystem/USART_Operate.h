//#include "USART_Operate.h"

#ifndef _USART_Operate_H
#define _USART_Operate_H

#define FOSC 11059200 //����Ƶ��
#define BAUD0 115200 //USART0������
#define BAUD1 57600 //USART1������
#define MYUBRR0 FOSC/16/BAUD0-1 //UBRR0��ֵ
#define MYUBRR1 FOSC/16/BAUD1-1 //UBRR1��ֵ

//USART0��ʼ��
void USART0_Init(unsigned int ubrr);

//USART0��5��8������λ�ķ�ʽ����֡
void USART0_Transmit(unsigned char data);

//USART0��9������λ�ķ�ʽ����֡
void USART0_Transmit_9bits(unsigned int data);

//USART0��5��8������λ�ķ�ʽ����֡
unsigned char USART0_Receive(void);

//USART0��9������λ�ķ�ʽ����֡
unsigned int USART0_Receive_9bits(void);

//USART0��5��8������λ�ķ�ʽ�����ַ���
void USART0_Transmit_String(unsigned char *p);

//USART0ˢ�½��ջ�����
void USART0_Flush(void);

//USART1��ʼ��
void USART1_Init(unsigned int ubrr);

//USART1��5��8������λ�ķ�ʽ����֡
void USART1_Transmit(unsigned char data);

//USART1��9������λ�ķ�ʽ����֡
void USART1_Transmit_9bits(unsigned int data);

//USART1��5��8������λ�ķ�ʽ����֡
unsigned char USART1_Receive(void);

//USART1��9������λ�ķ�ʽ����֡
unsigned int USART1_Receive_9bits(void);

//USART1��5��8������λ�ķ�ʽ�����ַ���
void USART1_Transmit_String(unsigned char *p);

//USART1ˢ�½��ջ�����
void USART1_Flush(void);

#endif