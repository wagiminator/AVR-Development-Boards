// ATmega4808 - Wake up from Sleep by PIT to Blink LED
//
// This is just a simple demo on how to use the periodic interrupt
// timer (PIT) to periodically wake up the CPU from sleep. The ATmega is
// put into sleep and wakes up every 500 ms by the RTC periodic interrupt
// timer (PIT) to toggle an LED.
//
// Controller:  ATmega4808
// Core:        MegaCoreX (https://github.com/MCUdude/MegaCoreX)
// Clock:       doesn't matter
//
// 2020 by Stefan Wagner 
// Project Files (EasyEDA): https://easyeda.com/wagiminator
// Project Files (Github):  https://github.com/wagiminator

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

void setup() {
  PORTA.DIRSET   = PIN7_bm;                 // builtin LED as output
  RTC.PITINTCTRL = RTC_PI_bm;               // enable periodic interrupt
  RTC.PITCTRLA   = RTC_PERIOD_CYC16384_gc   // set period to 500 ms
                 | RTC_PITEN_bm;            // enable PIT
  sei();                                    // enable global interrupts
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);      // set sleep mode
  sleep_enable();                           // enable sleep control
}

void loop() {
  sleep_cpu();                              // go to sleep, wake up by PIT
  PORTA.OUTTGL = PIN7_bm;                   // toggle builtin LED
}

// interrupt service routine for RTC periodic timer
ISR(RTC_PIT_vect) {
  RTC.PITINTFLAGS = RTC_PI_bm;              // clear interrupt flag
}
