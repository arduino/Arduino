// Adafruit Arduino Zero / Feather M0 I2S audio library.
// Author: Tony DiCola & Limor "ladyada" Fried
//
// The MIT License (MIT)
//
// Copyright (c) 2016 Adafruit Industries
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#include "Adafruit_ZeroPDM.h"

#if defined(ARDUINO_ARCH_SAMD)

// Define macros for debug output that optimize out when debug mode is disabled.
#ifdef DEBUG
  #define DEBUG_PRINT(...) DEBUG_PRINTER.print(__VA_ARGS__)
  #define DEBUG_PRINTLN(...) DEBUG_PRINTER.println(__VA_ARGS__)
#else
  #define DEBUG_PRINT(...)
  #define DEBUG_PRINTLN(...)
#endif


Adafruit_ZeroPDM::Adafruit_ZeroPDM(int clockpin, int datapin, uint8_t gclk):
  _gclk(gclk), _clk(clockpin), _data(datapin)  {

}

bool Adafruit_ZeroPDM::begin(void) {
  // check the pins are valid!
  _clk_pin = _clk_mux = _data_pin = _data_mux = 0;

  // Clock pin, can only be one of 3 options
  uint32_t clockport = g_APinDescription[_clk].ulPort;
  uint32_t clockpin = g_APinDescription[_clk].ulPin;
  if ((clockport == 0) && (clockpin == 10)) {
    // PA10
    _i2sclock = I2S_CLOCK_UNIT_0;
    _clk_pin = PIN_PA10G_I2S_SCK0;
    _clk_mux = MUX_PA10G_I2S_SCK0;
  } else if ((clockport == 1) && (clockpin == 10)) {
    // PB11
    _i2sclock = I2S_CLOCK_UNIT_1;
    _clk_pin = PIN_PB11G_I2S_SCK1;
    _clk_mux = MUX_PB11G_I2S_SCK1;
  } else if ((clockport == 0) && (clockpin == 20)) {
    // PA20
    _i2sclock = I2S_CLOCK_UNIT_0;
    _clk_pin = PIN_PA20G_I2S_SCK0;
    _clk_mux = MUX_PA20G_I2S_SCK0;
  } else {
    DEBUG_PRINTLN("Clock isnt on a valid pin");
    return false;
  }

  // Data pin, can only be one of 3 options
  uint32_t datapin = g_APinDescription[_data].ulPin;
  uint32_t dataport = g_APinDescription[_data].ulPort;
  if ((dataport == 0) && (datapin == 7)) {
    // PA07
    _i2sserializer = I2S_SERIALIZER_0;
    _data_pin = PIN_PA07G_I2S_SD0;
    _data_mux = MUX_PA07G_I2S_SD0;
  } else if ((dataport == 0) && (datapin == 8)) {
    // PA08
    _i2sserializer = I2S_SERIALIZER_1;
    _data_pin = PIN_PA08G_I2S_SD1;
    _data_mux = MUX_PA08G_I2S_SD1;
  } else if ((dataport == 0) && (datapin == 19)) {
    // PA19
    _i2sserializer = I2S_SERIALIZER_0;
    _data_pin = PIN_PA19G_I2S_SD0;
    _data_mux = MUX_PA19G_I2S_SD0;
  } else {
    DEBUG_PRINTLN("Data isnt on a valid pin");
    return false;
  }

  // Initialize I2S module from the ASF.
  // replace "status_code res = i2s_init(&_i2s_instance, I2S);
  //  if (res != STATUS_OK) {
  //  DEBUG_PRINT("i2s_init failed with result: "); DEBUG_PRINTLN(res);
  //  return false;
  // }" with:

  /* Enable the user interface clock in the PM */
  //system_apb_clock_set_mask(SYSTEM_CLOCK_APB_APBC, PM_APBCMASK_I2S);
  PM->APBCMASK.reg |= PM_APBCMASK_I2S;

  /* Status check */
  uint32_t ctrla = I2S->CTRLA.reg;
  if (ctrla & I2S_CTRLA_ENABLE) {
    if (ctrla & (I2S_CTRLA_SEREN1 |
		 I2S_CTRLA_SEREN0 | I2S_CTRLA_CKEN1 | I2S_CTRLA_CKEN0)) {
      //return STATUS_BUSY;
      return false;
    } else {
      //return STATUS_ERR_DENIED;
      return false;
    }
  }

  /* Initialize module */
  _hw = I2S;

  return true;
}

