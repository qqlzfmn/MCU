//FingerprintOperate.c

#include <iom128v.h>
#include <macros.h>
#include "FingerprintOperate.h"
#include "USART_Operate.h"
#include "LED_Operate.h"

#define UART1_Send_Byte USART1_Transmit
#define UART1_Receive_Byte USART1_Receive

volatile unsigned char UART1_FINGERPRINT_RECEVICE_BUFFER[24]; //默认全为1

//FINGERPRINT通信协议定义
unsigned char FP_Pack_Head[6]={0xEF,0x01,0xFF,0xFF,0xFF,0xFF}; //协议包头
unsigned char FP_Get_Img[6]={0x01,0x00,0x03,0x01,0x00,0x05}; //获得指纹图像
unsigned char FP_Templete_Num[6]={0x01,0x00,0x03,0x1D,0x00,0x21}; //获得模版总数
unsigned char FP_Search[11]={0x01,0x00,0x08,0x04,0x01,0x00,0x00,0x03,0xE7,0x00,0xF8}; //搜索指纹搜索范围0-999
unsigned char FP_Search_0_9[11]={0x01,0x00,0x08,0x04,0x01,0x00,0x00,0x00,0x0A,0x00,0x18}; //搜索0-9号指纹
unsigned char FP_Img_To_Buffer1[7]={0x01,0x00,0x04,0x02,0x01,0x00,0x08}; //将图像放入到BUFFER1
unsigned char FP_Img_To_Buffer2[7]={0x01,0x00,0x04,0x02,0x02,0x00,0x09}; //将图像放入到BUFFER2
unsigned char FP_Reg_Model[6]={0x01,0x00,0x03,0x05,0x00,0x09}; //将BUFFER1跟BUFFER2合成特征模版
unsigned char FP_Delet_All_Model[6]={0x01,0x00,0x03,0x0d,0x00,0x11}; //删除指纹模块里所有的模版
volatile unsigned char FP_Save_Finger[9]={0x01,0x00,0x06,0x06,0x01,0x00,0x0B,0x00,0x19}; //将BUFFER1中的特征码存放到指定的位置
volatile unsigned char FP_Delete_Model[10]={0x01,0x00,0x07,0x0C,0x00,0x00,0x00,0x1,0x00,0x00}; //删除指定的模版
//volatile unsigned char FINGER_NUM;

/*-------------------- FINGERPRINT命令字 --------------------*/

//获得指纹图像命令
void FINGERPRINT_Cmd_Get_Img(void)
{
	unsigned char i;

	for(i=0;i<6;i++) //发送包头
		UART1_Send_Byte(FP_Pack_Head[i]);

	for(i=0;i<6;i++) //发送命令0x1d
		UART1_Send_Byte(FP_Get_Img[i]);
}

//将图像转换成特征码存放在Buffer1中
void FINGERPRINT_Cmd_Img_To_Buffer1(void)
{
	unsigned char i;

	for(i=0;i<6;i++) //发送包头
		UART1_Send_Byte(FP_Pack_Head[i]);

	for(i=0;i<7;i++) //发送命令将图像转换成特征码存放在CHAR_buffer1
		UART1_Send_Byte(FP_Img_To_Buffer1[i]);
}

//将图像转换成特征码存放在Buffer2中
void FINGERPRINT_Cmd_Img_To_Buffer2(void)
{
	unsigned char i;

	for(i=0;i<6;i++) //发送包头
		UART1_Send_Byte(FP_Pack_Head[i]);

	for(i=0;i<7;i++) //发送命令将图像转换成特征码存放在CHAR_buffer2
		UART1_Send_Byte(FP_Img_To_Buffer2[i]);
}

//将BUFFER1跟BUFFER2中的特征码合并成指纹模版
void FINGERPRINT_Cmd_Reg_Model(void)
{
	unsigned char i;

	for(i=0;i<6;i++) //包头
		UART1_Send_Byte(FP_Pack_Head[i]);

	for(i=0;i<6;i++) //命令合并指纹模版
		UART1_Send_Byte(FP_Reg_Model[i]);
}

//删除指纹模块里的所有指纹模版
void FINGERPRINT_Cmd_Delete_All_Model(void)
{
	unsigned char i;

	for(i=0;i<6;i++) //包头
		UART1_Send_Byte(FP_Pack_Head[i]);

	for(i=0;i<6;i++) //命令合并指纹模版
		UART1_Send_Byte(FP_Delet_All_Model[i]);
}

//删除指纹模块里的指定指纹模版
void FINGERPRINT_Cmd_Delete_Model(unsigned int Page_ID)
{
	volatile unsigned int sum = 0;
	unsigned char i;

	//Delete_MODEL[10]={0x01,0x00,0x07,0x0C,0x00,0x00,0x00,0x1,0x00,0x00}; //删除指定的模版

	FP_Delete_Model[4] = (Page_ID & 0xFF00) >> 8;
	FP_Delete_Model[5] = (Page_ID & 0x00FF);

	for(i=0;i<8;i++)
		sum = sum + FP_Delete_Model[i];

	//UART1_Send_Byte(sum);
	FP_Delete_Model[8] = (sum & 0xFF00)>>8;
	FP_Delete_Model[9] =  sum & 0x00FF;

	for(i=0;i<6;i++) //包头
		UART1_Send_Byte(FP_Pack_Head[i]);

	for(i=0;i<10;i++) //命令合并指纹模版
		UART1_Send_Byte(FP_Delete_Model[i]);
}

//获得指纹模板数量
void FINGERPRINT_Cmd_Get_Templete_Num(void)
{
	unsigned int i;
	unsigned char temp[14];

	for(i=0;i<6;i++) //包头
		UART1_Send_Byte(FP_Pack_Head[i]);

	for(i=0;i<6;i++) //发送命令0x1d
		UART1_Send_Byte(FP_Templete_Num[i]);
}

