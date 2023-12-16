// ATmega4808 - RTC Test
//
// This is just a simple test of the real timer counter (RTC) with an attached
// 32.768 kHz crystal. With a prescaler of 32768 the RTC counts every second.
// A message is transmitted via the serial interface every 5 seconds (RTC period).
//
// Controller:  ATmega4808
// Core:        MegaCoreX (https://github.com/MCUdude/MegaCoreX)
// Clock:       Internal 20 MHz
//
// Code is based on Microchip's Application Note AN2543:
// https://www.microchip.com//wwwAppNotes/AppNotes.aspx?appnote=en592095
// and Microchip's Technical Brief TB3213:
// https://www.microchip.com/wwwappnotes/appnotes.aspx?appnote=en609105
//
// 2020 by Stefan Wagner 
// Project Files (EasyEDA): https://easyeda.com/wagiminator
// Project Files (Github):  https://github.com/wagiminator

#include <avr/io.h>
#include <avr/interrupt.h>

typedef uint8_t bool;
#define true  1
#define false 0

#define UPDATE_PERIOD     5       // update period in seconds
#define USE_EXTERNAL_OSC  true    // set FALSE to use internal 32k OSC

typedef struct {
  uint8_t  second;
  uint8_t  minute;
  uint8_t  hour;
  uint8_t  date;
  uint8_t  month;
  uint16_t year;
} time;

volatile time        t;
volatile static bool tick = false;


void setup() {
  Serial.begin(9600);                     // start serial interface
  PORTA.OUTCLR = PIN7_bm;                 // builtin LED off
  PORTA.DIRSET = PIN7_bm;                 // builtin LED as output
  process_start_time();                   // set time to compile time
  if (USE_EXTERNAL_OSC) RTC_setCrystal(); // set external crystal if selected
  RTC_init();                             // setup RTC
  sei();                                  // enable global interrupts
}

void loop() {
  if (tick) {                             // if tick flag is set
    PORTA.OUTSET = PIN7_bm;               // builtin LED on
    update_time();                        // update time
    Serial.print("Hello World ! - ");     // send message
    sendTime();                           // send time
    tick = false;                         // clear flag
    PORTA.OUTCLR = PIN7_bm;               // builtin LED off
  }
}

// setup external 32.768 kHz crystal for RTC (refer to TB3213)
void RTC_setCrystal() {
  uint8_t temp;
    
  // disable oscillator first
  temp = CLKCTRL.XOSC32KCTRLA;
  temp &= ~CLKCTRL_ENABLE_bm;
  CPU_CCP = CCP_IOREG_gc;
  CLKCTRL.XOSC32KCTRLA = temp;

  // wait for status bit to become '0'
  while(CLKCTRL.MCLKSTATUS & CLKCTRL_XOSC32KS_bm);

  // select external crystal for RTC
  temp = CLKCTRL.XOSC32KCTRLA;
  temp &= ~CLKCTRL_SEL_bm;
  CPU_CCP = CCP_IOREG_gc;
  CLKCTRL.XOSC32KCTRLA = temp;

  // enable the oscillator
  temp = CLKCTRL.XOSC32KCTRLA;
  temp |= CLKCTRL_ENABLE_bm | CLKCTRL_RUNSTDBY_bm;
  CPU_CCP = CCP_IOREG_gc;
  CLKCTRL.XOSC32KCTRLA = temp;

  // wait for all registers to be synchronized
  while (RTC.STATUS > 0);

  // select 32.768 kHz external crystal oscillator
  RTC.CLKSEL = RTC_CLKSEL_TOSC32K_gc;

  /*
  _PROTECTED_WRITE(CLKCTRL_XOSC32KCTRLA, (CLKCTRL_ENABLE_bm | CLKCTRL_RUNSTDBY_bm));
  while (!(CLKCTRL.MCLKSTATUS & CLKCTRL_XOSC32KS_bm));
  RTC.CLKSEL = RTC_CLKSEL_TOSC32K_gc;
  }
  */
}

