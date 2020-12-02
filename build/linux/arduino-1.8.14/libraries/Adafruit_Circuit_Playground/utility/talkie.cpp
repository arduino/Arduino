// Talkie library
// Copyright 2011 Peter Knight
// This code is released under GPLv2 license.

#include "Adafruit_CPlay_Speaker.h"

#define FS    8000                        // Speech engine sample rate
#define TICKS (FS / 40)                   // Speech data rate
#define USEC  ((1000000 + (FS / 2)) / FS) // Sample period (microseconds)

static const uint16_t PROGMEM
  tmsK1[]     = {0x82C0,0x8380,0x83C0,0x8440,0x84C0,0x8540,0x8600,0x8780,
                 0x8880,0x8980,0x8AC0,0x8C00,0x8D40,0x8F00,0x90C0,0x92C0,
                 0x9900,0xA140,0xAB80,0xB840,0xC740,0xD8C0,0xEBC0,0x0000,
                 0x1440,0x2740,0x38C0,0x47C0,0x5480,0x5EC0,0x6700,0x6D40},
  tmsK2[]     = {0xAE00,0xB480,0xBB80,0xC340,0xCB80,0xD440,0xDDC0,0xE780,
                 0xF180,0xFBC0,0x0600,0x1040,0x1A40,0x2400,0x2D40,0x3600,
                 0x3E40,0x45C0,0x4CC0,0x5300,0x5880,0x5DC0,0x6240,0x6640,
                 0x69C0,0x6CC0,0x6F80,0x71C0,0x73C0,0x7580,0x7700,0x7E80};

static const uint8_t PROGMEM
  tmsK3[]     = {0x92,0x9F,0xAD,0xBA,0xC8,0xD5,0xE3,0xF0,
                 0xFE,0x0B,0x19,0x26,0x34,0x41,0x4F,0x5C},
  tmsK4[]     = {0xAE,0xBC,0xCA,0xD8,0xE6,0xF4,0x01,0x0F,
                 0x1D,0x2B,0x39,0x47,0x55,0x63,0x71,0x7E},
  tmsK5[]     = {0xAE,0xBA,0xC5,0xD1,0xDD,0xE8,0xF4,0xFF,
                 0x0B,0x17,0x22,0x2E,0x39,0x45,0x51,0x5C},
  tmsK6[]     = {0xC0,0xCB,0xD6,0xE1,0xEC,0xF7,0x03,0x0E,
                 0x19,0x24,0x2F,0x3A,0x45,0x50,0x5B,0x66},
  tmsK7[]     = {0xB3,0xBF,0xCB,0xD7,0xE3,0xEF,0xFB,0x07,
                 0x13,0x1F,0x2B,0x37,0x43,0x4F,0x5A,0x66},
  tmsK8[]     = {0xC0,0xD8,0xF0,0x07,0x1F,0x37,0x4F,0x66},
  tmsK9[]     = {0xC0,0xD4,0xE8,0xFC,0x10,0x25,0x39,0x4D},
  tmsK10[]    = {0xCD,0xDF,0xF1,0x04,0x16,0x20,0x3B,0x4D},
  chirp[]     = {0x00,0x2A,0xD4,0x32,0xB2,0x12,0x25,0x14,
                 0x02,0xE1,0xC5,0x02,0x5F,0x5A,0x05,0x0F,
                 0x26,0xFC,0xA5,0xA5,0xD6,0xDD,0xDC,0xFC,
                 0x25,0x2B,0x22,0x21,0x0F,0xFF,0xF8,0xEE,
                 0xED,0xEF,0xF7,0xF6,0xFA,0x00,0x03,0x02,0x01};

static const uint8_t PROGMEM
  tmsEnergy[] = {0x00,0x02,0x03,0x04,0x05,0x07,0x0A,0x0F,
                 0x14,0x20,0x29,0x39,0x51,0x72,0xA1,0xFF},
  tmsPeriod[] = {0x00,0x10,0x11,0x12,0x13,0x14,0x15,0x16,
                 0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,
                 0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26,
                 0x27,0x28,0x29,0x2A,0x2B,0x2D,0x2F,0x31,
                 0x33,0x35,0x36,0x39,0x3B,0x3D,0x3F,0x42,
                 0x45,0x47,0x49,0x4D,0x4F,0x51,0x55,0x57,
                 0x5C,0x5F,0x63,0x66,0x6A,0x6E,0x73,0x77,
                 0x7B,0x80,0x85,0x8A,0x8F,0x95,0x9A,0xA0};

static const uint8_t *ptrAddr;
static uint16_t       buf;
static uint8_t        bufBits;

static inline uint8_t rev(uint8_t a) { // Reverse bit sequence in 8-bit value
	a = ( a         >> 4) | ( a         << 4); // 76543210 -> 32107654
	a = ((a & 0xCC) >> 2) | ((a & 0x33) << 2); // 32107654 -> 10325476
	a = ((a & 0xAA) >> 1) | ((a & 0x55) << 1); // 10325476 -> 01234567
	return a;
}

