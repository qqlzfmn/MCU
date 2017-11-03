#include<reg51.h>
void delay(unsigned int i);
sbit led1 = P2^7;
void main()
{
	while(1)
	{
		led1 = 0;
		delay(500);
		led1 = 1;
		delay(500);
	}
}
void delay(unsigned int i)
{
	unsigned int j;
	for(i;i>0;i--)
		for(j=255;j>0;j--)
			;
}