//#include "DeviceInitialize.h"

#ifndef _DeviceInitialize_H
#define _DeviceInitialize_H

//IO�˿ڳ�ʼ��
void port_init(void);

//USART0��ʼ��
void USART0_Init(unsigned int ubrr);

//USART1��ʼ��
void USART1_Init(unsigned int ubrr);

//�豸��ʼ��
void init_devices(void);

#endif
