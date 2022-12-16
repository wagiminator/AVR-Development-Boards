// ===================================================================================
// Project:   Hello World Demo
// Version:   v1.0
// Year:      2022
// Author:    Stefan Wagner
// Github:    https://github.com/wagiminator
// EasyEDA:   https://easyeda.com/wagiminator
// License:   http://creativecommons.org/licenses/by-sa/3.0/
// ===================================================================================
//
// Description:
// ------------
// Blink the built-in LED and send a message via UART once a second.
//
// Wiring:
// -------
//                            +-\/-+
//                      Vcc  1|°   |14  GND
//         --- !SS AIN4 PA4  2|    |13  PA3 AIN3 SCK ---- 
//         ------- AIN5 PA5  3|    |12  PA2 AIN2 MISO --- 
//         --- DAC AIN6 PA6  4|    |11  PA1 AIN1 MOSI --- 
//     LED ------- AIN7 PA7  5|    |10  PA0 AIN0 UPDI --- USB
//     USB -------- RXD PB3  6|    |9   PB0 AIN11 SCL --- 
//     USB ---------TXD PB2  7|    |8   PB1 AIN10 SDA --- 
//                            +----+
//
// Compilation Settings:
// ---------------------
// Core:          megaTinyCore (https://github.com/SpenceKonde/megaTinyCore)
// Board:         ATtiny1614/1604/814/804/414/404/214/204
// Chip:          choose the one on your board
// Clock:         5 MHz internal
//
// Leave the rest on default settings. Select "SerialUPDI" as programmer in the
// Arduino IDE and set the Serial Mode Switch on the board to "P". Don't forget
// to "Burn bootloader"! Compile and upload the code. Set the Serial Mode Switch
// to "S" and use a serial monitor with 9600 BAUD.
//
// No Arduino core functions or libraries are used. To compile and upload without
// Arduino IDE use the makefile.
//
// Fuse Settings: 0:0x00 1:0x00 2:0x02 4:0x00 5:0xC5 6:0x04 7:0x00 8:0x00


// ===================================================================================
// Libraries and Definitions
// ===================================================================================

// Libraries
#include <avr/io.h>           // for GPIO
#include <util/delay.h>       // for delays

// Firmware Settings
#define PIN_LED     PA7       // pin the LED is connected to
#define UART_BAUD   9600      // UART BAUD rate

// Pin manipulation macros
enum {PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PB0, PB1, PB2, PB3};    // enumerate pin designators
#define pinInput(x)       (&VPORTA.DIR)[((x)&8)>>1] &= ~(1<<((x)&7))  // set pin to INPUT
#define pinOutput(x)      (&VPORTA.DIR)[((x)&8)>>1] |=  (1<<((x)&7))  // set pin to OUTPUT
#define pinLow(x)         (&VPORTA.OUT)[((x)&8)>>1] &= ~(1<<((x)&7))  // set pin to LOW
#define pinHigh(x)        (&VPORTA.OUT)[((x)&8)>>1] |=  (1<<((x)&7))  // set pin to HIGH
#define pinToggle(x)      (&VPORTA.IN )[((x)&8)>>1] |=  (1<<((x)&7))  // TOGGLE pin
#define pinRead(x)        ((&VPORTA.IN)[((x)&8)>>1] &   (1<<((x)&7))) // READ pin
#define pinDisable(x)     (&PORTA.PIN0CTRL)[(((x)&8)<<2)+((x)&7)] |= PORT_ISC_INPUT_DISABLE_gc
#define pinPullup(x)      (&PORTA.PIN0CTRL)[(((x)&8)<<2)+((x)&7)] |= PORT_PULLUPEN_bm
#define pinAIN(x)         ((x)<8 ? (x) : (19-(x)))                    // convert pin to ADC port

// ===================================================================================
// UART TX Implementation (refer to TB3216)
// ===================================================================================

// UART definitions and macros
#define PIN_TXD         PB2                     // UART transmit pin
#define UART_BAUD_RATE  4.0 * F_CPU / UART_BAUD + 0.5
#define UART_ready()    (USART0.STATUS & USART_DREIF_bm)

// UART init
void UART_init(void) {
  pinOutput(PIN_TXD);                           // set TX pin to OUTPUT
  USART0.BAUD   = UART_BAUD_RATE;               // set BAUD
  USART0.CTRLB  = USART_TXEN_bm;                // enable TX
}

// UART transmit data byte
void UART_write(char data) {
  while(!UART_ready());                         // wait until ready for next data
  USART0.TXDATAL = data;                        // send data byte
}

// UART print string
void UART_print(const char *str) {
  while(*str) UART_write(*str++);               // write characters of string
}

// ===================================================================================
// Main Function
// ===================================================================================

int main(void) {
  // Setup
  _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 3);       // set clock frequency to 5 MHz
  UART_init();                                  // init UART TX
  pinOutput(PIN_LED);                           // set LED pin to OUTPUT
  
  // Loop
  while(1) {                                    // loop until forever                         
    pinToggle(PIN_LED);                         // toggle LED pin
    UART_print("Hello World!\n");               // send message via UART
    _delay_ms(1000);                            // 1 sec delay
  }
}
