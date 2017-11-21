//#include "FingerprintOperate.h"

#ifndef _FingerprintOperate_H
#define _FingerprintOperate_H

#define fingerprint_power_on	PORTA |= BIT(7); DDRA & BIT(7) //����PA7���Ž�ָ��ģ���Դ
#define fingerprint_touched 	PINA  &  BIT(6) //����PA6���Ž�ָ��ģ�鴥�����

/*-------------------- FINGERPRINT������ --------------------*/

//FINGERPRINT_���ָ��ͼ������
void FINGERPRINT_Cmd_Get_Img(void);

//��ͼ��ת��������������Buffer1��
void FINGERPRINT_Cmd_Img_To_Buffer1(void);

//��ͼ��ת��������������Buffer2��
void FINGERPRINT_Cmd_Img_To_Buffer2(void);

//��BUFFER1��BUFFER2�е�������ϲ���ָ��ģ��
void FINGERPRINT_Cmd_Reg_Model(void);

//ɾ��ָ��ģ���������ָ��ģ��
void FINGERPRINT_Cmd_Delete_All_Model(void);

//ɾ��ָ��ģ�����ָ��ָ��ģ��
void FINGERPRINT_Cmd_Delete_Model(unsigned int Page_ID);

//���ָ��ģ������
void FINGERPRINT_Cmd_Get_Templete_Num(void);

//����ȫ���û�999ö
void FINGERPRINT_Cmd_Search_Finger(void);

//��������Ա�û�10ö
void FINGERPRINT_Cmd_Search_Finger_Admin(void);

//����ָ�Ƶ�ָ����λ��
void FINGERPRINT_Cmd_Save_Finger(unsigned int Page_ID);

//���շ������ݻ���
void FINGERPRINT_Recevice_Data(unsigned char ucLength);

/*-------------------- Ӧ�ò�ӿں��� --------------------*/

//ָ��������û�  ִ������󷵻�1 �������󷵻�0
unsigned char FINGERPRINT_add_new_user(unsigned int Page_ID);

//ָ�������Ƿ�Ϊע���û�  ִ������󷵻�1 �������󷵻�0
unsigned char FINGERPRINT_search_reg_user(void);

//����Ƿ�����ָ����  �����򷵻�1 ��û���򷵻�0
unsigned char FINGERPRINT_touched(void);

#endif
