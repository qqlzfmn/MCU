NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   0055 =     85. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       00E1  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00E2   05C4 =   1476. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0071  __start
       0071  __text_start
       0093  _exit
       0094  _main
       009A  _USART0_Init
       00A6  _USART0_Transmit
       00AA  _USART0_Transmit_9bits
       00B2  _USART0_Receive
       00B6  _USART0_Receive_9bits
       00C9  _USART0_Transmit_String
       00D9  _USART0_Flush
       00DE  _USART1_Init
       00EC  _USART1_Transmit
       00F3  _USART1_Transmit_9bits
       0106  _USART1_Receive
       010D  _USART1_Receive_9bits
       0125  _USART1_Transmit_String
       0135  _USART1_Flush
       013D  _FINGERPRINT_Cmd_Get_Img
       015C  _FINGERPRINT_Cmd_Img_To_Buffer1
       017B  _FINGERPRINT_Cmd_Img_To_Buffer2
       019A  _FINGERPRINT_Cmd_Reg_Model
       01B9  _FINGERPRINT_Cmd_Delete_All_Model
       01D8  _FINGERPRINT_Cmd_Delete_Model
       022A  _FINGERPRINT_Cmd_Get_Templete_Num
       0253  _FINGERPRINT_Cmd_Search_Finger
       0272  _FINGERPRINT_Cmd_Search_Finger_Admin
       0291  _FINGERPRINT_Cmd_Save_Finger
       02FD  _FINGERPRINT_Recevice_Data
       0311  _FP_add_new_user
       0335  push_xgsetF03C
       033E  pop_xgsetF03C
       0347  lsr32
       0353  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0055 =     85. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _FP_Pack_Head
       0100  __data_start
       0106  _FP_Get_Img
       010C  _FP_Templete_Num
       0112  _FP_Search
       011D  _FP_Search_0_9
       0128  _FP_Img_To_Buffer1
       012F  _FP_Img_To_Buffer2
       0136  _FP_Reg_Model
       013C  _FP_Delet_All_Model
       0142  _FP_Save_Finger
       014B  _FP_Delete_Model
       0155  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0155   0018 =     24. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0155  _UART1_FINGERPRINT_RECEVICE_BUFFER
       0155  __bss_start
       016D  __bss_end

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

