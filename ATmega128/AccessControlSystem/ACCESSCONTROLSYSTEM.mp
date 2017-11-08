NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   0063 =     99. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       00EF  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00F0   0660 =   1632. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0078  __start
       0078  __text_start
       009A  _exit
       009B  _delay
       00AE  _main
       00D8  _USART0_Init
       00E4  _USART0_Transmit
       00E8  _USART0_Transmit_9bits
       00F0  _USART0_Receive
       00F4  _USART0_Receive_9bits
       0107  _USART0_Transmit_String
       0117  _USART0_Flush
       011C  _USART1_Init
       012A  _USART1_Transmit
       0131  _USART1_Transmit_9bits
       0144  _USART1_Receive
       014B  _USART1_Receive_9bits
       0163  _USART1_Transmit_String
       0173  _USART1_Flush
       017B  _FINGERPRINT_Cmd_Get_Img
       019A  _FINGERPRINT_Cmd_Img_To_Buffer1
       01B9  _FINGERPRINT_Cmd_Img_To_Buffer2
       01D8  _FINGERPRINT_Cmd_Reg_Model
       01F7  _FINGERPRINT_Cmd_Delete_All_Model
       0216  _FINGERPRINT_Cmd_Delete_Model
       0268  _FINGERPRINT_Cmd_Get_Templete_Num
       0291  _FINGERPRINT_Cmd_Search_Finger
       02B0  _FINGERPRINT_Cmd_Search_Finger_Admin
       02CF  _FINGERPRINT_Cmd_Save_Finger
       033B  _FINGERPRINT_Recevice_Data
       034F  _FINGERPRINT_add_new_user
       0373  _LCD_Busy
       0379  _LCD_Clear_Screen
       038A  push_xgsetF03C
       0393  pop_xgsetF03C
       039C  lsr32
       03A8  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0063 =     99. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       0104  _FP_Pack_Head
       010A  _FP_Get_Img
       0110  _FP_Templete_Num
       0116  _FP_Search
       0121  _FP_Search_0_9
       012C  _FP_Img_To_Buffer1
       0133  _FP_Img_To_Buffer2
       013A  _FP_Reg_Model
       0140  _FP_Delet_All_Model
       0146  _FP_Save_Finger
       014F  _FP_Delete_Model
       0163  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0163   0018 =     24. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0163  _UART1_FINGERPRINT_RECEVICE_BUFFER
       0163  __bss_start
       017B  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
AccessControlSystem.o	[ AccessControlSystem.c ]
USART_Operate.o	[ USART_Operate.c ]
FingerprintOperate.o	[ FingerprintOperate.c ]
LCD_Operate.o	[ LCD_Operate.c ]
KeyboardOperate.o	[ KeyboardOperate.c ]
GlobalDefine.o	[ GlobalDefine.c ]
<library>	[ gpushb.s, lsr32.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096

