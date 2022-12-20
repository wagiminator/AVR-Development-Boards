# ATtiny84A Development Board v2
Development board for ATtiny 24(A)/44(A)/84(A) with ICSP programming header and Arduino IDE support.

![ATtiny84_pic1.jpg](https://raw.githubusercontent.com/wagiminator/AVR-Development-Boards/master/ATtiny84_DevBoard_v2/documentation/ATtiny84_DevBoard_v2_pic1.jpg)

# Pinout
![ATtiny84_pinout.png](https://raw.githubusercontent.com/wagiminator/AVR-Development-Boards/master/ATtiny84_DevBoard_v2/documentation/ATtiny84_DevBoard_v2_pinout.png)

# Features of the ATtiny x4(A)

Specification         |    ATtiny24    |     ATtiny44   |      ATtiny84  |
----------------------|----------------|----------------|----------------|
Flash                 |     2048 bytes |     4096 bytes |     8192 bytes |
SRAM                  |      128 bytes |      256 bytes |      512 bytes |
EEPROM                |      128 bytes |      256 bytes |      512 bytes |
GPIO Pins             |     11 + RESET |     11 + RESET |     11 + RESET |
ADC Channels          |  12 (incl RST) |  12 (incl RST) |  12 (incl RST) |
Differential ADC      |     1/20x gain |     1/20x gain |     1/20x gain |
PWM Channels          |  4: PA5-7, PB2 |  4: PA5-7, PB2 |  4: PA5-7, PB2 |
Interfaces            |            USI |            USI |            USI |
Internal Oscillator   | 8, 4, 2, 1 MHz | 8, 4, 2, 1 MHz | 8, 4, 2, 1 MHz |
External Crystal      |     max 20 MHz |     max 20 MHz |     max 20 MHz |
External Clock        |     max 20 MHz |     max 20 MHz |     max 20 MHz |
Int. WDT Oscillator   |        128 kHz |        128 kHz |        128 kHz |
Default Pin Mapping   |      Clockwise |      Clockwise |      Clockwise |
LED_BUILTIN           |        PIN_PB2 |        PIN_PB2 |        PIN_PB2 |

Note: The 24/44/84 and 24A/44A/84A are functionally identical, have the same signatures and are fully interchangible; the latter replaced the former in 2008, uses slightly less power, and has a more accurate internal oscillator.

# Preparing Arduino IDE
- [Install ATtinyCore](https://github.com/SpenceKonde/ATTinyCore).
- Go to **Tools -> Board -> ATtinyCore** and select your chip (no bootloader).
- Go to **Tools** and set the desired board options.
- Connect your [ISP programmer](https://github.com/wagiminator/AVR-Programmer) to your PC and to the ICSP header of the board.
- Go to **Tools -> Programmer** and select your ISP programmer (e.g. [USBasp](https://aliexpress.com/wholesale?SearchText=usbasp)).
- Go to **Tools -> Burn Bootloader** to burn the fuses.
- Open your sketch and click **Upload**.

# References, Links and Notes
- [ATtinyCore](https://github.com/SpenceKonde/ATTinyCore)
- [ATtiny84A Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/ATtiny24A-44A-84A-DataSheet-DS40002269A.pdf)

![ATtiny84_pic2.jpg](https://raw.githubusercontent.com/wagiminator/AVR-Development-Boards/master/ATtiny84_DevBoard_v2/documentation/ATtiny84_DevBoard_v2_pic2.jpg)
![ATtiny84_pic3.jpg](https://raw.githubusercontent.com/wagiminator/AVR-Development-Boards/master/ATtiny84_DevBoard_v2/documentation/ATtiny84_DevBoard_v2_pic3.jpg)

# License

![license.png](https://i.creativecommons.org/l/by-sa/3.0/88x31.png)

This work is licensed under Creative Commons Attribution-ShareAlike 3.0 Unported License. 
(http://creativecommons.org/licenses/by-sa/3.0/)
