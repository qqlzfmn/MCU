#include <iom128v.h>
#include <macros.h>
#include "USART_Operate.h"
#include "FingerprintOperate.h"
#include "LCD_Operate.h"
#include "KeyboardOperate.h"
#include "GlobalDefine.h"

void main(void)
{
	USART0_Init(MYUBRR0);
	while(1);
}