#include<reg51.h>
void delay(unsigned int i);
unsigned int led = 0xFF;
void main()
{
	while(1)
	{
		delay(200);
		led = led - 1;
		P2 = led;
	}
}
void delay(unsigned int i)
{
	unsigned int j;
	for(i;i>0;i--)
		for(j=255;j>0;j--)
			;
}