// setup the RTC (refer to AN2543)
void RTC_init(void) {
  RTC.CTRLA = RTC_RUNSTDBY_bm               // enable RTC in standby
            | RTC_PRESCALER_DIV32768_gc;    // prescale for 1 second
  while (RTC.STATUS & RTC_CTRLABUSY_bm);    // wait for done
  RTC.PER = UPDATE_PERIOD;                  // set RTC period
  while (RTC.STATUS & RTC_PERBUSY_bm);      // wait for done
  RTC.INTFLAGS = 0xFF;                      // clear interrupt flags
  RTC.INTCTRL = RTC_OVF_bm;                 // enable interrupt on overflow
  RTC.CTRLA |= RTC_RTCEN_bm;                // enable RTC
  while (RTC.STATUS & RTC_CTRLABUSY_bm);    // wait for done
}

// update time (refer to AN2543)
void update_time() {
  t.second += UPDATE_PERIOD;
  if (t.second >= 60) {
    t.second -= 60;
    if (++t.minute == 60) {
      t.minute = 0;
      if (++t.hour == 24) {
        t.hour = 0;
        if (++t.date == 32) {
          t.month++;
          t.date = 1;
        } else if (t.date == 31) {
          if ((t.month == 4) || (t.month == 6) || (t.month == 9) || (t.month == 11)) {
            t.month++;
            t.date = 1;
          }
        } else if (t.date == 30) {
          if (t.month == 2) {
            t.month++;
            t.date = 1;
          }
        } else if (t.date == 29) {
          if ((t.month == 2) && (not_a_leap_year())) {
            t.month++;
            t.date = 1;
          }
        }
        if (t.month == 13) {
          t.year++;
          t.month = 1;
        }
      }
    }
  }
}

// returns TRUE if year is NOT a leap year (refer to AN2543)
uint8_t not_a_leap_year() {
  if (!(t.year % 100)) {
    return (t.year % 400);
  } else {
    return (t.year % 4);
  }
}

// get compile date and time to use as initial time (refer to AN2543)
void process_start_time(void) {
  char *ptr = __DATE__;

  // month
  if (*ptr == 'J') {
    ptr++;
    if (*ptr == 'a') {
      t.month = 1;
      ptr += 3;
    } else if (*ptr == 'u') {
      ptr++;
      if (*ptr == 'n') {
        t.month = 6;
      } else if (*ptr == 'l') {
        t.month = 7;
      }
      ptr += 2;
    }
  } else if (*ptr == 'F') {
    t.month = 2;
    ptr += 4;
  } else if (*ptr == 'M') {
    ptr += 2;
    if (*ptr == 'r') {
      t.month = 3;
    } else if (*ptr == 'y') {
      t.month = 5;
    }
    ptr += 2;
  } else if (*ptr == 'A') {
    ptr++;
    if (*ptr == 'p') {
      t.month = 5;
    } else if (*ptr == 'u') {
      t.month = 8;
    }
    ptr += 3;
  } else if (*ptr == 'S') {
    t.month = 9;
    ptr += 4;
  } else if (*ptr == 'O') {
    t.month = 10;
    ptr += 4;
  } else if (*ptr == 'N') {
    t.month = 11;
    ptr += 4;
  } else if (*ptr == 'D') {
    t.month = 12;
    ptr += 4;
  }

  // day
  char date[3] = {*ptr, *(ptr + 1), '\0'};
  t.date       = atoi(date);
  ptr += 3;
  
  // year
  char year[5] = {*ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3), '\0'};
  t.year       = atoi(year);

  ptr = __TIME__;
  
  // hour
  date[0] = *ptr;
  date[1] = *(ptr + 1);
  ptr += 3;
  t.hour = atoi(date);
  
  // minute
  date[0] = *ptr;
  date[1] = *(ptr + 1);
  ptr += 3;
  t.minute = atoi(date);
  
  // second
  date[0] = *ptr;
  date[1] = *(ptr + 1);
  ptr += 3;
  t.second = atoi(date);
}

// send 2-digit value via UART
void sendByte(uint8_t value) {
  Serial.print(value / 10);
  Serial.print(value % 10);
}

// send time stamp via UART
void sendTime() {
  sendByte(t.hour);   Serial.print(':');
  sendByte(t.minute); Serial.print(':');
  sendByte(t.second); Serial.print(" - ");
  sendByte(t.date);   Serial.print('.');
  sendByte(t.month);  Serial.print('.');
  Serial.println(t.year);
}

// interrupt service routine for RTC counter overflow
ISR(RTC_CNT_vect) {
  RTC.INTFLAGS = 0xFF;              // clear interrupt flag
  tick = true;                      // raise tick flag
}
