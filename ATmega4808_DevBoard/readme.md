# ATmega4808 Development Board
Development board for the new ATmega4808 series with integrated USB-to-serial converter, 32.768 kHz crystal for the RTC, 3.3V voltage regulator, support for bootloader and Arduino IDE.

![IMG_20201122_141215_x.jpg](https://image.easyeda.com/pullimage/bv7UeEqS38jVMSSA5YwmlywENO5LUWd5GpY35DGX.jpeg)

# Features of the megaAVR
The ATmega4808 microcontrollers are part of the megaAVR 0-series, which uses the AVR processor with hardware multiplier running at up to 20 MHz from the internal calibrated oscillator. The series uses the latest technologies from Microchip with a flexible and low-power architecture, including Event System and SleepWalking, accurate analog features, and advanced peripherals.
The following microcontrollers can be used with this development board:

|Controller|Flash|SRAM|EEPROM|
|:-|:-|:-|:-|
|ATmega808|8 KB|1 KB|256 B|
|ATmega1608|16 KB|2 KB|256 B|
|ATmega3208|32 KB|4 KB|256 B|
|ATmega4808|48 KB|6 KB|256 B|

All microcontrollers have the following features:
- 27 General purpose I/O
- One 16-bit Timer/Counter type A (TCA) with a dedicated period register and three compare channels
- Three 16-bit Timer/Counters type B (TCB) with input capture
- One 16-bit Real-Time Counter (RTC) running from an external crystal or an internal RC oscillator
- Three USARTs with fractional baud rate generator, auto-baud, and start-of-frame detection
- Master/slave Serial Peripheral Interface (SPI)
- Master/slave TWI (I²C) with dual address match, 
   - can operate simultaneously as master and slave
   - Standard mode (Sm, 100 kHz)
   - Fast mode (Fm, 400 kHz)
   - Fast mode plus (Fm+, 1 MHz)
- Event System for core independent and predictable inter-peripheral signaling
- Configurable Custom Logic (CCL) with up to four programmable Look-up Tables (LUT)
- One Analog Comparator (AC) with a scalable reference input
- One 10-bit 150 ksps Analog-to-Digital Converter (ADC) with 12 channels
- Five selectable internal voltage references: 0.55V, 1.1V, 1.5V, 2.5V, and 4.3V
- Watchdog Timer (WDT) with Window mode, with a separate on-chip oscillator
- External interrupt on all general purpose pins

# Preparing Arduino IDE and Installing Bootloader
- [Install MegaCoreX](https://github.com/MCUdude/MegaCoreX#how-to-install)
- Open the Arduino IDE
- Go to "Tools" -> "Board" -> "MegaCoreX" -> "ATmega4808"
- Go to "Tools" and set the following board options:
   - Clock: "Internal 20 MHz"
   - Pinout: "32 pin standard"
   - Reset pin: "Reset"
   - Bootloader: "Optiboot (UART0 default pins)"
   - Programmer: "jtag2updi(megaTinyCore)"
- Connect the UPDI programmer to the UPDI header on the development board. You can find such programmers in my [projects](https://github.com/wagiminator/AVR-Programmer) or you can use an [Arduino Uno as a UPDI programmer](https://github.com/SpenceKonde/megaTinyCore/blob/master/MakeUPDIProgrammer.md)
- Go to "Tools" -> "Burn Bootloader"
- Disconnect the UPDI programmer and connect the development board via USB to your computer
- Open one of the [example sketches](https://github.com/wagiminator/AVR-Development-Boards/blob/master/ATmega4808_DevBoard/ATmega4808_DevBoard_firmware.zip) and click the "Upload" button

# Example Sketches
To test the board and to learn a thing or two about the new megaAVR, four small [example sketches](https://github.com/wagiminator/AVR-Development-Boards/blob/master/ATmega4808_DevBoard/ATmega4808_DevBoard_firmware.zip) are attached.

|Sketch Name|Description|
|:-|:-|
|ATmega4808_Hello_World.ino|This sketch flashes the built-in LED at 1 Hz and sends a message once per second via the serial interface, which can be displayed on the serial monitor at 9600 baud.|
|ATmega4808_RTC.ino|This sketch implements a real-time clock using the external 32.768 kHz crystal. Every five seconds the current time and date is sent via the serial interface, which can be displayed on the serial monitor at 9600 baud.|
|ATmega4808_blink_PIT.ino|One of the new features is the Periodic Interrupt Timer (PIT), which can run on the internal ultra low-power 32.768 kHz oscillator while the CPU is in sleep mode power down. In this sketch, the PIT wakes the sleeping CPU twice per second in order to toggle the built-in LED.|
|ATmega4808_Blink_CIP.ino|One of the coolest new features are the Core Independent Peripherals (CIPs). Asynchronous peripherals can be connected directly to one another via the Event System (EVSYS) and thus work independently of the CPU. In this example, the built-in LED is flashing while the CPU is in sleep mode power down all the time ... without ever waking up.|

# References, Links and Notes
1. [megaAVR 0-series Family Data Sheet](http://ww1.microchip.com/downloads/en/DeviceDoc/megaAVR0-series-Family-Data-Sheet-DS40002015B.pdf)
2. [ATmega4808 Datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega4808-09-DataSheet-DS40002173B.pdf)
3. [TB3262: Getting Started with Writing C-Code for AVR MCUs](http://ww1.microchip.com/downloads/en/Appnotes/AVR1000b-Getting-Started-Writing-C-Code-for-AVR-DS90003262B.pdf)
4. [TB3213: Getting Started with RTC](http://ww1.microchip.com/downloads/en/Appnotes/TB3213-Getting-Started-with-RTC-DS90003213B.pdf)
5. [AN2451: Getting Started with Core Independent Peripherals](http://ww1.microchip.com/downloads/en/Appnotes/Getting-Started-with-Peripherals-on-AVR-MCU-00002451C.pdf)
6. [AN2515: AVR Low-Power Techniques](http://ww1.microchip.com/downloads/en/Appnotes/AN2515-AVR-Low-Power-Techniques-00002515C.pdf)
7. [AN2543: Temperature Logger with ATtiny817 and SD Card](http://ww1.microchip.com/downloads/en/Appnotes/AN2543-Temperature-Logger-with-ATtiny817-and-SD-Card-v2-00002543C.pdf)

![IMG_20201122_081520_x.jpg](https://image.easyeda.com/pullimage/jHPM6GLFS4yb8MbdF48letGdqqN7pdmElsiTVPeI.jpeg)
![IMG_20201122_081532_x.jpg](https://image.easyeda.com/pullimage/x5FqI2qEoBpFqv6xOdfeim12Fc5r4ZIUS1q72vov.jpeg)

# License
![license.png](https://i.creativecommons.org/l/by-sa/3.0/88x31.png)

This work is licensed under Creative Commons Attribution-ShareAlike 3.0 Unported License. 
(http://creativecommons.org/licenses/by-sa/3.0/)
