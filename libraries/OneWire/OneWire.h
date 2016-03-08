#ifndef OneWire_h
#define OneWire_h

#include <inttypes.h>

#if ARDUINO >= 100 || ENERGIA >= 100
#include "Arduino.h"       // for delayMicroseconds, digitalPinToBitMask, etc
#else
#include "WProgram.h"      // for delayMicroseconds
#include "pins_arduino.h"  // for digitalPinToBitMask, etc
#endif

// You can exclude certain features from OneWire.  In theory, this
// might save some space.  In practice, the compiler automatically
// removes unused code (technically, the linker, using -fdata-sections
// and -ffunction-sections when compiling, and Wl,--gc-sections
// when linking), so most of these will not result in any code size
// reduction.  Well, unless you try to use the missing features
// and redesign your program to not need them!  ONEWIRE_CRC8_TABLE
// is the exception, because it selects a fast but large algorithm
// or a small but slow algorithm.

// you can exclude onewire_search by defining that to 0
#ifndef ONEWIRE_SEARCH
#define ONEWIRE_SEARCH 1
#endif

// You can exclude CRC checks altogether by defining this to 0
#ifndef ONEWIRE_CRC
#define ONEWIRE_CRC 1
#endif

// Select the table-lookup method of computing the 8-bit CRC
// by setting this to 1.  The lookup table enlarges code size by
// about 250 bytes.  It does NOT consume RAM (but did in very
// old versions of OneWire).  If you disable this, a slower
// but very compact algorithm is used.
#ifndef ONEWIRE_CRC8_TABLE
#define ONEWIRE_CRC8_TABLE 1
#endif

// You can allow 16-bit CRC checks by defining this to 1
// (Note that ONEWIRE_CRC must also be 1.)
#ifndef ONEWIRE_CRC16
#define ONEWIRE_CRC16 1
#endif

#define FALSE 0
#define TRUE  1

// Platform specific I/O definitions

#if defined(__AVR__)
#define PIN_TO_BASEREG(pin)             (portInputRegister(digitalPinToPort(pin)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define IO_REG_TYPE uint8_t
#define IO_REG_ASM asm("r30")
#define DIRECT_READ(base, mask)         (((*(base)) & (mask)) ? 1 : 0)
#define DIRECT_MODE_INPUT(base, mask)   ((*(base+1)) &= ~(mask))
#define DIRECT_MODE_OUTPUT(base, mask)  ((*(base+1)) |= (mask))
#define DIRECT_WRITE_LOW(base, mask)    ((*(base+2)) &= ~(mask))
#define DIRECT_WRITE_HIGH(base, mask)   ((*(base+2)) |= (mask))

#elif defined(__PIC32MX__)
#include <plib.h>  // is this necessary?
#define PIN_TO_BASEREG(pin)             (portModeRegister(digitalPinToPort(pin)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define IO_REG_TYPE uint32_t
#define IO_REG_ASM
#define DIRECT_READ(base, mask)         (((*(base+4)) & (mask)) ? 1 : 0)  //PORTX + 0x10
#define DIRECT_MODE_INPUT(base, mask)   ((*(base+2)) = (mask))            //TRISXSET + 0x08
#define DIRECT_MODE_OUTPUT(base, mask)  ((*(base+1)) = (mask))            //TRISXCLR + 0x04
#define DIRECT_WRITE_LOW(base, mask)    ((*(base+8+1)) = (mask))          //LATXCLR  + 0x24
#define DIRECT_WRITE_HIGH(base, mask)   ((*(base+8+2)) = (mask))          //LATXSET + 0x28

#elif defined(__MSP430G2452__) || defined(__MSP430G2553__)
// Original Launchpad
#define PIN_TO_BASEREG(pin)             (portInputRegister(digitalPinToPort(pin)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define IO_REG_TYPE uint8_t
#define IO_REG_ASM
#define DIRECT_READ(base, mask)         (((*(base)) & (mask)) ? 1 : 0)
#define DIRECT_MODE_INPUT(base, mask)   ((*(base+2)) &= ~(mask))
#define DIRECT_MODE_OUTPUT(base, mask)  ((*(base+2)) |= (mask))
#define DIRECT_WRITE_LOW(base, mask)    ((*(base+1)) &= ~(mask))
#define DIRECT_WRITE_HIGH(base, mask)   ((*(base+1)) |= (mask))

