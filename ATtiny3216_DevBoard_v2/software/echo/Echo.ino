// ===================================================================================
// Project:   Serial Echo Demo - ATtiny3216
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
// Simple USB-Serial demo which echoes back all received messages.
//
// Wiring:
// -------
//                             +--\/--+
//                       Vcc  1|°     |20  GND
//         ---- !SS AIN4 PA4  2|      |19  PA3 AIN3 SCK ---- 
//         -------- AIN5 PA5  3|      |18  PA2 AIN2 MISO --- 
//         ---- DAC AIN6 PA6  4|      |17  PA1 AIN1 MOSI --- 
//     LED -------- AIN7 PA7  5|      |16  PA0 AIN0 UPDI --- USB
//         -------- AIN8 PB5  6|      |15  PC3 -------------
//         -------- AIN9 PB4  7|      |14  PC2 -------------
//     USB --------- RXD PB3  8|      |13  PC1 -------------
//     USB --------- TXD PB2  9|      |12  PC0 -------------
//         --- SDA AIN10 PB1 10|      |11  PB0 AIN11 SCL --- 
//                             +------+
//
// Compilation Settings:
// ---------------------
// Core:          megaTinyCore (https://github.com/SpenceKonde/megaTinyCore)
// Board:         ATtiny3216/3206/1616/1606/816/806/416/406
// Chip:          choose the one on your board
// Clock:         5 MHz internal
//
// Leave the rest on default settings. Select "SerialUPDI" as programmer in the
// Arduino IDE and set the Serial Mode Switch on the board to "UPDI". Don't forget
// to "Burn bootloader"! Compile and upload the code. Set the Serial Mode Switch
// to "UART" and use a serial monitor with 9600 BAUD.
//
// No Arduino core functions or libraries are used. Use the makefile to compile
// and upload without Arduino IDE.
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

// Enumerate pin designators
enum {PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, 
      PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7,
      PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7};

// Pin manipulation macros
#define pinInput(x)       (&VPORTA.DIR)[((x)&24)>>1] &= ~(1<<((x)&7))  // set pin to INPUT
#define pinOutput(x)      (&VPORTA.DIR)[((x)&24)>>1] |=  (1<<((x)&7))  // set pin to OUTPUT
#define pinLow(x)         (&VPORTA.OUT)[((x)&24)>>1] &= ~(1<<((x)&7))  // set pin to LOW
#define pinHigh(x)        (&VPORTA.OUT)[((x)&24)>>1] |=  (1<<((x)&7))  // set pin to HIGH
#define pinToggle(x)      (&VPORTA.IN )[((x)&24)>>1] |=  (1<<((x)&7))  // TOGGLE pin
#define pinRead(x)        ((&VPORTA.IN)[((x)&24)>>1] &   (1<<((x)&7))) // READ pin
#define pinDisable(x)     (&PORTA.PIN0CTRL)[(((x)&24)<<2)+((x)&7)] |= PORT_ISC_INPUT_DISABLE_gc
#define pinPullup(x)      (&PORTA.PIN0CTRL)[(((x)&24)<<2)+((x)&7)] |= PORT_PULLUPEN_bm
#define pinAIN(x)         ((x)<8 ? (x) : (19-(x)))                    // convert pin to ADC port

// ===================================================================================
// UART RX/TX Implementation (refer to TB3216)
// ===================================================================================

// UART definitions and macros
#define PIN_TXD           PB2                   // UART transmit pin
#define UART_BAUD_RATE    4.0 * F_CPU / UART_BAUD + 0.5
#define UART_ready()      (USART0.STATUS & USART_DREIF_bm)
#define UART_available()  (USART0.STATUS & USART_RXCIF_bm)
#define UART_get()        (USART0.RXDATAL)
#define UART_put(x)       USART0.TXDATAL = (x)

// UART init
void UART_init(void) {
  pinOutput(PIN_TXD);                           // set TX pin to OUTPUT
  USART0.BAUD  = UART_BAUD_RATE;                // set BAUD
  USART0.CTRLB = USART_RXEN_bm | USART_TXEN_bm; // enable RX and TX
}

// UART transmit data byte
void UART_write(char data) {
  while(!UART_ready());                         // wait until ready for next data
  UART_put(data);                               // send data byte
}

// UART receive data byte
uint8_t UART_read(void) {
  while(!UART_available());                     // wait until received something
  return UART_get();                            // read and return received data
}

// ===================================================================================
// Main Function
// ===================================================================================

int main(void) {
  // Setup
  _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 3);       // set clock frequency to 5 MHz
  UART_init();                                  // init UART TX
  pinOutput(PIN_LED);                           // set LED pin to OUTPUT
  pinHigh(PIN_LED);                             // light up LED
  
  // Loop
  while(1) {                                    // loop until forever                         
    UART_write(UART_read());                    // echo received character
  }
}
