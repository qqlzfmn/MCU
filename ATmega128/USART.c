#define FOSC 11059200// Clock Speed
#define BAUD 57600
#define MYUBRR FOSC/16/BAUD-1

void main(void)
{
	USART_Init(MYUBRR);
}

void USART_Init(unsigned int ubrr)
{
	/* Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<USBS)|(3<<UCSZ0);
}

void USART_Transmit(unsigned char data)
{
	/* Wait for empty transmit buffer */
	while(!(UCSRA & (1<<UDRE)));
	/* Put data into buffer, sends the data */
	UDR = data;
}

unsigned char USART_Receive(void)
{
	/* Wait for data to be received */
	while(!(UCSRA & (1<<RXC)));
	/* Get and return received data from buffer */
	return UDR;
}

unsigned int USART_Receive_9bits(void)
{
	unsigned char status, resh, resl;
	/* Wait for data to be received */
	while (!(UCSRA & (1<<RXC)));
	/* Get status and 9th bit, then data */
	/* from buffer */
	status = UCSRA;
	resh = UCSRB;
	resl = UDR;
	/* If error, return -1 */
	if (status & (1<<FE)|(1<<DOR)|(1<<UPE))
		return -1;
	/* Filter the 9th bit, then return */
	resh = (resh >> 1) & 0x01;
	return ((resh << 8) | resl);
}

void USART_Flush(void)
{
	unsigned char dummy;
	while (UCSRA & (1<<RXC))
		dummy = UDR;
}

