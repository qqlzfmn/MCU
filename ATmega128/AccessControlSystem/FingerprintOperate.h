//#include "FingerprintOperate.h"

#ifndef _FingerprintOperate_H
#define _FingerprintOperate_H

#define fingerprint_power_on	PORTA |= BIT(7); DDRA & BIT(7) //定义PA7引脚接指纹模块电源
#define fingerprint_touched 	PINA  &  BIT(6) //定义PA6引脚接指纹模块触摸检测

/*-------------------- FINGERPRINT命令字 --------------------*/

//FINGERPRINT_获得指纹图像命令
void FINGERPRINT_Cmd_Get_Img(void);

//将图像转换成特征码存放在Buffer1中
void FINGERPRINT_Cmd_Img_To_Buffer1(void);

//将图像转换成特征码存放在Buffer2中
void FINGERPRINT_Cmd_Img_To_Buffer2(void);

//将BUFFER1跟BUFFER2中的特征码合并成指纹模版
void FINGERPRINT_Cmd_Reg_Model(void);

//删除指纹模块里的所有指纹模版
void FINGERPRINT_Cmd_Delete_All_Model(void);

//删除指纹模块里的指定指纹模版
void FINGERPRINT_Cmd_Delete_Model(unsigned int Page_ID);

//获得指纹模板数量
void FINGERPRINT_Cmd_Get_Templete_Num(void);

//搜索全部用户999枚
void FINGERPRINT_Cmd_Search_Finger(void);

//搜索管理员用户10枚
void FINGERPRINT_Cmd_Search_Finger_Admin(void);

//保存指纹到指定的位置
void FINGERPRINT_Cmd_Save_Finger(unsigned int Page_ID);

//接收反馈数据缓冲
void FINGERPRINT_Recevice_Data(unsigned char ucLength);

/*-------------------- 应用层接口函数 --------------------*/

//指纹添加新用户  执行无误后返回1 发生错误返回0
unsigned char FINGERPRINT_add_new_user(unsigned int Page_ID);

//指纹搜索是否为注册用户  执行无误后返回1 发生错误返回0
unsigned char FINGERPRINT_search_reg_user(void);

//检测是否有手指按下  若有则返回1 若没有则返回0
unsigned char FINGERPRINT_touched(void);

#endif
