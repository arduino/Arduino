// ArduinoISP version 04m3
// Copyright (c) 2008-2011 Randall Bohn
// If you require a license, see
//     http://www.opensource.org/licenses/bsd-license.php
//
// This sketch turns the Arduino into a AVRISP
// using the following arduino pins:
// If using with Arduino Due, connect PC to Native port
//
// pin name:    not-mega:         mega(1280 and 2560)
// slave reset: 10:               53
// MOSI:        11:               51
// MISO:        12:               50
// SCK:         13: (std LED)     52
//
// Put an LED (with resistor) on the following pins:
// 9: Heartbeat   - shows the programmer is running
// 8: Error       - Lights up if something goes wrong (use red if that makes sense)
// 7: Programming - In communication with the slave
//
// 23 July 2011 Randall Bohn
// -Address Arduino issue 509 :: Portability of ArduinoISP
// http://code.google.com/p/arduino/issues/detail?id=509
//
// October 2010 by Randall Bohn
// - Write to EEPROM > 256 bytes
// - Better use of LEDs:
// -- Flash LED_PMODE on each flash commit
// -- Flash LED_PMODE while writing EEPROM (both give visual feedback of writing progress)
// -- Light LED_ERR whenever we hit a STK_NOSYNC. Turn it off when back in sync.
// - Use pins_arduino.h (should also work on Arduino Mega)
//
// October 2009 by David A. Mellis
// - Added support for the read signature command
//
// February 2009 by Randall Bohn
// - Added support for writing to EEPROM (what took so long?)
// Windows users should consider WinAVR's avrdude instead of the
// avrdude included with Arduino software.
//
// January 2008 by Randall Bohn
// - Thanks to Amplificar for helping me with the STK500 protocol
// - The AVRISP/STK500 (mk I) protocol is used in the arduino bootloader
// - The SPI functions herein were developed for the AVR910_ARD programmer
// - More information at http://code.google.com/p/mega-isp


// versions need to be above Atmel programmer to avoid fw update attempts
#define HWVER 2
#define SWMAJ 1
#define SWMIN 18


#define BAUDRATE 19200
//#define BAUDRATE 38400
//#define BAUDRATE 115200

// create clock on digital 9 using pwm (timer1), LED_HB must move
//#define LADYADA_CLOCK

#define RESETDELAY 0

// uncomment if you want to have debug traces
// (needs a separate uart so works only on Sanguino, Leonardo, Due...)
//#define TRACES

// following settings have different defaults on SAM vs. AVR

#ifdef __SAM3X8E__

// Select uart to use for programming and debugging:
#define SERIAL_PRG SerialUSB
#define SERIAL_DBG Serial

// comment USE_HARDWARE_SPI to use bitbang spi 
// use bitbang to make it work with very slow attiny2313
// #define USE_HARDWARE_SPI

#else

// Select uart to use for programming and debugging:
#define SERIAL_PRG Serial
#define SERIAL_DBG Serial1

// comment USE_HARDWARE_SPI to use bitbang spi
// use bitbang to make it work with very slow attiny2313
#define USE_HARDWARE_SPI

#endif

///////////////////////////////////////////////
//   ideally won't need to edit below here   //
///////////////////////////////////////////////



#ifdef USE_HARDWARE_SPI
#include "SPI.h"

#ifdef __AVR__  // this would better go into SPI lib
#define SPI_CLOCK_DIV_MAX  SPI_CLOCK_DIV128
#else
#define SPI_CLOCK_DIV_MAX  255
#endif

#endif

#include "pins_arduino.h"
#define PIN_RESET     SS
#define PIN_SCK       SCK
#define PIN_MOSI      MOSI
#define PIN_MISO      MISO

#define LED_HB    9
#define LED_ERR   8
#define LED_PMODE 7
#define PROG_FLICKER true



#ifdef LADYADA_CLOCK
#ifndef __AVR__
#error "Not yet implemented for non AVR's."
#endif
// needs timer1 PWM
#define CLOCK_PIN 9
#undef  LED_HB
#define LED_HB    6
#endif

