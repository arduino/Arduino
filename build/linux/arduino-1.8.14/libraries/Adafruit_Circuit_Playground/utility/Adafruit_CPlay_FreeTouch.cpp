/*
 * FreeTouch, a QTouch-compatible library - tested on ATSAMD21 only!
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Limor 'ladyada' Fried for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "Adafruit_CPlay_FreeTouch.h"

#if defined(__SAMD21G18A__)

Adafruit_CPlay_FreeTouch::Adafruit_CPlay_FreeTouch(int p, oversample_t f, series_resistor_t r, freq_mode_t fh) {
  pin = p;
  oversample = f;
  seriesres = r;
  freqhop = fh;
  compcap = 0x2000;
  intcap = 0x3F;
  yline = -1;
}

bool Adafruit_CPlay_FreeTouch::begin(void) {
  yline = getYLine();  // determine the Y0-15 #

  if (yline == -1)     // not all pins have Y line
    return false;

  setupClock();

  ptcInitSettings();

  enablePTC(false);

  enableWCOint(false);
  enableEOCint(false);

  // enable the sensor, only done once per line
  if (yline < 8) {
    sync_config();
    QTOUCH_PTC->YENABLEL.reg |= 1 << yline;
    sync_config();
  } else if (yline < 16) {
    QTOUCH_PTC->YENABLEH.reg |= 1 << (yline - 8);
  }

  enablePTC(true);

  return true;
}

void Adafruit_CPlay_FreeTouch::setupClock(void) {
  /* Setup and enable generic clock source for PTC module.
    struct system_gclk_chan_config gclk_chan_conf;
    system_gclk_chan_get_config_defaults(&gclk_chan_conf);
  */

  uint8_t channel = PTC_GCLK_ID;
  uint8_t source_generator = 1;

  // original line: system_gclk_chan_set_config(PTC_GCLK_ID, &gclk_chan_conf);
  uint32_t new_clkctrl_config = (channel << GCLK_CLKCTRL_ID_Pos);  // from gclk.c

  // original line: gclk_chan_conf.source_generator = GCLK_GENERATOR_1;
  /* Select the desired generic clock generator */
  new_clkctrl_config |= source_generator << GCLK_CLKCTRL_GEN_Pos;  // from gclk.c
  
  /* Disable generic clock channel */
  // original line: system_gclk_chan_disable(channel);
  noInterrupts();

  /* Select the requested generator channel */
  *((uint8_t*)&GCLK->CLKCTRL.reg) = channel;

  /* Sanity check WRTLOCK */
  //Assert(!GCLK->CLKCTRL.bit.WRTLOCK);

  /* Switch to known-working source so that the channel can be disabled */
  uint32_t prev_gen_id = GCLK->CLKCTRL.bit.GEN;
  GCLK->CLKCTRL.bit.GEN = 0;

  /* Disable the generic clock */
  GCLK->CLKCTRL.reg &= ~GCLK_CLKCTRL_CLKEN;
  while (GCLK->CLKCTRL.reg & GCLK_CLKCTRL_CLKEN) {
    /* Wait for clock to become disabled */
  }

  /* Restore previous configured clock generator */
  GCLK->CLKCTRL.bit.GEN = prev_gen_id;

  //system_interrupt_leave_critical_section();  
  interrupts();

  /* Write the new configuration */
  GCLK->CLKCTRL.reg = new_clkctrl_config;

  // original line: system_gclk_chan_enable(PTC_GCLK_ID);
  *((uint8_t*)&GCLK->CLKCTRL.reg) = channel;
  GCLK->CLKCTRL.reg |= GCLK_CLKCTRL_CLKEN;	/* Enable the generic clock */

    
  // original line: system_apb_clock_set_mask(SYSTEM_CLOCK_APB_APBC, PM_APBCMASK_PTC);
  PM->APBCMASK.reg |= PM_APBCMASK_PTC;
}


uint16_t Adafruit_CPlay_FreeTouch::measure(void) {
  uint16_t m;

  m = measureRaw();
  if (m == -1) return -1;

  // normalize the signal
  switch (oversample) {
    case OVERSAMPLE_1:   return m;
    case OVERSAMPLE_2:   return m/2;
    case OVERSAMPLE_4:   return m/4;
    case OVERSAMPLE_8:   return m/8;
    case OVERSAMPLE_16:  return m/16;
    case OVERSAMPLE_32:  return m/32;
    case OVERSAMPLE_64:  return m/64;
  }

  return -1; // shouldn't reach here but fail if we do!
}

