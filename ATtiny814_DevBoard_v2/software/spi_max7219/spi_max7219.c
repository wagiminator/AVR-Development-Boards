// ===================================================================================
// Project:   Example for ATtiny814
// Version:   v1.0
// Year:      2021
// Author:    Stefan Wagner
// Github:    https://github.com/wagiminator
// EasyEDA:   https://easyeda.com/wagiminator
// License:   http://creativecommons.org/licenses/by-sa/3.0/
// ===================================================================================
//
// Description:
// ------------
// Prints numbers on a MAX7219 8-digit 7-segment display using hardware-SPI.
//
// Compilation Instructions:
// -------------------------
// - Make sure GCC toolchain (gcc-avr, avr-libc) and Python3 with PySerial is
//   installed. If necessary, a driver for the USB-to-serial converter used by the
//   SerialUPDI programmer must be installed.
// - Connect the SerialUPDI programmer to the UPDI pin of the MCU.
// - Run 'make flash'.


// ===================================================================================
// Libraries, Definitions and Macros
// ===================================================================================
#include "system.h"                     // system functions
#include "gpio.h"                       // GPIO functions
#include "spi.h"                        // SPI functions

#define PIN_CS    PA4                   // define CS pin
#define PIN_LED   PA7                   // define LED pin

// ===================================================================================
// MAX7219 8-Digit 7-Segment Display Implementation
// ===================================================================================

// MAX7219 send command
void SEG_send(uint8_t reg, uint8_t data) {
  PIN_low(PIN_CS);                      // set CS low  -> select device
  SPI_transfer(reg);                    // send address byte
  SPI_transfer(data);                   // send data byte
  PIN_high(PIN_CS);                     // set CS high -> latch the bytes
}

// MAX7219 print a number on display
void SEG_print(uint32_t number) {
  for(uint8_t i=1; i<9; i++, number /= 10) SEG_send(i, number % 10);
}

// MAX7219 init
void SEG_init(void) {
  PIN_output(PIN_CS);                   // set CS pin to output
  PIN_high(PIN_CS);                     // set CS high (unselect device)
  SPI_init();                           // init SPI
  SEG_send(0x09, 0xff);                 // set BCD decode for 8 digits
  SEG_send(0x0a, 0x0f);                 // set intensity (0x00 .. 0x0f)
  SEG_send(0x0b, 0x07);                 // set scan limit at 8 digits
  SEG_send(0x0c, 0x01);                 // shutdown mode off
  SEG_send(0x0f, 0x00);                 // display test off
}

// ===================================================================================
// Main Function
// ===================================================================================
int main (void) {
  // Setup
  CLK_init();                           // set system clock frequency
  DLY_ms(500);                          // wait a bit for MAX7219
  SEG_init();                           // init MAX7219 7-segment display

  // Loop
  while (1) {
    for(uint32_t i=0; i<100000000; i++) { // print numbers 0 - 99999999
      SEG_print(i);                     // print number
      DLY_ms(10);                       // wait a bit
    }
  }
}
