NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   0044 =     68. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       00D0  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00D0   0110 =    272. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0068  __start
       0068  __text_start
       008A  _exit
       008B  _port_init
       0091  _uart0_init
       009D  _uart0_send_char
       00A1  _uart0_send_string
       00B1  _lcd_bz
       00BC  _delay
       00CF  _uart0_rx_isr
       00D0  _uart0_udre_isr
       00D1  _uart0_tx_isr
       00D2  _init_devices
       00E6  _main
       00F0  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0044 =     68. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       0144  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0054 =     84. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
finger.o	[ finger.c ]
<library>	

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096

