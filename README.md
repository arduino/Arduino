<p align="center">
    <img src="http://content.arduino.cc/brand/arduino-color.svg" width="50%" />
</p>

# Arduino IDE

Arduino is an open-source physical computing platform based on a simple I/O board and a development environment that implements the Processing/Wiring language. Arduino can be used to develop stand-alone interactive objects or can be connected to software on your computer (e.g., Flash, Processing, and MaxMSP). The boards can be assembled by hand or purchased preassembled; the open-source IDE can be downloaded for free at [Arduino Software](https://www.arduino.cc/en/Main/Software).

---

**Important Notice**: This repository contains the legacy Arduino IDE 1.x, which is no longer in active development. For the latest features and updates, please visit the [Arduino IDE 2.x](https://github.com/arduino/arduino-ide) repository. If you encounter issues related to the newer IDE, please report them there.

---

![Github](https://img.shields.io/github/v/release/arduino/Arduino)

## More Info At
- [Our website](https://www.arduino.cc/)
- [The forums](https://forum.arduino.cc/)
- Follow us on [Twitter](https://twitter.com/arduino)
- Like us on [Facebook](https://www.facebook.com/official.arduino)

## Bug Reports and Technical Discussions
- To report a *bug* in the software or to request *a simple enhancement*, go to [Github Issues](https://github.com/arduino/Arduino/issues).
- More complex requests and technical discussions should go on the [Arduino Developers mailing list](https://groups.google.com/a/arduino.cc/forum/#!forum/developers).
- If you're interested in modifying or extending the Arduino software, we strongly suggest discussing your ideas on the Developers mailing list *before* starting to work on them. This way, you can coordinate with the Arduino Team and others, giving your work a higher chance of being integrated into the official release.

### Security
If you think you found a vulnerability or other security-related bug in this project, please read our [security policy](https://github.com/arduino/Arduino/security/policy) and report the bug to our Security Team 🛡️. Thank you!

e-mail contact: [security@arduino.cc](mailto:security@arduino.cc)

## Installation
Detailed instructions for installation on popular operating systems can be found at:
- [Linux](https://www.arduino.cc/en/Guide/Linux) (see also the [Arduino playground](https://playground.arduino.cc/Learning/Linux))
- [macOS](https://www.arduino.cc/en/Guide/macOS)
- [Windows](https://www.arduino.cc/en/Guide/Windows)

## Contents of This Repository
This repository contains just the code for the Arduino IDE itself. Originally, it also contained the AVR and SAM Arduino core and libraries (i.e., the code that is compiled as part of a sketch and runs on the actual Arduino device), but those have been moved into their own repositories. They are still automatically downloaded as part of the build process and included in built releases, though.

The repositories for these extra parts can be found here:
- Non-core specific Libraries are listed under: [Arduino Libraries](https://github.com/arduino-libraries/).
- The AVR core can be found at: [ArduinoCore-avr](https://github.com/arduino/ArduinoCore-avr).
- Other cores are not included by default but can be installed through the board manager. Their repositories can also be found under [Arduino GitHub organization](https://github.com/arduino/).

## Building and Testing
Instructions for building the IDE and running unit tests can be found on the wiki:
- [Building Arduino](https://github.com/arduino/Arduino/wiki/Building-Arduino)
- [Testing Arduino](https://github.com/arduino/Arduino/wiki/Testing-Arduino)

## Credits
Arduino is an open-source project, supported by many. The Arduino team is composed of Massimo Banzi, David Cuartielles, Tom Igoe, and David A. Mellis.

Arduino uses:
- [GNU avr-gcc toolchain](https://gcc.gnu.org/wiki/avr-gcc)
- [GCC ARM Embedded toolchain](https://launchpad.net/gcc-arm-embedded)
- [avr-libc](https://www.nongnu.org/avr-libc/)
- [avrdude](https://www.nongnu.org/avrdude/)
- [bossac](http://www.shumatech.com/web/products/bossa)
- [openOCD](http://openocd.org/)
- Code from [Processing](https://www.processing.org) and [Wiring](http://wiring.org.co).

Icon and about image designed by [ToDo](https://www.todo.to.it/).