#elif defined (__MSP432P401R__) || defined(__MSP430F5529__) || defined(__MSP430FR5969__) || defined(__MSP430FR4133__) || defined(__MSP430FR6989__) || defined(__MSP430FR5739__)
// Newer Launchpads
#if defined(ti_sysbios_BIOS___VERS)
static const uint32_t GPIO_PORT_TO_BASE[] =
{   0x00,
    0x40004C00,
    0x40004C01,
    0x40004C20,
    0x40004C21,
    0x40004C40,
    0x40004C41,
    0x40004C60,
    0x40004C61,
    0x40004C80,
    0x40004C81,
    0x40004D20
};

#include <ti/drivers/gpio/GPIOMSP432.h>
#include <driverlib/gpio.h>
extern const GPIOMSP432_Config GPIOMSP432_config;
#define PIN_TO_PORT(pin) (GPIOMSP432_config.pinConfigs[pin] & 0xff00) >> 8
#define PIN_TO_BASEREG(pin) ((volatile uint32_t*)(GPIO_PORT_TO_BASE[(GPIOMSP432_config.pinConfigs[pin] & 0xff00) >> 8]))
#define PIN_TO_BITMASK(pin) (GPIOMSP432_config.pinConfigs[pin] & 0xff)
#define IO_REG_TYPE uint32_t
#define IO_REG_ASM
#define DIRECT_READ(base, mask)         (HWREG((uint32_t)base) & (mask) ? 1 : 0)
#define DIRECT_MODE_INPUT(base, mask)   (HWREG((uint32_t)base+4) &= ~(mask))
#define DIRECT_MODE_OUTPUT(base, mask)  (HWREG((uint32_t)base+4) |= (mask))
#define DIRECT_WRITE_LOW(base, mask)    (HWREG((uint32_t)base+2) &= ~(mask))
#define DIRECT_WRITE_HIGH(base, mask)   (HWREG((uint32_t)base+2) |= (mask))
#else
#define PIN_TO_BASEREG(pin)             (portInputRegister(digitalPinToPort(pin)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define IO_REG_TYPE uint8_t
#define IO_REG_ASM
#define DIRECT_READ(base, mask)         (((*(base)) & (mask)) ? 1 : 0)
#define DIRECT_MODE_INPUT(base, mask)   ((*(base+4)) &= ~(mask))
#define DIRECT_MODE_OUTPUT(base, mask)  ((*(base+4)) |= (mask))
#define DIRECT_WRITE_LOW(base, mask)    ((*(base+2)) &= ~(mask))
#define DIRECT_WRITE_HIGH(base, mask)   ((*(base+2)) |= (mask))
#endif

#elif defined(__LM4F120H5QR__) || defined(__TM4C1294NCPDT__)

// Launchpad Stellaris
#define PIN_TO_BASEREG(pin)             (portBASERegister(digitalPinToPort(pin)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define IO_REG_TYPE uint32_t
#define IO_REG_ASM
#define DIRECT_READ(base, mask)         (((*(base+0x0FF)) & (mask)) ? 1 : 0)
#define DIRECT_MODE_INPUT(base, mask)   ((*(base+0x100)) &= ~(mask))
#define DIRECT_MODE_OUTPUT(base, mask)  ((*(base+0x100)) |= (mask))
#define DIRECT_WRITE_LOW(base, mask)    ((*(base+0x0FF)) &= ~(mask))
#define DIRECT_WRITE_HIGH(base, mask)   ((*(base+0x0FF)) |= (mask))

// CC3200 Launchpad
#elif defined(__CC3200R1M1RGC__) || defined(__CC3200R1MXRGCR__)
#include <inc/hw_gpio.h>
#include <inc/hw_types.h>
// TI-RTOS
#if defined(ti_sysbios_BIOS___VERS)
#include <ti/drivers/gpio/GPIOCC3200.h>
extern const GPIOCC3200_Config GPIOCC3200_config;
#define PIN_TO_BASEREG(pin) ((volatile uint32_t*)(0x40004000 + ((GPIOCC3200_config.pinConfigs[pin] & 0xff00) << 4)))
#define PIN_TO_BITMASK(pin) (GPIOCC3200_config.pinConfigs[pin] & 0xff)
#else
#define PIN_TO_BASEREG(pin)             (portBASERegister(digitalPinToPort(pin)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#endif // TI-RTOS
#define IO_REG_TYPE uint32_t
#define IO_REG_ASM
#define DIRECT_READ(base, mask)         (HWREG((uint32_t)base + (GPIO_O_GPIO_DATA + (mask << 2))) & mask ? 1 : 0)
#define DIRECT_MODE_INPUT(base, mask)   ((HWREG((uint32_t)base + GPIO_O_GPIO_DIR)) &= ~(mask))
#define DIRECT_MODE_OUTPUT(base, mask)  ((HWREG((uint32_t)base + GPIO_O_GPIO_DIR)) |= (mask))
#define DIRECT_WRITE_LOW(base, mask)    ((HWREG((uint32_t)base + (GPIO_O_GPIO_DATA + (mask << 2)))) &= ~(mask))
#define DIRECT_WRITE_HIGH(base, mask)   ((HWREG((uint32_t)base + (GPIO_O_GPIO_DATA + (mask << 2)))) |= (mask))

