NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   0071 =    113. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       00FD  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00FE   0A02 =   2562. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       007F  __start
       007F  __text_start
       00A1  _exit
       00A2  _main
       00E1  _USART0_Init
       00F0  _USART0_Transmit
       00F4  _USART0_Transmit_9bits
       00FC  _USART0_Receive
       0100  _USART0_Receive_9bits
       0113  _USART0_Transmit_String
       0123  _USART0_Flush
       0128  _USART1_Init
       013B  _USART1_Transmit
       0142  _USART1_Transmit_9bits
       0155  _USART1_Receive
       015C  _USART1_Receive_9bits
       0174  _USART1_Transmit_String
       0184  _USART1_Flush
       018C  _FINGERPRINT_Cmd_Get_Img
       01AB  _FINGERPRINT_Cmd_Img_To_Buffer1
       01CA  _FINGERPRINT_Cmd_Img_To_Buffer2
       01E9  _FINGERPRINT_Cmd_Reg_Model
       0208  _FINGERPRINT_Cmd_Delete_All_Model
       0227  _FINGERPRINT_Cmd_Delete_Model
       0279  _FINGERPRINT_Cmd_Get_Templete_Num
       02A2  _FINGERPRINT_Cmd_Search_Finger
       02C1  _FINGERPRINT_Cmd_Search_Finger_Admin
       02E0  _FINGERPRINT_Cmd_Save_Finger
       0352  _FINGERPRINT_Recevice_Data
       0366  _FINGERPRINT_add_new_user
       03A8  _FINGERPRINT_search_reg_user
       03CE  _LCD_Busy
       03D2  _LCD_Clear_Screen
       03E3  _LCD_Display
       03E7  _Keyboard_Scan
       04C5  _delay
       04DB  _led_on
       04FE  _led_off
       0521  _led_on_all
       0525  _led_off_all
       052A  _led_blink
       0539  _port_init
       054D  _init_devices
       0566  push_xgsetF00C
       056D  pop_xgsetF00C
       0574  lsr32
       0580  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0071 =    113. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       010F  _FP_Pack_Head
       0115  _FP_Get_Img
       011B  _FP_Templete_Num
       0121  _FP_Search
       012C  _FP_Search_0_9
       0137  _FP_Img_To_Buffer1
       013E  _FP_Img_To_Buffer2
       0145  _FP_Reg_Model
       014B  _FP_Delet_All_Model
       0151  _FP_Save_Finger
       015A  _FP_Delete_Model
       0171  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0171   0018 =     24. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0171  _UART1_FINGERPRINT_RECEVICE_BUFFER
       0171  __bss_start
       0189  __bss_end

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
DeviceInitialize.o	[ DeviceInitialize.c ]
<library>	[ gpushz.s, lsr32.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096