uint16_t Adafruit_CPlay_FreeTouch::measureRaw(void) {
  if (yline == -1) 
    return -1;

  runInStandby(true);
  enablePTC(true);
  // check if in progress
  // set up NVIC if using INT (we're not)
  enableWCOint(false);
  clearWCOintFlag();
  clearEOCintFlag();
  // enable_eoc_int(); // not using irq (for now)

  // set up pin!
  //Serial.print("Y Line #"); Serial.println(yline);
  selectYLine();
  // set up sense resistor
  setSeriesResistor(seriesres);
  // set up prescalar
  setOversampling(oversample);
  // set up freq hopping
  setFreqHopping(freqhop, hops);
  // set up compensation cap + int (?) cap
  setCompCap(compcap);
  setIntCap(intcap);

  QTOUCH_PTC->BURSTMODE.reg = 0xA4;

  sync_config();


  return startPtcAcquire();
}

uint16_t Adafruit_CPlay_FreeTouch::startPtcAcquire(void) {
  ptcConfigIOpin();

  ptcAcquire();

  while (QTOUCH_PTC->CONVCONTROL.bit.CONVERT) {
    yield();
  }

  sync_config();
  uint16_t result = QTOUCH_PTC->RESULT.reg;

  return result;
}

/*********************************** low level config **/

void Adafruit_CPlay_FreeTouch::selectYLine(void) {

  sync_config();
  if (yline < 8) {
    QTOUCH_PTC->YSELECTL.reg = 1 << yline;
  } else {
    QTOUCH_PTC->YSELECTL.reg = 0;
  }

  if (yline > 7) {
    QTOUCH_PTC->YSELECTH.reg = 1 << (yline - 8);
  } else {
    QTOUCH_PTC->YSELECTH.reg = 0;
  }
  
  sync_config();
}

int Adafruit_CPlay_FreeTouch::getYLine(void) {
  int p = g_APinDescription[pin].ulPin;
  if (g_APinDescription[pin].ulPort == PORTA) {
    if ((p >= 2) && (p <= 7)) {
      return (p - 2);
    }
  }
  if (g_APinDescription[pin].ulPort == PORTB) {
    if ((p >= 0) && (p <= 9)) {
      return (p + 6);
    }
  }

  // not valid
  return -1;
}

void Adafruit_CPlay_FreeTouch::setCompCap(uint16_t cc) {
  compcap = cc & 0x3FFF;

  sync_config();
  QTOUCH_PTC->COMPCAPL.bit.VALUE = compcap & 0xFF;
  QTOUCH_PTC->COMPCAPH.bit.VALUE = (compcap>>8) & 0x3F;
  sync_config();
}

void Adafruit_CPlay_FreeTouch::setIntCap(uint8_t ic) {
  intcap = ic & 0x3F;

  sync_config();
  QTOUCH_PTC->INTCAP.bit.VALUE = intcap & 0x3F;
  sync_config();
}

void Adafruit_CPlay_FreeTouch::setOversampling(oversample_t lvl) {
  oversample = lvl; // back it up for later

  sync_config();
  QTOUCH_PTC->CONVCONTROL.bit.ADCACCUM = lvl;
  sync_config();
}

void Adafruit_CPlay_FreeTouch::setSeriesResistor(series_resistor_t res) {
  seriesres = res;

  sync_config();
  QTOUCH_PTC->SERRES.bit.RESISTOR = res;
  sync_config();
}

void Adafruit_CPlay_FreeTouch::setFreqHopping(freq_mode_t fh, freq_hop_t hs) {
  freqhop = fh;
  hops = hs;

  sync_config();
  if (fh == FREQ_MODE_NONE) {
    QTOUCH_PTC->FREQCONTROL.bit.FREQSPREADEN = 0;
    QTOUCH_PTC->FREQCONTROL.bit.SAMPLEDELAY = 0;
  } else {
    QTOUCH_PTC->FREQCONTROL.bit.FREQSPREADEN = 1;
    QTOUCH_PTC->FREQCONTROL.bit.SAMPLEDELAY = hops;
  }
  sync_config();
}