#else
#error "Please define I/O register types here"
#endif


class OneWire
{
  private:
    IO_REG_TYPE bitmask;
    volatile IO_REG_TYPE *baseReg;

#if ONEWIRE_SEARCH
    // global search state
    unsigned char ROM_NO[8];
    uint8_t LastDiscrepancy;
    uint8_t LastFamilyDiscrepancy;
    uint8_t LastDeviceFlag;
#endif

  public:
    OneWire( uint8_t pin);

    // Perform a 1-Wire reset cycle. Returns 1 if a device responds
    // with a presence pulse.  Returns 0 if there is no device or the
    // bus is shorted or otherwise held low for more than 250uS
    uint8_t reset(void);

    // Issue a 1-Wire rom select command, you do the reset first.
    void select( uint8_t rom[8]);

    // Issue a 1-Wire rom skip command, to address all on bus.
    void skip(void);

    // Write a byte. If 'power' is one then the wire is held high at
    // the end for parasitically powered devices. You are responsible
    // for eventually depowering it by calling depower() or doing
    // another read or write.
    void write(uint8_t v, uint8_t power = 0);

    void write_bytes(const uint8_t *buf, uint16_t count, bool power = 0);

    // Read a byte.
    uint8_t read(void);

    void read_bytes(uint8_t *buf, uint16_t count);

    // Write a bit. The bus is always left powered at the end, see
    // note in write() about that.
    void write_bit(uint8_t v);

    // Read a bit.
    uint8_t read_bit(void);

    // Stop forcing power onto the bus. You only need to do this if
    // you used the 'power' flag to write() or used a write_bit() call
    // and aren't about to do another read or write. You would rather
    // not leave this powered if you don't have to, just in case
    // someone shorts your bus.
    void depower(void);

#if ONEWIRE_SEARCH
    // Clear the search state so that if will start from the beginning again.
    void reset_search();

    // Look for the next device. Returns 1 if a new address has been
    // returned. A zero might mean that the bus is shorted, there are
    // no devices, or you have already retrieved all of them.  It
    // might be a good idea to check the CRC to make sure you didn't
    // get garbage.  The order is deterministic. You will always get
    // the same devices in the same order.
    uint8_t search(uint8_t *newAddr);
#endif

#if ONEWIRE_CRC
    // Compute a Dallas Semiconductor 8 bit CRC, these are used in the
    // ROM and scratchpad registers.
    static uint8_t crc8( uint8_t *addr, uint8_t len);

#if ONEWIRE_CRC16
    // Compute the 1-Wire CRC16 and compare it against the received CRC.
    // Example usage (reading a DS2408):
    //    // Put everything in a buffer so we can compute the CRC easily.
    //    uint8_t buf[13];
    //    buf[0] = 0xF0;    // Read PIO Registers
    //    buf[1] = 0x88;    // LSB address
    //    buf[2] = 0x00;    // MSB address
    //    WriteBytes(net, buf, 3);    // Write 3 cmd bytes
    //    ReadBytes(net, buf+3, 10);  // Read 6 data bytes, 2 0xFF, 2 CRC16
    //    if (!CheckCRC16(buf, 11, &buf[11])) {
    //        // Handle error.
    //    }     
    //          
    // @param input - Array of bytes to checksum.
    // @param len - How many bytes to use.
    // @param inverted_crc - The two CRC16 bytes in the received data.
    //                       This should just point into the received data,
    //                       *not* at a 16-bit integer.
    // @return True, iff the CRC matches.
    static bool check_crc16(uint8_t* input, uint16_t len, uint8_t* inverted_crc);

    // Compute a Dallas Semiconductor 16 bit CRC.  This is required to check
    // the integrity of data received from many 1-Wire devices.  Note that the
    // CRC computed here is *not* what you'll get from the 1-Wire network,
    // for two reasons:
    //   1) The CRC is transmitted bitwise inverted.
    //   2) Depending on the endian-ness of your processor, the binary
    //      representation of the two-byte return value may have a different
    //      byte order than the two bytes you get from 1-Wire.
    // @param input - Array of bytes to checksum.
    // @param len - How many bytes to use.
    // @return The CRC16, as defined by Dallas Semiconductor.
    static uint16_t crc16(uint8_t* input, uint16_t len);
#endif
#endif
};

#endif
