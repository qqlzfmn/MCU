#include <reg51.h>
#define uint unsigned int
sbit led = P2^7;
uint num=0;

void InitTimer0(void)
{
    TMOD = 0x01;
    TH0 = 0x4C;
    TL0 = 0x00;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}

void main(void)
{
		InitTimer0();
		while(1)
		{
				if(num==20)
				{
					num=0;
					led=~led;
				}
		}
}

void Timer0Interrupt(void) interrupt 1
{
    TH0 = 0x4C;
    TL0 = 0x00;
    //add your code here!
		num++;
}
