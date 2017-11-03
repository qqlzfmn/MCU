#include <reg51.h>
#define uint unsigned int

void display(uint i);
void select(uint i);
void delay(uint i);

uint num;
int counter;

// 定时器1初始化程序
void InitTimer1(void)
{
    TMOD = 0x10;
    TH1 = 0x4C;
    TL1 = 0x00;
    EA = 1;
    ET1 = 1;
    TR1 = 1;
}

void main(void)
{
    InitTimer1();
		num=0;
		counter=60;
		while(1)
		{
				select(1);
				display(counter/10);
				delay(1);
				P0=0x00;
				select(2);
				display(counter%10);
				delay(1);
				P0=0x00;
				if(num==20)
				{
						num=0;
						counter--;
						if(counter<0)
								counter=60;
				}
		}
}

// 定时器1中断服务程序
void Timer1Interrupt(void) interrupt 3
{
    TH1 = 0x4C;
    TL1 = 0x00;
    //add your code here!
		num++; //中断服务程序要短,功能尽量写在其他函数或主函数里
}

// 数码管显示程序
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

// 数码管位选程序
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

// 数码管刷新的延时
void delay(uint i)
{
	uint j;
	for(i;i>0;i--)
		for(j=110;j>0;j--)
			;
}