void Adafruit_CPlay_FreeTouch::ptcInitSettings(void) {
  ptcConfigIOpin();

  enablePTC(false);  

  QTOUCH_PTC->UNK4C04.reg &= 0xF7; //MEMORY[0x42004C04] &= 0xF7u;
  QTOUCH_PTC->UNK4C04.reg &= 0xFB; //MEMORY[0x42004C04] &= 0xFBu;
  QTOUCH_PTC->UNK4C04.reg &= 0xFC; //MEMORY[0x42004C04] &= 0xFCu;
  sync_config();
  QTOUCH_PTC->FREQCONTROL.reg &= 0x9F;       //MEMORY[0x42004C0C] &= 0x9Fu;
  sync_config();
  QTOUCH_PTC->FREQCONTROL.reg &= 0xEF;       //MEMORY[0x42004C0C] &= 0xEFu;
  sync_config();
  QTOUCH_PTC->FREQCONTROL.bit.SAMPLEDELAY = 0; //MEMORY[0x42004C0C] &= 0xF0u;
  QTOUCH_PTC->CONTROLC.bit.INIT = 1;         //MEMORY[0x42004C05] |= 1u;
  QTOUCH_PTC->CONTROLA.bit.RUNINSTANDBY = 1; //MEMORY[0x42004C00] |= 4u;
  sync_config();
  enablePTC(true);                           //MEMORY[0x42004C00] |= 2u;

}

void Adafruit_CPlay_FreeTouch::ptcConfigIOpin(void) {
  uint32_t ulpin = g_APinDescription[pin].ulPin;
  uint32_t ulport = g_APinDescription[pin].ulPort;
  
  PORT->Group[ulport].PINCFG[ulpin].reg = 0x3;  // pmuxen + input

  uint8_t curr_pmux = (PORT->Group[ulport].PMUX[ulpin/2].reg);

  if (ulpin & 1) {
    // pmuxodd
    curr_pmux &= PORT_PMUX_PMUXE(0xF); // keep the even mux data
    curr_pmux |= PORT_PMUX_PMUXO(0x1); // set to mux B
  } else {
    // pmuxeven
    curr_pmux &= PORT_PMUX_PMUXO(0xF); // keep the odd mux data
    curr_pmux |= PORT_PMUX_PMUXE(0x1); // set to mux B
  }
  PORT->Group[ulport].PMUX[ulpin/2].reg = curr_pmux;
}



void Adafruit_CPlay_FreeTouch::runInStandby(boolean en) {
  sync_config();
  if (en) {
    QTOUCH_PTC->CONTROLA.bit.RUNINSTANDBY = 1;
  } else {
    QTOUCH_PTC->CONTROLA.bit.RUNINSTANDBY = 0;
  }
  sync_config();
}


void Adafruit_CPlay_FreeTouch::enablePTC(boolean en) {
  sync_config();
  if (en) {
    QTOUCH_PTC->CONTROLA.bit.ENABLE = 1;
  } else {
    QTOUCH_PTC->CONTROLA.bit.ENABLE = 0;
  }
  sync_config();
}

void Adafruit_CPlay_FreeTouch::enableWCOint(boolean en) {
  sync_config();
  if (en) {
    QTOUCH_PTC->INTENABLE.bit.WCO = 1;
  } else {
    QTOUCH_PTC->INTDISABLE.bit.WCO = 1;
  } 
  sync_config();
}

void Adafruit_CPlay_FreeTouch::enableEOCint(boolean en) {
  sync_config();
  if (en) {
    QTOUCH_PTC->INTENABLE.bit.EOC = 1;
  } else {
    QTOUCH_PTC->INTDISABLE.bit.EOC = 1;
  } 
  sync_config();
}

void Adafruit_CPlay_FreeTouch::clearWCOintFlag(void) {
  sync_config();
  QTOUCH_PTC->INTFLAGS.bit.WCO = 1;
  sync_config();
}

void Adafruit_CPlay_FreeTouch::clearEOCintFlag(void) {
  sync_config();
  QTOUCH_PTC->INTFLAGS.bit.EOC = 1;
  sync_config();
}


void Adafruit_CPlay_FreeTouch::ptcAcquire(void) {
  sync_config();
  QTOUCH_PTC->CONVCONTROL.bit.CONVERT = 1;
  sync_config();
}


