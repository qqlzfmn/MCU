//#include "USART_Operate.h"

#ifndef _USART_Operate_H
#define _USART_Operate_H

#define FOSC 11059200 //晶振频率
#define BAUD0 115200 //USART0波特率(屏幕)
#define BAUD1 57600 //USART1波特率(指纹)
#define MYUBRR0 FOSC/16/BAUD0-1 //UBRR0初值0x05
#define MYUBRR1 FOSC/16/BAUD1-1 //UBRR1初值0x0B

/*-------------------- USART0 --------------------*/

//USART0初始化
void USART0_Init(unsigned int ubrr);

//USART0以5到8个数据位的方式发送帧
void USART0_Transmit(unsigned char data);

//USART0以9个数据位的方式发送帧
void USART0_Transmit_9bits(unsigned int data);

//USART0以5到8个数据位的方式接收帧
unsigned char USART0_Receive(void);

//USART0以9个数据位的方式接收帧
unsigned int USART0_Receive_9bits(void);

//USART0以5到8个数据位的方式发送字符串
void USART0_Transmit_String(unsigned char *p);

//USART0刷新接收缓冲器
void USART0_Flush(void);

/*-------------------- USART1 --------------------*/

//USART1初始化
void USART1_Init(unsigned int ubrr);

//USART1以5到8个数据位的方式发送帧
void USART1_Transmit(unsigned char data);

//USART1以9个数据位的方式发送帧
void USART1_Transmit_9bits(unsigned int data);

//USART1以5到8个数据位的方式接收帧
unsigned char USART1_Receive(void);

//USART1以9个数据位的方式接收帧
unsigned int USART1_Receive_9bits(void);

//USART1以5到8个数据位的方式发送字符串
void USART1_Transmit_String(unsigned char *p);

//USART1刷新接收缓冲器
void USART1_Flush(void);

#endif
