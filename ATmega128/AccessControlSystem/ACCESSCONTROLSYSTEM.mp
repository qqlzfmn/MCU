NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   006F =    111. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       00FB  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00FC   09D6 =   2518. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       007E  __start
       007E  __text_start
       00A0  _exit
       00A1  _main
       00D4  _USART0_Transmit
       00D8  _USART0_Transmit_9bits
       00E0  _USART0_Receive
       00E4  _USART0_Receive_9bits
       00F7  _USART0_Transmit_String
       0107  _USART0_Flush
       010C  _USART1_Transmit
       0113  _USART1_Transmit_9bits
       0126  _USART1_Receive
       012D  _USART1_Receive_9bits
       0145  _USART1_Transmit_String
       0155  _USART1_Flush
       015D  _FINGERPRINT_Cmd_Get_Img
       017C  _FINGERPRINT_Cmd_Img_To_Buffer1
       019B  _FINGERPRINT_Cmd_Img_To_Buffer2
       01BA  _FINGERPRINT_Cmd_Reg_Model
       01D9  _FINGERPRINT_Cmd_Delete_All_Model
       01F8  _FINGERPRINT_Cmd_Delete_Model
       024A  _FINGERPRINT_Cmd_Get_Templete_Num
       0273  _FINGERPRINT_Cmd_Search_Finger
       0292  _FINGERPRINT_Cmd_Search_Finger_Admin
       02B1  _FINGERPRINT_Cmd_Save_Finger
       0323  _FINGERPRINT_Recevice_Data
       0337  _FINGERPRINT_add_new_user
       0379  _FINGERPRINT_search_reg_user
       039F  _LCD_Busy
       03A3  _LCD_Clear_Screen
       03B4  _LCD_Display
       03B8  _Keyboard_Scan
       0496  _delay
       04AC  _led_on
       04CF  _led_off
       04F2  _led_on_all
       04F6  _led_off_all
       04FB  _led_blink
       050A  _port_init
       051E  _USART0_Init
       052A  _USART1_Init
       0538  _init_devices
       054F  push_xgsetF00C
       0556  pop_xgsetF00C
       055D  lsr32
       0569  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   006F =    111. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       010D  _FP_Pack_Head
       0113  _FP_Get_Img
       0119  _FP_Templete_Num
       011F  _FP_Search
       012A  _FP_Search_0_9
       0135  _FP_Img_To_Buffer1
       013C  _FP_Img_To_Buffer2
       0143  _FP_Reg_Model
       0149  _FP_Delet_All_Model
       014F  _FP_Save_Finger
       0158  _FP_Delete_Model
       016F  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   016F   0019 =     25. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       016F  _key_temp
       016F  __bss_start
       0170  _UART1_FINGERPRINT_RECEVICE_BUFFER
       0188  __bss_end

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