static uint8_t getBits(uint8_t bits) {
	uint8_t value;
	if(bits > bufBits) {
		buf     |= rev(pgm_read_byte(ptrAddr)) << (8 - bufBits);
		bufBits += 8;
		ptrAddr++; // Don't post-inc in pgm_read_byte! Is a macro.
	}
	value    = buf >> (16 - bits);
	buf    <<= bits;
	bufBits -= bits;
	return value;
}

#define read8(base, bits)  pgm_read_byte(&base[getBits(bits)]);
#define read16(base, bits) pgm_read_word(&base[getBits(bits)]);

/**************************************************************************/
/*! 
    @brief  speak the data at the passed location
    @param addr pointer to the data
*/
/**************************************************************************/
void Adafruit_CPlay_Speaker::say(const uint8_t *addr) {

	int16_t  x0=0, x1=0, x2=0, x3=0, x4=0,
	         x5=0, x6=0, x7=0, x8=0, x9=0,
	         synthK1, synthK2, u0;
	uint16_t synthEnergy, synthRand = 1;
	int8_t   synthK3, synthK4, synthK5, synthK6,
	         synthK7, synthK8, synthK9, synthK10;
	uint8_t  periodCounter=0, nextPwm = 0x7F, synthPeriod;
	uint8_t  iCount = TICKS;
	uint32_t nowTime, prevTime=0;

	if(!started) begin();

	buf = bufBits = 0; // Reset 'ROM' reader (global stuff)
	ptrAddr = addr;

	for(;;) {
		while(((nowTime = micros()) - prevTime) < USEC);
#ifdef __AVR__
		OCR4A    = nextPwm;
#else
		analogWrite(A0, nextPwm);
#endif
		prevTime = nowTime;

		if(++iCount >= TICKS) {
			// Read speech data, processing the variable size frames
			uint8_t energy;
			if((energy = getBits(4)) == 0) {  // Rest frame
				synthEnergy = 0;
			} else if(energy == 0xF) {        // Stop frame; silence
#ifdef __AVR__
				TCCR4A = 0x7F;
#else
				analogWrite(A0, 0x7F);
#endif
				break;
			} else {
				synthEnergy    = pgm_read_byte(&tmsEnergy[energy]);
				uint8_t repeat = getBits(1);
				synthPeriod    = pgm_read_byte(&tmsPeriod[getBits(6)]);
				if(!repeat) { // A repeat frame uses last coefficients
					synthK1 = read16(tmsK1, 5); // All frames
					synthK2 = read16(tmsK2, 5); // use the first
					synthK3 = read8( tmsK3, 4); // 4 coefficients
					synthK4 = read8( tmsK4, 4);
					if(synthPeriod) {
						synthK5  = read8(tmsK5 , 4); // Voiced
						synthK6  = read8(tmsK6 , 4); // frames
						synthK7  = read8(tmsK7 , 4); // use
						synthK8  = read8(tmsK8 , 3); // six
						synthK9  = read8(tmsK9 , 3); // extra
						synthK10 = read8(tmsK10, 3); // coeffs
					}
				}
			}
			iCount = 0;
		}

		if(synthPeriod) { // Voiced source
			if(++periodCounter >= synthPeriod) periodCounter = 0;
			u0 = (periodCounter >= sizeof(chirp)) ? 0 :
			     (pgm_read_byte(&chirp[periodCounter]) *
			     (uint32_t)synthEnergy) >> 8;
		} else {          // Unvoiced source
			synthRand = (synthRand >> 1) ^ ((synthRand & 1) ? 0xB800 : 0);
			u0        = (synthRand & 1) ? synthEnergy : -synthEnergy;
		}
		u0     -=       ((synthK10 *          x9) +
				 (synthK9  *          x8)) >>  7;
		x9      = x8  + ((synthK9  *          u0 ) >>  7);
		u0     -=       ((synthK8  *          x7 ) >>  7);
		x8      = x7  + ((synthK8  *          u0 ) >>  7);
		u0     -=       ((synthK7  *          x6 ) >>  7);
		x7      = x6  + ((synthK7  *          u0 ) >>  7);
		u0     -=       ((synthK6  *          x5 ) >>  7);
		x6      = x5  + ((synthK6  *          u0 ) >>  7);
		u0     -=       ((synthK5  *          x4 ) >>  7);
		x5      = x4  + ((synthK5  *          u0 ) >>  7);
		u0     -=       ((synthK4  *          x3 ) >>  7);
		x4      = x3  + ((synthK4  *          u0 ) >>  7);
		u0     -=       ((synthK3  *          x2 ) >>  7);
		x3      = x2  + ((synthK3  *          u0 ) >>  7);
		u0     -=       ((synthK2  * (int32_t)x1 ) >> 15);
		x2      = x1  + ((synthK2  * (int32_t)u0 ) >> 15);
		u0     -=       ((synthK1  * (int32_t)x0 ) >> 15);
		x1      = x0  + ((synthK1  * (int32_t)u0 ) >> 15);

		if(     u0 >  511) u0 =  511; // Output clamp
		else if(u0 < -512) u0 = -512;

		x0      =  u0;
		nextPwm = (u0 >> 2) + 0x80;
	}
}
