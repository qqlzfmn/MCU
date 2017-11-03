//ICC-AVR application builder : 17/10/31 16:00:25
// Target : M128
// Crystal: 11.0592Mhz

#include <iom128v.h>
#include <macros.h>

#define FOSC 11059200// Clock Speed
#define BAUD 115200
#define MYUBRR FOSC/16/BAUD-1

#define uint unsigned int
#define uchar unsigned char

void port_init(void)
{
	PORTA = 0x00;
 	DDRA  = 0x00;
 	PORTB = 0x00;
 	DDRB  = 0x00;
}

//UART0 initialize
// desired baud rate: 57600
// actual: baud rate:57600 (0.0%)
// char size: 8 bit
// parity: Disabled
void uart0_init(unsigned int ubrr)
{
	/* Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void uart0_send_char(uchar data)
{
	while(!(UCSR0A & (1<<UDRE0)));
	
	UDR0 = data;
}

void uart0_send_string(uchar *p)
{
    while(*p)
    {
        uart0_send_char(*p);
        p++;
    }
}

uint lcd_bz()
{
	PORTA = 0x00;
 	DDRA  = 0x00;
	if(PINA&BIT(4))
		return 1;
	else
		return 0;
}

void delay(uint ms)
{
	uint i;
	for(ms;ms>0;ms--)
		for(i=1200;i>0;i--);
}

#pragma interrupt_handler uart0_rx_isr:iv_USART0_RXC
void uart0_rx_isr(void)
{
 	//uart has received a character in UDR
}

#pragma interrupt_handler uart0_udre_isr:iv_USART0_UDRE
void uart0_udre_isr(void)
{
 	//character transferred to shift register so UDR is now empty
}

#pragma interrupt_handler uart0_tx_isr:iv_USART0_TXC
void uart0_tx_isr(void)
{
 	//character has been transmitted
}

//call this routine to initialize all peripherals
void init_devices(void)
{
 	//stop errant interrupts until set up
 	CLI(); //disable all interrupts
 	XDIV  = 0x00; //xtal divider
 	XMCRA = 0x00; //external memory
 	port_init();
 	uart0_init(MYUBRR);

 	MCUCR = 0x00;
 	EICRA = 0x00; //extended ext ints
 	EICRB = 0x00; //extended ext ints
 	EIMSK = 0x00;
 	TIMSK = 0x00; //timer interrupt sources
 	ETIMSK = 0x00; //extended timer interrupt sources
 	SEI(); //re-enable interrupts
 	//all peripherals are now initialized
}

//
void main(void)
{
 	init_devices();
 	//insert your functional code here...
	//delay(1000);
	while(lcd_bz());
	uart0_send_string("CLS(0);DS32(0,50,'实验室门禁系统',1);DS16(65,100,'显示模块测试',2);");
	//uart0_send_string("CLS(0);BOX(0,0,219,175,15);BOX(1,1,218,174,0);BOXF(2,2,217,17,3);PL(2,18,218,18,0);SBC(3);DS12(40,4,'菜单演示界面',15);SBC(0);PIC(20,40,1);DS12(25,75,'电压',7);PIC(70,40,2);DS12(75,75,'电流',7);PIC(120,40,3);DS12(125,75,'充电',7);PIC(170,40,4);DS12(175,75,'输入',7);PIC(20,110,5);DS12(25,145,'输出',7);PIC(70,110,6);DS12(75,145,'测试',7);PIC(120,110,7);DS12(125,145,'关闭',7);PIC(170,110,8);DS12(175,145,'设置',7);");
	//uart0_send_string("DR0;CLS(0);DS16(30,2,'Usart-GPU  串口液晶屏 ',2);PL(0,20,220,20,4);SNF(10,22);DS16(10,50,'出品:APACHECTL',13);DS16(10,72,'网站:http://www.A-DIY.cn',13);BS12(10,100,210,4,'　本页面可自由由上位机软件定义，具体资料以及程序请去网站下载。',15);BS12(10,140,210,4,'　静等10秒，演示开始；此间如有串口命令，则自动进入命令处理状态。',15);");
	while(1);
}

