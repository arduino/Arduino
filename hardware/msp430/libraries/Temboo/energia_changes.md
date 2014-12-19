Temboo Energia Updates
======================

Three main changes were necessary to run the Temboo TI Library via Energia on a TI Tiva C LaunchPad. These changes are documented below.

###1. Adding c_str()

The first update is the addition of the `c_str()` method to the standard String class. This is literally adding a single line to the `public` section of the `String` class declaration in the `WString.h` file:

  ```
  const char* c_str() const {return buffer;}
  ```

This method returns a pointer to the character array holding the current contents of the String. This allows the Temboo client to efficiently access the String contents without having to make a copy of it. Arduino added this method to their version of the String class in version 1.0.5 of the Arduino IDE. If TI is planning to merge recent changes from the original Arduino libraries, they may well get this change in that process. This would have to be added to all the Energia core libraries (Tiva C, MSP430, and any other devices that should support Temboo.) 

###2. Adding #define INADDR_NONE

The second update is the introduction of `#define INADDR_NONE`. This is defined for ethernet interfaces, but not for the CC3000 WiFi shield.

***INADDR_NONE is created in the IPAddress header file***

###3. Adding PROGMEM macros + functions
The third update is related to defining some missing PROGMEM-related macros and functions. TI apparently already has some facility for dealing with PROGMEM data in their libraries, but it's incomplete. Specifically, we had to define the following macros:

```
#define PSTR
#define PROGMEM 
#define pgm_read_byte(x) (*x)
#define pgm_read_dword(x) (*x)
#define strcat_P strcat
#define strlen_P strlen
```

We also had to comment out any `#include <avr/pgmspace.h>` directives.