#ifdef TRACES
#define TRACE_BEGIN(baud) SERIAL_DBG.begin(baud)
#define TRACE(x) SERIAL_DBG.print(x)
#define TRACELN(x) SERIAL_DBG.println(x)
#define TRACE2(x, format) SERIAL_DBG.print(x, format)
#define TRACE2LN(x, format) SERIAL_DBG.println(x, format)
#else
#define TRACE_BEGIN(baud)
#define TRACE(x)
#define TRACELN(x)
#define TRACE2(x, format)
#define TRACE2LN(x, format)
#endif


// STK Definitions
#define STK_OK      0x10
#define STK_FAILED  0x11
#define STK_UNKNOWN 0x12
#define STK_INSYNC  0x14
#define STK_NOSYNC  0x15
#define CRC_EOP     0x20 //ok it is a space...

void pulse(uint8_t pin, uint8_t times);

#ifndef USE_HARDWARE_SPI

class BitBangedSPI {
public:

  void begin() {
    pinMode(PIN_MISO, INPUT);
    pinMode(PIN_RESET, OUTPUT);
    pinMode(PIN_SCK, OUTPUT);
    pinMode(PIN_MOSI, OUTPUT);
  }

  void end() {}
 
  uint8_t transfer (uint8_t b) {
    for (unsigned int i = 0; i < 8; ++i) {
      digitalWrite(PIN_MOSI, b & 0x80);
      digitalWrite(PIN_SCK, HIGH);
      b = (b << 1) | digitalRead(PIN_MISO);
      digitalWrite(PIN_SCK, LOW); // slow pulse
    }
    return b;
  }
};

static BitBangedSPI SPI;

#endif

void setup(void) {
  SERIAL_PRG.begin(BAUDRATE);
  
#ifdef USE_HARDWARE_SPI
  SPI.setDataMode(0);
  SPI.setBitOrder(MSBFIRST);
  // Clock Div can be 2,4,8,16,32,64, or 128
  SPI.setClockDivider(SPI_CLOCK_DIV_MAX);  
#endif

  pinMode(LED_PMODE, OUTPUT);
  pulse(LED_PMODE, 2);
  pinMode(LED_ERR, OUTPUT);
  pulse(LED_ERR, 2);
  pinMode(LED_HB, OUTPUT);
  pulse(LED_HB, 2);

#ifdef LADYADA_CLOCK
  // setup high freq PWM (timer 1)
  pinMode(CLOCK_PIN, OUTPUT);
  uint8_t sreg = SREG;
  cli(); // disable interrupts to access TCNT1, OCR1A,B
  // 50% duty cycle -> 8 MHz
  OCR1A = 0;
  ICR1 = 1;
  // OC1A output, fast PWM
  TCCR1A = _BV(WGM11) | _BV(COM1A1);
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10); // no clock prescale
  SREG = sreg; // restore interrupts
#endif
  
  TRACE_BEGIN(115200);
  TRACELN("*** setup ***");  
}

uint8_t error=0;
uint8_t pmode=0;
uint8_t buff[256]; // global block storage
// address for reading and writing, set by 'U' command
uint16_t here;

// get multi-byte Big Endian values
#define beget16(addr) ((uint16_t)*(addr) <<  8 | (uint16_t)*((addr)+1) )
#define beget32(a) ((uint32_t)beget16(a) << 16 | (uint32_t)beget16((a)+2) )

struct param {
  uint8_t devicecode;
  uint8_t revision;
  uint8_t progtype;
  uint8_t parmode;
  uint8_t polling;
  uint8_t selftimed;
  uint8_t lockbytes;
  uint8_t fusebytes;
  uint8_t flashpoll;
  //uint8_t ignored;
  uint16_t eeprompoll;
  uint16_t pagesize;
  uint16_t eepromsize;
  uint32_t flashsize;
} param;


