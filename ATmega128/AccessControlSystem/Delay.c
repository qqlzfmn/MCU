//Delay.c

#include "Delay.h"

//��ʱ����
void delay(unsigned char i)
{
	unsigned char j, k;
	
	for(i; i>0; i--)
		for(j=0xFF; j>0; j--)
			for(k=0xFF; k>0; k--);
}
