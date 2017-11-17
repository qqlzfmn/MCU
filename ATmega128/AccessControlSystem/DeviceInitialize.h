//#include "DeviceInitialize.h"

#ifndef _DeviceInitialize_H
#define _DeviceInitialize_H

//IO端口初始化
void port_init(void);

//USART0初始化
void USART0_Init(unsigned int ubrr);

//USART1初始化
void USART1_Init(unsigned int ubrr);

//设备初始化
void init_devices(void);

#endif
