#!/usr/bin/env python
import sys

'''
This script scans pins_energia.h file, finds the energia pins, then 
generates template declarations for 
    digital_pin_to_timer
    digital_pin_to_port
    digital_pin_to_bit_mask
    digital_pin_to_analog_in
They can then be pasted into pin_energia.h and modified.
'''

'''
from launchpad_129 pins_energia.h

// X8 and X9
//                     5v = 21  // X8_02
//                    GND = 22  // X8_04
static const uint8_t PE_0 = 23; // X8_06
static const uint8_t PE_1 = 24; // X8_08
'''

pins_energia = open("pins_energia.h","r").readlines()

pins = []
indeclares = False
for l in pins_energia:
    if l.count("energia pin definition begin") == 1:
        indeclares = True
        continue
    if l.count("energia pin definition end") == 1:
        break

    if indeclares:
        pins.append(l.strip())



digital_pin_to_timer     = "const uint8_t digital_pin_to_timer[]      = {\n    NOT_ON_TIMER,   // dummy \n"
digital_pin_to_port      = "const uint8_t digital_pin_to_port[]       = {\n    NOT_A_PIN,      // dummy \n"
digital_pin_to_bit_mask  = "const uint8_t digital_pin_to_bit_mask[]   = {\n    NOT_A_PIN,      // dummy \n"
digital_pin_to_analog_in = "const uint32_t digital_pin_to_analog_in[] = {\n    NOT_A_PIN,      // dummy \n"

energiapinlast = 0
for pin in pins:
    if len(pin) < 30:
        continue
    if pin[0:2] == "//": # this rigs commented out pins to have same number of fields
        pin = pin.replace("//                  ","static const uint8_t ")
    pinfields = ' '.join(pin.split()).split(" ")
    #print pinfields
    cpuio         = pinfields[3].strip()
    energiapin    = int(pinfields[5].replace(";",""))
    boardlabel    = pinfields[7].strip()

    if (energiapin - energiapinlast) != 1:
        print "energia pin", energiapin - 1, "is missing, please add it pins_engeria.h"
        sys.exit(1)
    energiapinlast = energiapin
    
    # digital_pin_to_timer
    digital_pin_to_timer += "    %-15s // %02d - %-10s %s\n"%("NOT_ON_TIMER,",energiapin,cpuio,boardlabel)

    # digital_pin_to_port
    if cpuio[0] == 'P':
        port = cpuio[0:2].upper()+","
    else:
        port = "NOT_A_PIN,"
    digital_pin_to_port += "    %-15s // %02d - %-10s %s\n"%(port,energiapin,cpuio,boardlabel)

    # digital_pin_to_bit_mask
    if cpuio.count('_') == 1:
        bit = "BV(%s),"%cpuio[-1]
    else:
        bit = "NOT_A_PIN,"
    digital_pin_to_bit_mask += "    %-15s // %02d - %-10s %s\n"%(bit,energiapin,cpuio,boardlabel)

    # digital_pin_to_analog_in
    digital_pin_to_analog_in += "    %-15s // %02d - %-10s %s\n"%("NOT_ON_ADC,",energiapin,cpuio,boardlabel)

digital_pin_to_timer += "};\n\n"
digital_pin_to_port += "};\n\n"
digital_pin_to_bit_mask += "};\n\n"
digital_pin_to_analog_in += "};\n\n"

print digital_pin_to_timer
print digital_pin_to_port
print digital_pin_to_bit_mask
print digital_pin_to_analog_in



