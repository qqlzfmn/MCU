#include<reg51.h>
void delay(unsigned int i);
unsigned int led = 0xFF;
void main()
{
	while(1)
	{
		P2 = led;
		delay(200);
		led = led >> 1;
		if(led == 0x00)
		{
			P2 = led;
			delay(200);
			led = 0xFF;
		}
	}
}
void delay(unsigned int i)
{
	unsigned int j;
	for(i;i>0;i--)
		for(j=255;j>0;j--)
			;
}