# ATtiny x06/x16/x26 Development Board v2
Development board for ATtiny x06/x16/x26 series with USB to serial converter, integrated SerialUPDI programmer and Arduino IDE support.

![ATtiny3216_pic1.jpg](https://raw.githubusercontent.com/wagiminator/AVR-Development-Boards/master/ATtiny3216_DevBoard_v2/documentation/ATtiny3216_DevBoard_v2_pic1.jpg)

# Pinout
![ATtiny3216_pinout.png](https://raw.githubusercontent.com/wagiminator/AVR-Development-Boards/master/ATtiny3216_DevBoard_v2/documentation/ATtiny3216_DevBoard_v2_pinout.png)

# Serial Mode Switch
The integrated CH340N USB to serial converter can also be used as a SerialUPDI programmer, so that no additional hardware is required to flash your firmware. Set the Serial Mode Switch on the board to "P" (Programming Mode) for uploading firmware and to "S" (Serial Mode) for UART communication via USB. You do not need to unplug the board for changing the Serial Mode.

# Features of the tinyAVR

 Specifications |   ATtiny406   |   ATtiny806   |  ATtiny1606
----------------|---------------|---------------|--------------
Flash           |    4096 bytes |    8192 bytes |   16384 bytes
RAM             |     256 bytes |     512 bytes |    1024 bytes
EEPROM          |     128 bytes |     128 bytes |     256 bytes
GPIO Pins       | 18 (17 usable)| 18 (17 usable)| 18 (17 usable)
ADC Channels    | 11 | 11 | 11
DAC             |  0 |  0 |  0
PWM Channels    |  6 |  6 |  6
Timer/Counter A |  1 |  1 |  1
Timer/Counter B |  1 |  1 |  1
Timer/Counter D |  0 |  0 |  0
CCL Logic Blocks | 2 (no int) | 2 (no int) | 2 (no int) | 2 (no int)
Event Channels   | 3, 1 sync<br/> 2 async | 3, 1 sync<br/> 2 async  | 3, 1 sync<br/> 2 async | 3, 1 sync<br/> 2 async
Interfaces | UART, SPI, I2C | UART, SPI, I2C | UART, SPI, I2C | UART, SPI, I2C
Clock options | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz

 Specifications |   ATtiny416   |   ATtiny816   |  ATtiny1616   |   ATtiny3216
----------------|---------------|---------------|---------------|----------------
Flash           |    4096 bytes |    8192 bytes |   16384 bytes |   32768 bytes
RAM             |     256 bytes |     512 bytes |    2048 bytes |    2048 bytes
EEPROM          |     128 bytes |     128 bytes |     256 bytes |     256 bytes
GPIO Pins       | 18 (17 usable)| 18 (17 usable)| 18 (17 usable)| 18 (17 usable)
ADC Channels    | 11 | 11 | 11 | 11
DAC             |  1 |  1 |  3 |  3
PWM Channels    |  8 |  8 |  8 |  8
Timer/Counter A |  1 |  1 |  1 |  1
Timer/Counter B |  1 |  1 |  2 |  2
Timer/Counter D |  1 |  1 |  1 |  1
CCL Logic Blocks|  2 (no int) |  2 (no int) |      2 (no int) |  2 (no int)
Event Channels  | 6, 2 sync<br/> 4 async | 6, 2 sync<br/> 4 async | 6, 2 sync<br/> 4 async | 6, 2 sync<br/> 4 async |
Interfaces | UART, SPI, I2C | UART, SPI, I2C | UART, SPI, I2C | UART, SPI, I2C
Clock options | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz

 Specifications |    ATtiny426   |   ATtiny826   |   ATtiny1626  |  ATtiny3226   
----------------|----------------|---------------|---------------|---------------
Flash           |     4096 bytes |    8192 bytes |   16384 bytes |   32768 bytes 
RAM             |      512 bytes |    1024 bytes |    2048 bytes |    3072 bytes 
EEPROM          |      128 bytes |     128 bytes |     256 bytes |     256 bytes 
GPIO Pins       | 18 (17 usable) | 18 (17 usable)| 18 (17 usable)| 18 (17 usable)
ADC Channels    | 15 | 15 | 15 | 15
DAC             |  0 |  0 |  0 |  0
PWM Channels    |  6 |  6 |  6 |  6
Timer/Counter A |  1 |  1 |  1 |  1
Timer/Counter B |  2 |  2 |  2 |  2
Timer/Counter D |  0 |  0 |  0 |  0
CCL Logic Blocks|  4 |  4 |  4 |  4
Event Channels  | 6, 2 sync<br/> 4 async | 6, 2 sync<br/> 4 async | 6, 2 sync<br/> 4 async | 6, 2 sync<br/> 4 async |
Interfaces | 2x UART, SPI, I2C | 2x UART, SPI, I2C | 2x UART, SPI, I2C | 2x UART, SPI, I2C
Clock options | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz

Note: The 0-series and 1-series parts have a 10-bit single-ended ADC with a sampling rate of up to 115 ksps, the 2-series parts have a 12-bit single-ended/differential ADC with a sampling rate of up to 375 ksps. The 2-series parts have a DAC for internal use only.
Users who need to lean heavily on event channels or the CCL are advised to use the 2-series parts. In contrast to the 0/1 series the 2 series has 4 CCL blocks with interrupts, working D-type latch option, and the 6 event channels are normal and well-behaved.

# Preparing Arduino IDE
- [Install megaTinyCore](https://github.com/SpenceKonde/megaTinyCore/blob/master/Installation.md).
- Open the Arduino IDE.
- Go to "Tools" -> "Board" -> "megaTinyCore" and select your chip.
- Go to "Tools" and set the desired board options.
- Go to "Tools" -> "Programmer" and select "SerialUPDI".
- Connect the board via USB to your PC.
- Set the Serial Mode Switch on the board to "P" (Programming Mode).
- Go to "Tools" -> "Burn Bootloader".
- Now you can upload your sketch.

# References, Links and Notes
- [Getting started with the new ATtiny chips](http://www.technoblogy.com/show?2OCH)
- [The ATtiny 2-Series](http://www.technoblogy.com/show?3UKF)
- [megaTinyCore](https://github.com/SpenceKonde/megaTinyCore)
- [ATtiny3216 Datasheet](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATtiny3216-17-DataSheet-DS40002205A.pdf)

![ATtiny3216_pic2.jpg](https://raw.githubusercontent.com/wagiminator/AVR-Development-Boards/master/ATtiny3216_DevBoard_v2/documentation/ATtiny3216_DevBoard_v2_pic2.jpg)
![ATtiny3216_pic3.jpg](https://raw.githubusercontent.com/wagiminator/AVR-Development-Boards/master/ATtiny3216_DevBoard_v2/documentation/ATtiny3216_DevBoard_v2_pic3.jpg)

# License

![license.png](https://i.creativecommons.org/l/by-sa/3.0/88x31.png)

This work is licensed under Creative Commons Attribution-ShareAlike 3.0 Unported License. 
(http://creativecommons.org/licenses/by-sa/3.0/)
