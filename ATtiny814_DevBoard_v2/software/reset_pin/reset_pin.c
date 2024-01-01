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
// Software-defined reset pin.
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
#include "system.h"               // for system functions
#include "gpio.h"                 // for GPIO functions

#define PIN_RST   PA4             // define reset pin
#define PIN_LED   PA7             // define LED pin

// ===================================================================================
// Pin Interrupt Service Routine (entered when reset pin low)
// ===================================================================================
ISR(PORTA_PORT_vect) {
  RST_now();                      // perform software reset
}

// ===================================================================================
// Main Function
// ===================================================================================
int main (void) {
  CLK_init();                     // set system clock frequency
  PIN_output(PIN_LED);            // set LED pin as output
  PIN_pullup(PIN_RST);            // internal pullup resistor on reset pin
  PIN_INT_level(PIN_RST);         // low level interrupt for reset pin
  INT_enable();                   // global interrupt enable
  PIN_toggle(PIN_LED);            // toggle LED
  while(1);                       // wait for reset
}
