# ATtiny x04/x14 Development Board
Development board for ATtiny x04/x14 series with USB to serial converter and Arduino IDE support.

# Features of the tinyAVR

 Specifications |  ATtiny204|  ATtiny404  |  ATtiny804  |    ATtiny1604
:------------ | :------------- | :------------- | :------------- | :-------------
Flash (program memory)   | 2048 bytes | 4096 bytes | 8192 bytes | 16384 bytes
Flash w/Optiboot   | 1536 bytes | 3584 bytes | 7680 bytes | 15872 bytes
RAM  | 128 bytes | 256 bytes | 512 bytes | 1024 bytes
EEPROM | 64 bytes | 128 bytes | 128 bytes | 256 bytes
Bootloader | Optiboot (optional, not recommended) | Optiboot (optional, not recommended) | Optiboot (optional) | Optiboot (optional)
GPIO Pins | 12 (11 usable) | 12 (11 usable) | 12 (11 usable) | 12 (11 usable)
ADC Channels | 10 (9 usable) | 10 (9 usable) | 10 (9 usable) | 10 (9 usable)
DAC | No | No | No | No
PWM Channels | 6 | 6 | 6 | 6
Timer Type B| 1 | 1 | 1 | 1
Timer Type D | No | No | No | No
Interfaces | UART, SPI, I2C | UART, SPI, I2C | UART, SPI, I2C | UART, SPI, I2C
Clock options | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz

 Specifications |  ATtiny214|  ATtiny414  |  ATtiny814  |    ATtiny1614
:------------ | :------------- | :------------- | :------------- | :-------------
Flash (program memory)   | 2048 bytes | 4096 bytes | 8192 bytes | 16384 bytes
Flash w/Optiboot   | 1536 bytes | 3584 bytes | 7680 bytes | 15872 bytes
RAM  | 128 bytes | 256 bytes | 512 bytes | 2048 bytes
EEPROM | 64 bytes | 128 bytes | 128 bytes | 256 bytes
Bootloader | Optiboot (optional, not recommended) | Optiboot (optional, not recommended)| Optiboot (optional) | Optiboot (optional)
GPIO Pins | 12 (11 usable) | 12 (11 usable) | 12 (11 usable) | 12 (11 usable)
ADC Channels | 10 (9 usable) | 10 (9 usable) | 10 (9 usable) | 10 (9 usable)
DAC | Yes | Yes | Yes | Yes
PWM Channels | 6 | 6 | 6 | 6
Timer Type B | 1 | 1 | 1 | 2
Timer Type D | Yes | Yes | Yes | Yes
Interfaces | UART, SPI, I2C | UART, SPI, I2C | UART, SPI, I2C | UART, SPI, I2C
Clock options | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz | Internal 20/16/10/8/5/4/1 MHz

Reference: https://github.com/SpenceKonde/megaTinyCore

# Pinout
![ATtiny814_pinout.png](https://raw.githubusercontent.com/wagiminator/AVR-Development-Boards/master/ATtiny814_DevBoard/ATtiny814_DevBoard_pinout.png)

# Preparing Arduino IDE
- [Install megaTinyCore](https://github.com/SpenceKonde/megaTinyCore/blob/master/Installation.md)
- Open the Arduino IDE
- Go to "Tools" -> "Board" -> "megaTinyCore" and select your chip
- Go to "Tools" and set the desired board options
- Go to "Tools" -> "Programmer" and select "jtag2updi(megaTinyCore)"
- Connect the UPDI programmer to the UPDI header on the development board. You can find such programmers in my [projects](https://github.com/wagiminator/AVR-Programmer) or you can use an [Arduino Uno as a UPDI programmer](https://github.com/SpenceKonde/megaTinyCore/blob/master/MakeUPDIProgrammer.md).
- Go to "Tools" -> "Burn Bootloader"
- Now you can upload your sketch

# References, Links and Notes
- Getting started with the new ATtiny chips: http://www.technoblogy.com/show?2OCH
- megaTinyCore: https://github.com/SpenceKonde/megaTinyCore
- UPDI Programmer based on ATmega: https://easyeda.com/wagiminator/y-updi-programmer
- Mini UPDI Programmer based on ATtiny1604: https://easyeda.com/wagiminator/attiny1604-updi-programmer
- Development board for ATtiny x16/x06 series: https://easyeda.com/wagiminator/y-attiny3216-development-board-smd

![ATtiny814_pic1.jpg](https://raw.githubusercontent.com/wagiminator/AVR-Development-Boards/master/ATtiny814_DevBoard/ATtiny814_DevBoard_pic1.jpg)
![ATtiny814_pic2.jpg](https://raw.githubusercontent.com/wagiminator/AVR-Development-Boards/master/ATtiny814_DevBoard/ATtiny814_DevBoard_pic2.jpg)

# License

![license.png](https://i.creativecommons.org/l/by-sa/3.0/88x31.png)

This work is licensed under Creative Commons Attribution-ShareAlike 3.0 Unported License. 
(http://creativecommons.org/licenses/by-sa/3.0/)