// this provides a heartbeat, so you can tell the software is running.
uint8_t hbval=128;
int8_t hbdelta=8;
unsigned long hbprev=0;
void heartbeat(void) {
  if (hbval > 192 || hbval < 32) hbdelta = -hbdelta;
  hbval += hbdelta;
  while (millis()-hbprev < 40); // wait a bit if came back too soon
  analogWrite(LED_HB, hbval);
  hbprev=millis();
}


void loop(void) {
  // is pmode active?
  if (pmode) digitalWrite(LED_PMODE, HIGH);
  else digitalWrite(LED_PMODE, LOW);

  // is there an error?
  if (error) digitalWrite(LED_ERR, HIGH);
  else digitalWrite(LED_ERR, LOW);

  // light the heartbeat LED
  heartbeat();

  if (SERIAL_PRG.available()) {
    avrisp();
  }
}


uint8_t getch(void) {
  while(!SERIAL_PRG.available());
  return SERIAL_PRG.read();
}
void fill(unsigned n) {
  for (unsigned x = 0; x < n; x++) {
    buff[x] = getch();
  }
}

#define PTIME 30
void pulse(uint8_t pin, uint8_t times) {
  do {
    digitalWrite(pin, HIGH);
    delay(PTIME);
    digitalWrite(pin, LOW);
    delay(PTIME);
  }
  while (times--);
}

void prog_lamp(uint8_t state) {
  if (PROG_FLICKER)
    digitalWrite(LED_PMODE, state);
}

uint8_t spi_transaction(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
  SPI.transfer(a);
  SPI.transfer(b);
  SPI.transfer(c);
  return SPI.transfer(d);
}


void empty_reply(void) {
  if (CRC_EOP == getch()) {
    SERIAL_PRG.print((char)STK_INSYNC);
    SERIAL_PRG.print((char)STK_OK);
  }
  else {
    error++;
    SERIAL_PRG.print((char)STK_NOSYNC);
  }
}

void breply(uint8_t b) {
  if (CRC_EOP == getch()) {
    SERIAL_PRG.print((char)STK_INSYNC);
    SERIAL_PRG.print((char)b);
    SERIAL_PRG.print((char)STK_OK);
  }
  else {
    error++;
    SERIAL_PRG.print((char)STK_NOSYNC);
  }
}

void get_version(uint8_t c) {
  switch(c) {
  case 0x80:
    breply(HWVER);
    break;
  case 0x81:
    breply(SWMAJ);
    break;
  case 0x82:
    breply(SWMIN);
    break;
  case 0x93:
    breply('S'); // serial programmer
    break;
  default:
    breply(0);
  }
}

void set_parameters(void) {
  // call this after reading paramter packet into buff[]
  param.devicecode = buff[0];
  param.revision   = buff[1];
  param.progtype   = buff[2];
  param.parmode    = buff[3];
  param.polling    = buff[4];
  param.selftimed  = buff[5];
  param.lockbytes  = buff[6];
  param.fusebytes  = buff[7];
  param.flashpoll  = buff[8];
  // ignore buff[9] (= buff[8])
  // following are 16 bits (big endian)
  param.eeprompoll = beget16(&buff[10]);
  param.pagesize   = beget16(&buff[12]);
  param.eepromsize = beget16(&buff[14]);
  // 32 bits flashsize (big endian)
  param.flashsize = beget32(&buff[16]);
}

void start_pmode(void) {
  pmode = 1;

  // reset target before driving SCK or MOSI
  digitalWrite(PIN_RESET, LOW);
  digitalWrite(PIN_SCK, LOW);
  digitalWrite(PIN_MOSI, HIGH);

  pinMode(PIN_MISO, INPUT);
  pinMode(PIN_RESET, OUTPUT); // PIN_RESET not always SS: Leonardo, Due...
  SPI.begin(); // now SS, MOSI and SCK are output

  // See datasheets: "SERIAL_PRG Programming Algorithm":
  delay(5); // choosen arbitrarilly
  // pulse RESET high after SCK is low
  digitalWrite(PIN_RESET, HIGH);
  delay(1); // must be minimum 2 CPU clock cycles
  digitalWrite(PIN_RESET, LOW);
  delay(50); // minimum 20 ms
  if (RESETDELAY) delay(RESETDELAY);
  spi_transaction(0xAC, 0x53, 0x00, 0x00);
}