//搜索全部用户999枚
void FINGERPRINT_Cmd_Search_Finger(void)
{
	unsigned char i;

	for(i=0;i<6;i++) //发送命令搜索指纹库
		UART1_Send_Byte(FP_Pack_Head[i]);

	for(i=0;i<11;i++)
		UART1_Send_Byte(FP_Search[i]);
}

//搜索管理员用户10枚
void FINGERPRINT_Cmd_Search_Finger_Admin(void)
{
	unsigned char i;

	for(i=0;i<6;i++) //发送命令搜索指纹库
		UART1_Send_Byte(FP_Pack_Head[i]);

	for(i=0;i<11;i++)
		UART1_Send_Byte(FP_Search_0_9[i]);
}

//保存指纹到指定的位置
void FINGERPRINT_Cmd_Save_Finger(unsigned int Page_ID)
{
	unsigned long sum = 0;
	unsigned char i;

	//SAVE_FINGER[9]={0x01,0x00,0x06,0x06,0x01,0x00,0x0B,0x00,0x19}; //将BUFFER1中的特征码存放到指定的位置

	FP_Save_Finger[5] = (Page_ID & 0xFF00) >> 8;
	FP_Save_Finger[6] = (Page_ID & 0x00FF);

	for(i=0;i<7;i++) //计算校验和
		sum = sum + FP_Save_Finger[i];

	FP_Save_Finger[7]=(sum & 0x00FF00) >> 8; //存放校验数据
	FP_Save_Finger[8]= sum & 0x0000FF;

	for(i=0;i<6;i++)
		UART1_Send_Byte(FP_Pack_Head[i]); //发送包头

	for(i=0;i<9;i++)
		UART1_Send_Byte(FP_Save_Finger[i]); //发送命令将图像转换成特征码存放在CHAR_buffer1
}

//接收反馈数据缓冲
void FINGERPRINT_Recevice_Data(unsigned char ucLength)
{
	unsigned char i;

	for (i=0;i<ucLength;i++)
		UART1_FINGERPRINT_RECEVICE_BUFFER[i] = UART1_Receive_Byte();
}

/*-------------------- 应用层接口函数 --------------------*/

//指纹添加新用户
unsigned char FINGERPRINT_add_new_user(unsigned int Page_ID)
{
	led_off_all(); //先关闭所有提示灯
	led_on(1); //打开第一个提示灯

	do
	{
		FINGERPRINT_Cmd_Get_Img(); //获得指纹图像
		FINGERPRINT_Recevice_Data(12); //接收12个长度的反馈码
	}
	while(UART1_FINGERPRINT_RECEVICE_BUFFER[9]!=0x00); //检测是否成功的按了指纹
	
	led_on(2); //第一个指纹录入完成, 打开第二个提示灯

	FINGERPRINT_Cmd_Img_To_Buffer1(); //将图像转换成特征码存放在Buffer1中
	FINGERPRINT_Recevice_Data(12); //接收12个长度的反馈码

	do
	{
		FINGERPRINT_Cmd_Get_Img(); //获得指纹图像
		FINGERPRINT_Recevice_Data(12); //接收12个长度的反馈码			 
	}
	while(UART1_FINGERPRINT_RECEVICE_BUFFER[9]!=0x00);
	
	led_on(3); //第二个指纹录入完成, 打开第三个提示灯

	FINGERPRINT_Cmd_Img_To_Buffer2(); //将图像转换成特征码存放在Buffer2中
	FINGERPRINT_Recevice_Data(12); //接收12个长度的反馈码

	FINGERPRINT_Cmd_Reg_Model(); //转换成特征码
	FINGERPRINT_Recevice_Data(12);
	if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]!=0x00)
		return 0; //合并特征生成模板出错 返回0

	FINGERPRINT_Cmd_Save_Finger(Page_ID);
	FINGERPRINT_Recevice_Data(12);
	if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]!=0x00)
	{
		if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]==0x0B)
			return 2; //PageID超出指纹库范围 返回2
		return 0; //储存模板出错 返回0
	}

	led_on(4); //添加新用户完成, 打开全部提示灯
	return 1; //全部执行无误 返回1
}

//指纹搜索是否为注册用户
unsigned char FINGERPRINT_search_reg_user(void)
{
	led_off_all(); //先关闭所有提示灯
	led_on(1); //打开第一个提示灯

	do
	{
		FINGERPRINT_Cmd_Get_Img(); //获得指纹图像
		FINGERPRINT_Recevice_Data(12); //接收12个长度的反馈码
	}
	while(UART1_FINGERPRINT_RECEVICE_BUFFER[9]!=0x00); //检测是否成功的按了指纹

	led_on(2); //读取到指纹, 打开第二个提示灯

	FINGERPRINT_Cmd_Img_To_Buffer1(); //将图像转换成特征码存放在Buffer1中
	FINGERPRINT_Recevice_Data(12); //接收12个长度的反馈码

	FINGERPRINT_Cmd_Search_Finger(); //搜索全部用户999枚
	FINGERPRINT_Recevice_Data(16); //接收16个长度的反馈码

	if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]!=0x00)
	{
		led_on(4); //发生错误, 打开第四个提示灯
		return 0; //发生错误 返回0
	}

	led_on_all(); //找到匹配的指纹, 打开全部提示灯
	return 1; //全部执行无误 返回1
}

//检测是否有手指按下
unsigned char FINGERPRINT_touched(void)
{
	if(fingerprint_touched)
	{
		fingerprint_power_on;
		return 1;
	}
	return 0;
}
