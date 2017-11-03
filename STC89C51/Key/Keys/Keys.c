#include <reg51.h>
#define uint unsigned int
sbit k5  = P3^4;
sbit k6  = P3^5;
sbit k7  = P3^6;
sbit k8  = P3^7;
sbit led = P2^7;

void display(uint i);
void select(uint i);
void delay(uint i);
void keyscan(void);

uint num;
int counter;

void InitTimer1(void)
{
    TMOD = 0x10;
    TH1  = 0x4C;
    TL1  = 0x00;
    EA   = 1;
    ET1  = 1;
}

void main(void)
{
    InitTimer1();
		num=0;
		counter=0;
		while(1)
		{
			keyscan(); // TODO: Fix k5 and k7
				select(1);
				display(counter/10);
				delay(1);
				P0=0x00;
				select(2);
				display(counter%10);
				delay(1);
				P0=0x00;
		}
}

void Timer1Interrupt(void) interrupt 3
{
    TH1 = 0x4C;
    TL1 = 0x00;
    //add your code here!
		num++;
		if(num==20)
		{
				num=0;
				counter++;
				if(counter==60)
						counter=0;
				if(counter==-1)
						counter=59;
		}
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

void delay(uint i)
{
	uint j;
	for(i;i>0;i--)
		for(j=110;j>0;j--);
}

void keyscan()
{
		if(k5==0)
		{
				delay(50); //Eliminate jitter
				if(k5==0)
				{
						led=~led; //Test if the key pressed
						counter++;
						if(counter==60)
								counter=0;
						if(counter==-1)
								counter=59;
						while(!k5); //Wait for release the key
				}
		}
		if(k6==0)
		{
				delay(50);
				if(k6==0)
				{
						led=~led;
						counter--;
						if(counter==60)
								counter=0;
						if(counter==-1)
								counter=59;
						while(!k6);
				}
		}
		if(k7==0)
		{
				delay(50);
				if(k7==0)
				{
						led=~led;
						counter=0;
						if(counter==60)
								counter=0;
						if(counter==-1)
								counter=59;
						while(!k7);
				}
		}
		if(k8==0)
		{
				delay(50);
				if(k8==0)
				{
						led=~led;
						while(!k8);
						TR1=~TR1; //Turn on/off timer1
				}
		}
}