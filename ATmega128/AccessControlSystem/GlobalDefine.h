//#include "GlobalDefine.h"

#ifndef _GlobalDefine_H
#define _GlobalDefine_H

/*-------------------- ���������Ŷ���, ��������������� --------------------*/

//����LED����
#define led1				PA0		//����PA0���Ž�led1
#define led2				PA1		//����PA1���Ž�led2
#define led3				PA2		//����PA2���Ž�led3
#define led4				PA3		//����PA3���Ž�led4

//����LCD����
#define lcd_busy			PA4		//����PA4���Ž�lcd_busy
#define lcd_rx				PE1		//����PE1���Ž�lcd_rx
#define lcd_tx				PE0		//����PE0���Ž�lcd_tx

//����ָ��ģ������
#define fingerprint_rx		PD3		//����PD3���Ž�fingerprint_rx
#define fingerprint_tx		PD2		//����PD2���Ž�fingerprint_tx
#define fingerprint_power	PA7		//����PA7���Ž�fingerprint_power
#define fingerprint_touch	PC6		//����PA6���Ž�fingerprint_touch

//�������ģ������
#define keyboard_row1		PB0		//����PB0���Ž�keyboard_row1
#define keyboard_row2		PB1		//����PB1���Ž�keyboard_row2
#define keyboard_row3		PB2		//����PB2���Ž�keyboard_row3
#define keyboard_row4		PB3		//����PB3���Ž�keyboard_row4
#define keyboard_col1		PB4		//����PB4���Ž�keyboard_col1
#define keyboard_col2		PB5		//����PB5���Ž�keyboard_col2
#define keyboard_col3		PB6		//����PB6���Ž�keyboard_col3
#define keyboard_col4		PB7		//����PB7���Ž�keyboard_col4

/*-------------------- ���������Ŷ���, ��������������� --------------------*/

//��ʱ����
void delay(unsigned char i);

//����ָ��LED
void led_on(unsigned char i);

//Ϩ��ָ��LED
void led_off(unsigned char i);

//����ȫ��LED
void led_on_all(void);

//Ϩ��ȫ��LED
void led_off_all(void);

//LED��˸ָ����
void led_blink(unsigned char i);

#endif
