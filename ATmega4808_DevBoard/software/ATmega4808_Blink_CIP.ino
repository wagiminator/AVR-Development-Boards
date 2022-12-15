// ATmega4808 - Blink LED with Core Independent Peripherals
//
// This is just a simple demo on how to use core independent peripherals to
// blink an LED whithout using the CPU. The periodic interrupt timer (PIT)
// directly toggles pin PA7 (which is connected to the builtin LED) via
// channel0 of the event system (EVSYS). Because the CPU isn't needed anymore,
// it is put into sleep mode power down forever.
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

int main(void) {
  PORTA.DIRSET = PIN7_bm;                       // builtin LED as output
  RTC.PITCTRLA = RTC_PITEN_bm;                  // enable PIT
  EVSYS.CHANNEL0 = EVSYS_GENERATOR_RTC_PIT0_gc; // PIT div 8192 as generator
  EVSYS.USEREVOUTA = EVSYS_CHANNEL_CHANNEL0_gc; // port A as user
  PORTMUX.EVSYSROUTEA = PORTMUX_EVOUT0_bm;      // pin 7  as user
  SLPCTRL.CTRLA |= SLPCTRL_SMODE_PDOWN_gc;      // set sleep mode power down
  SLPCTRL.CTRLA |= SLPCTRL_SEN_bm;              // set sleep enable
  sleep_cpu();                                  // go to sleep forever
}
