CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega128  -l -g -MLongJump -MHasMul -MEnhanced -Wf-use_elpm 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x20000 -ucrtatmega.o -bfunc_lit:0x8c.0x20000 -dram_end:0x10ff -bdata:0x100.0x10ff -dhwstk_size:30 -beeprom:0.4096 -fihx_coff -S2
FILES = AccessControlSystem.o USART_Operate.o FingerprintOperate.o LCD_Operate.o KeyboardOperate.o GlobalDefine.o 

ACCESSCONTROLSYSTEM:	$(FILES)
	$(CC) -o ACCESSCONTROLSYSTEM $(LFLAGS) @ACCESSCONTROLSYSTEM.lk   -lcatm128
AccessControlSystem.o: D:\iccv7avr\include\iom128v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\USART_Operate.h .\FingerprintOperate.h .\LCD_Operate.h .\KeyboardOperate.h .\GlobalDefine.h
AccessControlSystem.o:	AccessControlSystem.c
	$(CC) -c $(CFLAGS) AccessControlSystem.c
USART_Operate.o: D:\iccv7avr\include\iom128v.h .\USART_Operate.h
USART_Operate.o:	USART_Operate.c
	$(CC) -c $(CFLAGS) USART_Operate.c
FingerprintOperate.o: .\FingerprintOperate.h .\USART_Operate.h
FingerprintOperate.o:	FingerprintOperate.c
	$(CC) -c $(CFLAGS) FingerprintOperate.c
LCD_Operate.o: D:\iccv7avr\include\iom128v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\LCD_Operate.h .\USART_Operate.h
LCD_Operate.o:	LCD_Operate.c
	$(CC) -c $(CFLAGS) LCD_Operate.c
KeyboardOperate.o: .\KeyboardOperate.h
KeyboardOperate.o:	KeyboardOperate.c
	$(CC) -c $(CFLAGS) KeyboardOperate.c
GlobalDefine.o: .\GlobalDefine.h
GlobalDefine.o:	GlobalDefine.c
	$(CC) -c $(CFLAGS) GlobalDefine.c