void Adafruit_CPlay_FreeTouch::sync_config(void) {
  while (QTOUCH_PTC->CONTROLB.bit.SYNCFLAG) ;
}



/**************************** DEBUGGING ASSIST *************************/
void Adafruit_CPlay_FreeTouch::snapshotRegsAndPrint(uint32_t base, uint8_t numregs) {
  volatile uint32_t addr = base;
  uint8_t datas[255];

  digitalWrite(LED_BUILTIN, HIGH);
  for (uint8_t i=0; i<numregs; i++) {
    datas[i] = *(uint8_t *)(addr+i);
  }
  digitalWrite(LED_BUILTIN, LOW);
  printPTCregs(base, datas, numregs);
  
  for (uint8_t i=0; i<numregs; i++) {
  //  Serial.print("$"); Serial.print(addr+i, HEX); Serial.print("\t0x");
  //  printHex(datas[i]); Serial.println();
  }
  
}

// Print a hex with leading zero
void Adafruit_CPlay_FreeTouch::printHex(uint8_t h, boolean newline) {
  if (h < 0x10) Serial.print("0");
  Serial.print(h, HEX);
  if (newline)  Serial.println();
}

void Adafruit_CPlay_FreeTouch::printPTCregs(uint32_t base, uint8_t *regs, uint8_t num) {
  Serial.println("--------------------------------------------------------");
  for (uint8_t i=0; i<num; i++) {
      switch (i + base) {
        case 0x41004430:  Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" PMUX0:\t\t0x"); printHex(regs[i], true); break; 
        case 0x41004431:  Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" PMUX1:\t\t0x"); printHex(regs[i], true); break; 
        case 0x41004432:  Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" PMUX2:\t\t0x"); printHex(regs[i], true); break; 
        case 0x41004433:  Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" PMUX3:\t\t0x"); printHex(regs[i], true); break; 

        case 0x41004440:  Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" PCFG0:\t\t0x"); printHex(regs[i], true); break; 
        case 0x41004441:  Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" PCFG1:\t\t0x"); printHex(regs[i], true); break; 
        case 0x41004442:  Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" PCFG2:\t\t0x"); printHex(regs[i], true); break; 
        case 0x41004443:  Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" PCFG3:\t\t0x"); printHex(regs[i], true); break; 
        case 0x41004444:  Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" PCFG4:\t\t0x"); printHex(regs[i], true); break; 


        case 0x42004C00: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Control A:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C01: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Sync:     \t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C04: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Prescaler:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C05: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Init:     \t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C08: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Disable Irq:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C09: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Enable Irq:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C0A: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Flags:     \t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C0C: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Freq Cntl:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C0D: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Conv Cntl:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C10: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Y Select1:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C11: Serial.print("0x"); Serial.print(i+0x42004C00, HEX);
          Serial.print(" Y Select2:\t\t0x"); printHex(regs[i], true); break; 
/*
        case 0x42004C12: Serial.print("0x"); Serial.print(i+0x42004C00, HEX);
          Serial.print(" X Select1:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C13: Serial.print("0x"); Serial.print(i+0x42004C00, HEX);
          Serial.print(" X Select2:\t\t0x"); printHex(regs[i], true); break; 
*/
        case 0x42004C14: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Y Enable1:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C15: Serial.print("0x"); Serial.print(i+0x42004C00, HEX);
          Serial.print(" Y Enable2:\t\t0x"); printHex(regs[i], true); break; 
/*
        case 0x42004C16: Serial.print("0x"); Serial.print(i+0x42004C00, HEX);
          Serial.print(" X Enable1:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C17: Serial.print("0x"); Serial.print(i+0x42004C00, HEX);
          Serial.print(" X Enable2:\t\t0x"); printHex(regs[i], true); break; 
*/
        case 0x42004C18: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Compcap L:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C19: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Compcap H:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C1A: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Intcap:   \t\t0x"); printHex(regs[i], true); break;
        case 0x42004C1B: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Sense res:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C1C: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Result L:\t\t0x"); printHex(regs[i], true); break; 
        case 0x42004C1D: Serial.print("0x"); Serial.print(i+base, HEX);
          Serial.print(" Result H:\t\t0x"); printHex(regs[i], true); break; 
        
       }
  }
}
#endif
