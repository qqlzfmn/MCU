#include<reg51.h>
#define uint unsigned int
void delay(uint i);
void display(uint i);
void main()
{
	uint led;
	while(1)
	{
		for(led=0;led<=9;led++)
		{
			display(led);
			delay(500);
		}
	}
}
void delay(uint i)
{
	uint j;
	for(i;i>0;i--)
		for(j=255;j>0;j--)
			;
}
void display(uint i)
{
	switch(i)
	{
		case 0:P0=0xC0;break;
		case 1:P0=0xF9;break;
		case 2:P0=0xA4;break;
		case 3:P0=0xB0;break;
		case 4:P0=0x99;break;
		case 5:P0=0x92;break;
		case 6:P0=0x82;break;
		case 7:P0=0xF8;break;
		case 8:P0=0x80;break;
		case 9:P0=0x90;break;
	}
}