#include<reg51.h>
#define uint unsigned int

void delay(uint i);
void display(uint i);
void select(uint i);
int keyscan(void);

void main()
{
		int key=0;
		while(1)
		{
				select(1);
				display(key/10);
				delay(1);
				display(1000);
				select(2);
				display(key%10);
				delay(1);
				display(1000);
				if(keyscan()!=0)
						key=keyscan();
		}
}
void delay(uint i)
{
		uint j;
		for(i;i>0;i--)
				for(j=110;j>0;j--);
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
				default:P0=0x00;break;
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
int keyscan(void)
{
		uint temp;
		P2=0xBF;
		temp=P2;
		temp=temp&0x0F;
		if(temp!=0x0F)
		{
				delay(10);
				temp=P2;
				temp=temp&0x0F;
				if(temp!=0x0F)
				{
						temp=P2;
						switch(temp)
						{
								case 0xB7:return 1;break;
								case 0xBB:return 2;break;
								case 0xBD:return 3;break;
								case 0xBE:return 4;break;
						}
				}
		}
		P2=0xDF;
		temp=P2;
		temp=temp&0x0F;
		if(temp!=0x0F)
		{
				delay(10);
				temp=P2;
				temp=temp&0x0F;
				if(temp!=0x0F)
				{
						temp=P2;
						switch(temp)
						{
								case 0xD7:return 5;break;
								case 0xDB:return 6;break;
								case 0xDD:return 7;break;
								case 0xDE:return 8;break;
						}
				}
		}
		P2=0xEF;
		temp=P2;
		temp=temp&0x0F;
		if(temp!=0x0F)
		{
				delay(10);
				temp=P2;
				temp=temp&0x0F;
				if(temp!=0x0F)
				{
						temp=P2;
						switch(temp)
						{
								case 0xE7:return 9;break;
								case 0xEB:return 10;break;
								case 0xED:return 11;break;
								case 0xEE:return 12;break;
						}
				}
		}
		return 0;
}