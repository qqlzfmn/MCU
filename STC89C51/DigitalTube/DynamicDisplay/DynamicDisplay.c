#include<reg51.h>
#define uint unsigned int
void delay(uint i);
void display(uint i);
void select(uint i);
void main()
{
	uint led;
	while(1)
	{
		for(led=1;led<=8;led++)
		{
			select(led); //ѡ���led�������
			display(led); //�ڵ�led�����������ʾ����led
			delay(1); //��ʱ���߻ᵼ����˸,���ͻᵼ�����ȵ�
			P0=0x00; //��Ӱ,�������ⲽ�����ᵼ������ܱ�����Ӧ������λ���лԹ�
		}
	}
}
void delay(uint i)
{
	uint j;
	for(i;i>0;i--)
		for(j=110;j>0;j--)
			;
}
void display(uint i)
{
	switch(i)
	{
		case 0:P0=~0xC0;break;
		case 1:P0=~0xF9;break;
		case 2:P0=~0xA4;break;
		case 3:P0=~0xB0;break;
		case 4:P0=~0x99;break;
		case 5:P0=~0x92;break;
		case 6:P0=~0x82;break;
		case 7:P0=~0xF8;break;
		case 8:P0=~0x80;break;
		case 9:P0=~0x90;break;
	}
}
void select(uint i)
{
	switch(i)
	{
		case 0:P1=0xFF;break;
		case 1:P1=0xFE;break;
		case 2:P1=0xFD;break;
		case 3:P1=0xFB;break;
		case 4:P1=0xF7;break;
		case 5:P1=0xEF;break;
		case 6:P1=0xDF;break;
		case 7:P1=0xBF;break;
		case 8:P1=0x7F;break;
		case 9:P1=0x00;break;
	}
}