void end_pmode(void) {
  SPI.end();
  pinMode(PIN_MOSI, INPUT);
  pinMode(PIN_SCK, INPUT);
  pinMode(PIN_RESET, INPUT);
  pmode = 0;
}

void universal(void) {
  uint8_t ch;
  fill(4);
  ch = spi_transaction(buff[0], buff[1], buff[2], buff[3]);
  breply(ch);
}

#define flash_write_cmd(hilo, addr, data) \
    spi_transaction(0x40|((hilo)<<3), (addr)>>8 & 0xFF, (addr) & 0xFF, (data))

#define flash_read_cmd(hilo, addr) \
    spi_transaction(0x20|((hilo)<<3), (addr)>>8 & 0xFF, (addr) & 0xFF, 0)


void commit(uint16_t addr) {
  if (PROG_FLICKER) prog_lamp(LOW);
  spi_transaction(0x4C, (addr >> 8) & 0xFF, addr & 0xFF, 0);
  if (PROG_FLICKER) {
    delay(PTIME);
    prog_lamp(HIGH);
  }
}

uint16_t current_page(uint16_t addr) {
  if (param.pagesize == 32)  return here & 0xFFF0;
  if (param.pagesize == 64)  return here & 0xFFE0;
  if (param.pagesize == 128) return here & 0xFFC0;
  if (param.pagesize == 256) return here & 0xFF80;
  return here;
}


void write_flash(unsigned length) {
  fill(length);
  if (CRC_EOP == getch()) {
    SERIAL_PRG.print((char) STK_INSYNC);
    SERIAL_PRG.print((char) write_flash_pages(length));
  }
  else {
    error++;
    SERIAL_PRG.print((char) STK_NOSYNC);
  }
}

uint8_t write_flash_pages(unsigned length) {
  unsigned x = 0;
  uint16_t page = current_page(here);
  while (x < length) {
    if (page != current_page(here)) {
      commit(page);
      page = current_page(here);
    }
    flash_write_cmd(LOW,  here, buff[x++]);
    flash_write_cmd(HIGH, here, buff[x++]);
    here++;
  }

  commit(page);

  return STK_OK;
}

#define EECHUNK (32)
uint8_t write_eeprom(unsigned length) {
  // here is a word address, get the byte address
  uint16_t start = here << 1;
  if (length > param.eepromsize) {
    error++;
    return STK_FAILED;
  }
  while (length > EECHUNK) {
    write_eeprom_chunk(start, EECHUNK);
    start += EECHUNK;
    length -= EECHUNK;
  }
  write_eeprom_chunk(start, length);
  return STK_OK;
}
// write (length) bytes, (start) is a byte address
uint8_t write_eeprom_chunk(uint16_t addr, unsigned length) {
  // this writes byte-by-byte,
  // page writing may be faster (4 bytes at a time)
  fill(length);
  prog_lamp(LOW);
  for (unsigned x = 0; x < length; x++, addr++) {
    spi_transaction(0xC0, (addr>>8) & 0xFF, addr & 0xFF, buff[x]);
    delay(45);
  }
  prog_lamp(HIGH);
  return STK_OK;
}

void program_page(void) {
  char result = (char) STK_FAILED;
  unsigned length = getch()<<8;
  length |= getch();
  char memtype = getch();
  // flash memory @here, (length) bytes
  if (memtype == 'F') {
    write_flash(length);
    return;
  }
  if (memtype == 'E') {
    result = (char)write_eeprom(length);
    if (CRC_EOP == getch()) {
      SERIAL_PRG.print((char) STK_INSYNC);
      SERIAL_PRG.print(result);
    }
    else {
      error++;
      SERIAL_PRG.print((char) STK_NOSYNC);
    }
    return;
  }
  SERIAL_PRG.print((char)STK_FAILED);
}