void Adafruit_ZeroPDM::end(void) {
  while (_hw->SYNCBUSY.reg & I2S_SYNCBUSY_ENABLE); // Sync wait
  _hw->CTRLA.reg &= ~I2S_SYNCBUSY_ENABLE;
}

bool Adafruit_ZeroPDM::configure(uint32_t sampleRateHz, boolean stereo) {
  // Convert bit per sample int into explicit ASF values.

  // Disable I2S while it is being reconfigured to prevent unexpected output.
  end();


  /******************************* Set the GCLK generator config and enable it. *************/
  {
    /* Cache new register configurations to minimize sync requirements. */
    uint32_t new_genctrl_config = (_gclk << GCLK_GENCTRL_ID_Pos);
    uint32_t new_gendiv_config  = (_gclk << GCLK_GENDIV_ID_Pos);
    
    /* Select the requested source clock for the generator */
    // Set the clock generator to use the 48mhz main CPU clock and divide it down
    // to the SCK frequency.
    new_genctrl_config |= GCLK_SOURCE_DFLL48M  << GCLK_GENCTRL_SRC_Pos;
    uint32_t division_factor = F_CPU / (sampleRateHz*16); // 16 clocks for 16 stereo bits
    
    /* Set division factor */
    if (division_factor > 1) {
      /* Check if division is a power of two */
      if (((division_factor & (division_factor - 1)) == 0)) {
	/* Determine the index of the highest bit set to get the
	 * division factor that must be loaded into the division
	 * register */
	
	uint32_t div2_count = 0;
	
	uint32_t mask;
	for (mask = (1UL << 1); mask < division_factor;
	     mask <<= 1) {
	  div2_count++;
	}
	
	/* Set binary divider power of 2 division factor */
	new_gendiv_config  |= div2_count << GCLK_GENDIV_DIV_Pos;
	new_genctrl_config |= GCLK_GENCTRL_DIVSEL;
      } else {
	/* Set integer division factor */
	
	new_gendiv_config  |=
	  (division_factor) << GCLK_GENDIV_DIV_Pos;
	
	/* Enable non-binary division with increased duty cycle accuracy */
	new_genctrl_config |= GCLK_GENCTRL_IDC;
      }  
    }
    
    noInterrupts();  // cpu_irq_enter_critical();

    while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY);  // Wait for synchronization
    *((uint8_t*)&GCLK->GENDIV.reg) = _gclk;   /* Select the correct generator */

    while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY);  // Wait for synchronization
    GCLK->GENDIV.reg  = new_gendiv_config;    /* Write the new generator configuration */
    
    while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY);  // Wait for synchronization
    GCLK->GENCTRL.reg = new_genctrl_config | (GCLK->GENCTRL.reg & GCLK_GENCTRL_GENEN);

    // Replace "system_gclk_gen_enable(_gclk);" with:

    while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY);  // Wait for synchronization
    *((uint8_t*)&GCLK->GENCTRL.reg) = _gclk;          /* Select the requested generator */

    while (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY);  // Wait for synchronization
    GCLK->GENCTRL.reg |= GCLK_GENCTRL_GENEN;          /* Enable generator */
    
    interrupts();  // cpu_irq_leave_critical();
  }
  
  /******************************* Configure I2S clock *************/
  {
    /* Status check */
    /* Busy ? */
    if (_hw->SYNCBUSY.reg & (I2S_SYNCBUSY_CKEN0 << _i2sclock)) {
      return false;           //return STATUS_BUSY;
    }
    /* Already enabled ? */
    if (_hw->CTRLA.reg & (I2S_CTRLA_CKEN0 << _i2sclock)) {
     
      return false;           //return STATUS_ERR_DENIED;
    }
    
    /***************************** Initialize Clock Unit *************/
    uint32_t clkctrl = 
      // I2S_CLKCTRL_MCKOUTINV | // mck out not inverted
      // I2S_CLKCTRL_SCKOUTINV | // sck out not inverted
      // I2S_CLKCTRL_FSOUTINV |  // fs not inverted
      // I2S_CLKCTRL_MCKEN |    // Disable MCK output
      // I2S_CLKCTRL_MCKSEL |   // Disable MCK output
      // I2S_CLKCTRL_SCKSEL |   // SCK source is GCLK
      // I2S_CLKCTRL_FSINV |    // do not invert frame sync
      // I2S_CLKCTRL_FSSEL |    // Configure FS generation from SCK clock.
      // I2S_CLKCTRL_BITDELAY |  // No bit delay (PDM)
      0;

    clkctrl |= I2S_CLKCTRL_MCKOUTDIV(0);
    clkctrl |= I2S_CLKCTRL_MCKDIV(0);
    clkctrl |= I2S_CLKCTRL_NBSLOTS(1);  // STEREO is '1' (subtract one from #)
    clkctrl |= I2S_CLKCTRL_FSWIDTH(I2S_FRAME_SYNC_WIDTH_SLOT);  // Frame Sync (FS) Pulse is 1 Slot width
    if (stereo) {
      clkctrl |= I2S_CLKCTRL_SLOTSIZE(I2S_SLOT_SIZE_16_BIT);
    } else {
      clkctrl |= I2S_CLKCTRL_SLOTSIZE(I2S_SLOT_SIZE_32_BIT);
    }
    
    /* Write clock unit configurations */
    _hw->CLKCTRL[_i2sclock].reg = clkctrl;
    
    /* Select general clock source */
    const uint8_t i2s_gclk_ids[2] = {I2S_GCLK_ID_0, I2S_GCLK_ID_1};

    /* Cache the new config to reduce sync requirements */
    uint32_t new_clkctrl_config = (i2s_gclk_ids[_i2sclock] << GCLK_CLKCTRL_ID_Pos);

    /* Select the desired generic clock generator */
    new_clkctrl_config |= _gclk << GCLK_CLKCTRL_GEN_Pos;

    /* Disable generic clock channel */
    noInterrupts();

    /* Select the requested generator channel */
    *((uint8_t*)&GCLK->CLKCTRL.reg) = i2s_gclk_ids[_i2sclock];

    /* Switch to known-working source so that the channel can be disabled */
    uint32_t prev_gen_id = GCLK->CLKCTRL.bit.GEN;
    GCLK->CLKCTRL.bit.GEN = 0;

    /* Disable the generic clock */
    GCLK->CLKCTRL.reg &= ~GCLK_CLKCTRL_CLKEN;
    while (GCLK->CLKCTRL.reg & GCLK_CLKCTRL_CLKEN); /* Wait for clock to become disabled */

    /* Restore previous configured clock generator */
    GCLK->CLKCTRL.bit.GEN = prev_gen_id;

    /* Write the new configuration */
    GCLK->CLKCTRL.reg = new_clkctrl_config;
    
    // enable it
    *((uint8_t*)&GCLK->CLKCTRL.reg) = i2s_gclk_ids[_i2sclock];   /* Select the requested generator channel */
    GCLK->CLKCTRL.reg |= GCLK_CLKCTRL_CLKEN;                     /* Enable the generic clock */

    interrupts();

    /* Initialize pins */
    pinPeripheral(_clk, (EPioType)_clk_mux);
  }

  /***************************** Configure I2S serializer *************/
  {
    /* Status check */
    /* Busy ? */
    while (_hw->SYNCBUSY.reg & ((I2S_SYNCBUSY_SEREN0 | I2S_SYNCBUSY_DATA0) << _i2sserializer)) {
      //return STATUS_BUSY;
      return false;
    }
    
    /* Already enabled ? */
    if (_hw->CTRLA.reg & (I2S_CTRLA_CKEN0 << _i2sserializer)) {
      // return STATUS_ERR_DENIED;
      return false;
    }
    
    /* Initialize Serializer */
    uint32_t serctrl =
      // I2S_SERCTRL_RXLOOP |    // Dont use loopback mode
      // I2S_SERCTRL_DMA    |    // Single DMA channel for all I2S channels
      // I2S_SERCTRL_MONO   |    // Dont use MONO mode
      // I2S_SERCTRL_SLOTDIS7 |  // Dont have any slot disabling
      // I2S_SERCTRL_SLOTDIS6 |
      // I2S_SERCTRL_SLOTDIS5 |
      // I2S_SERCTRL_SLOTDIS4 |
      // I2S_SERCTRL_SLOTDIS3 |
      // I2S_SERCTRL_SLOTDIS2 |
      // I2S_SERCTRL_SLOTDIS1 |
      // I2S_SERCTRL_SLOTDIS0 |
      I2S_SERCTRL_BITREV   |  // Do not transfer LSB first (MSB first!)
      // I2S_SERCTRL_WORDADJ  |  // Data NOT left in word
      I2S_SERCTRL_SLOTADJ     |  // Data is left in slot
      // I2S_SERCTRL_TXSAME   |  // Pad 0 on underrun
      0;
    
    // Configure clock unit to use with serializer, and set serializer as an output.
    if (_i2sclock < 2) {
      serctrl |= (_i2sclock ? I2S_SERCTRL_CLKSEL : 0);
    } else {
      return false;       //return STATUS_ERR_INVALID_ARG;
    }
    if (stereo) {
      serctrl |= I2S_SERCTRL_SERMODE(I2S_SERIALIZER_PDM2); //Serializer is used to receive PDM data on each clock edge
    } else {
      serctrl |= I2S_SERCTRL_SERMODE(I2S_SERIALIZER_RECEIVE); // act like I2S
    }

    // Configure serializer data size.
    serctrl |=  I2S_SERCTRL_DATASIZE(I2S_DATA_SIZE_32BIT);  // anything other than 32 bits is ridiculous to manage, force this to be 32
    
    serctrl |=  I2S_SERCTRL_TXDEFAULT(I2S_LINE_DEFAULT_0) | /** Output default value is 0 */
                I2S_SERCTRL_EXTEND(I2S_DATA_PADDING_0);     /** Padding 0 in case of under-run */
   
    /* Write Serializer configuration */
    _hw->SERCTRL[_i2sserializer].reg = serctrl;
    
    /* Initialize pins */
    // Enable SD pin.  See Adafruit_ZeroI2S.h for default pin value.
    pinPeripheral(_data, (EPioType)_data_mux);
  }

  /***************************** Enable everything configured above *************/

  // Replace "i2s_enable(&_i2s_instance);" with:
  while (_hw->SYNCBUSY.reg & I2S_SYNCBUSY_ENABLE);  // Sync wait
  _hw->CTRLA.reg |= I2S_SYNCBUSY_ENABLE;
  
  // Replace "i2s_clock_unit_enable(&_i2s_instance, _i2sclock);" with:
  uint32_t cken_bit = I2S_CTRLA_CKEN0 << _i2sclock;
  while (_hw->SYNCBUSY.reg & cken_bit); // Sync wait
  _hw->CTRLA.reg |= cken_bit;
  
  // Replace "i2s_serializer_enable(&_i2s_instance, _i2sserializer);" with:
  uint32_t seren_bit = I2S_CTRLA_SEREN0 << _i2sserializer;
  while (_hw->SYNCBUSY.reg & seren_bit); // Sync wait
  _hw->CTRLA.reg |= seren_bit;
  
  return true;
}

uint32_t Adafruit_ZeroPDM::read(void) {
  // Read the sample from the I2S data register.
  // This will wait for the I2S hardware to be ready to send the byte.
  //return i2s_serializer_read_wait(&_i2s_instance, _i2sserializer);

  // replace i2s_serializer_read_wait with deASF'd code:
  {
    uint32_t sync_bit, ready_bit;
    uint32_t data;
    ready_bit = I2S_INTFLAG_RXRDY0 << _i2sserializer;
    while (!(_hw->INTFLAG.reg & ready_bit)) {
      /* Wait until ready to transmit */
    }
    sync_bit = I2S_SYNCBUSY_DATA0 << _i2sserializer;
    while (_hw->SYNCBUSY.reg & sync_bit) {
      /* Wait sync */
    }
    /* Read data */
    data = _hw->DATA[_i2sserializer].reg;
    _hw->INTFLAG.reg = ready_bit;
    return data;
  }
}

#endif
