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
// Blink built-in LED using software resets.
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

#define PIN_LED   PA7             // define LED pin

// ===================================================================================
// Main Function
// ===================================================================================
int main (void) {
  CLK_init();                     // set system clock frequency
  PIN_output(PIN_LED);            // set LED pin as output
  DLY_ms(100);                    // wait a bit
  PIN_toggle(PIN_LED);            // toggle LED
  DLY_ms(100);                    // wait a bit
  RST_now();                      // reset
}