char flash_read_page(unsigned length) {
  for (unsigned x = 0; x < length; x+=2) {
    char ch;
    ch = flash_read_cmd(LOW,  here);
    SERIAL_PRG.print(ch);
    ch = flash_read_cmd(HIGH, here);
    SERIAL_PRG.print(ch);
    here++;
  }
  return STK_OK;
}

char eeprom_read_page(unsigned length) {
  // here again we have a word address
  uint16_t addr = here << 1;
  for (unsigned x = 0; x < length; x++, addr++) {
    uint8_t ee = spi_transaction(0xA0, (addr >> 8) & 0xFF, addr & 0xFF, 0xFF);
    SERIAL_PRG.print((char) ee);
  }
  return STK_OK;
}

void read_page(void) {
  char result = (char)STK_FAILED;
  unsigned length = getch() << 8;
  length |= getch();
  char memtype = getch();
  if (CRC_EOP != getch()) {
    error++;
    SERIAL_PRG.print((char) STK_NOSYNC);
    return;
  }
  SERIAL_PRG.print((char) STK_INSYNC);
  if (memtype == 'F') result = flash_read_page(length);
  if (memtype == 'E') result = eeprom_read_page(length);
  SERIAL_PRG.print(result);
}

void read_signature(void) {
  if (CRC_EOP != getch()) {
    error++;
    SERIAL_PRG.print((char) STK_NOSYNC);
    return;
  }
  SERIAL_PRG.print((char) STK_INSYNC);
  char ch;
  ch = spi_transaction(0x30, 0x00, 0x00, 0x00);
  SERIAL_PRG.print(ch);
  ch = spi_transaction(0x30, 0x00, 0x01, 0x00);
  SERIAL_PRG.print(ch);
  ch = spi_transaction(0x30, 0x00, 0x02, 0x00);
  SERIAL_PRG.print(ch);
  SERIAL_PRG.print((char) STK_OK);
}
//////////////////////////////////////////
//////////////////////////////////////////



////////////////////////////////////
////////////////////////////////////
void avrisp(void) {
  uint8_t data, low, high;
  uint8_t ch = getch();
  TRACE("> ");  
  TRACELN((char) ch);
  switch (ch) {
  case '0': // signon
    error = 0;
    empty_reply();
    break;
  case '1':
    if (getch() == CRC_EOP) {
      SERIAL_PRG.print((char) STK_INSYNC);
      SERIAL_PRG.print("AVR ISP");
      SERIAL_PRG.print((char) STK_OK);
    } else {
      error++;
      SERIAL_PRG.print((char) STK_NOSYNC);
    }
    break;
  case 'A':
    get_version(getch());
    break;
  case 'B':
    fill(20);
    set_parameters();
    empty_reply();
    break;
  case 'E': // extended parameters - ignore for now
    fill(5);
    empty_reply();
    break;

  case 'P':
    if (pmode) {
      pulse(LED_ERR, 3);
    } else {
      start_pmode();
    }
    empty_reply();
    break;
  case 'U': // set address (word)
    here = getch();
    here |= getch()<<8;
    empty_reply();
    break;

  case 0x60: //STK_PROG_FLASH
    low = getch();
    high = getch();
    empty_reply();
    break;
  case 0x61: //STK_PROG_DATA
    data = getch();
    empty_reply();
    break;

  case 0x64: //STK_PROG_PAGE
    program_page();
    break;

  case 0x74: //STK_READ_PAGE 't'
    read_page();
    break;

  case 'V': //0x56
    universal();
    break;
  case 'Q': //0x51
    error=0;
    end_pmode();
    empty_reply();
    break;

  case 0x75: //STK_READ_SIGN 'u'
    read_signature();
    break;

    // expecting a command, not CRC_EOP
    // this is how we can get back in sync
  case CRC_EOP:
    error++;
    SERIAL_PRG.print((char) STK_NOSYNC);
    break;

    // anything else we will return STK_UNKNOWN
  default:
    error++;
    if (CRC_EOP == getch())
      SERIAL_PRG.print((char)STK_UNKNOWN);
    else
      SERIAL_PRG.print((char)STK_NOSYNC);
  }
}

