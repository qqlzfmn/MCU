#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar code table1[]="Li Zongfeng";
uchar code table2[]="http://lzf.kim";
sbit lcden=P2^7;
sbit lcdrs=P2^6;
//sbit lcdrw=P2^5;
void delay(uint i);
void write_cmd(uchar cmd);
void write_data(uchar dat);
void init(void);
//bit lcd_bz();
void main()
{
		uchar i;
		init();
		//lcdrw=0;
		write_cmd(0x80);
		i=0;
		while(table1[i]!='\0')
		{
				write_data(table1[i]);
				i++;
				delay(5);
		}
		write_cmd(0x80+0x40);
		i=0;
		while(table2[i]!='\0')
		{
				write_data(table2[i]);
				i++;
				delay(5);
		}
		while(1);
}
void delay(uint i)
{
		uint j;
		for(i;i>0;i--)
				for(j=110;j>0;j--);
}
void write_cmd(uchar cmd)
{
		//while(lcd_bz());
		lcdrs=0;
		//delay(5);
		P0=cmd;
		delay(5);
		lcden=1;
		delay(5);
		lcden=0;
}
void write_data(uchar dat)
{
		//while(lcd_bz());
		lcdrs=1;
		//delay(5);
		P0=dat;
		delay(5);
		lcden=1;
		delay(5);
		lcden=0;
}
void init(void)
{
		lcden=0;
		write_cmd(0x38);
		//delay(5);
		write_cmd(0x0C);
		//delay(5);
		write_cmd(0x06);
		//delay(5);
		write_cmd(0x01);
		//delay(5);
}
/*bit lcd_bz()
{						
		bit result;
		lcdrs = 0;
		lcdrw = 1;
		lcden = 1;
		delay(5);
		result = (bit)(P0&0x80);
		lcden = 0;
		return result;
}*/