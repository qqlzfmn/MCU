#include<reg51.h>
#include<intrins.h>
#define uint unsigned int
void delay(uint i);
uint led = 0x7F;
void main()
{
	while(1)
	{
		P2 = led;
		delay(200);
		led = _cror_(led,1); //ѭ������1λ,�ú���������<intrins.h>��
		if(led == 0x00)
		{
			P2 = led;
			delay(200);
			led = 0x7F;
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